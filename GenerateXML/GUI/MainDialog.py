# -*- coding: utf-8 -*-

"""
Module implementing MainDialog.
"""
import wave
import numpy as np

from PyQt5.QtCore import pyqtSlot, QModelIndex
from PyQt5.QtWidgets import QDialog, QFileDialog, QFileSystemModel, QMessageBox
from .Ui_MainDialog import Ui_Dialog
from os.path import isdir
from GUI.MPLWidget import MatPlotLibWidget


class MainDialog(QDialog, Ui_Dialog):
    """
    Class documentation goes here.
    """
    def __init__(self, parent=None):
        """
        Constructor
        
        @param parent reference to the parent widget (QWidget)
        """
        super(MainDialog, self).__init__(parent)
        self.setupUi(self)
        self.mode = QFileSystemModel()
        self.treeView.setModel(self.mode)
        self.mplw = MatPlotLibWidget(self)
        self.verticalLayout.addWidget(self.mplw)
        self.dir = ""
        self.checkBox_WithEOS_stat = 0
    
    @pyqtSlot()
    def on_pushButton_AddPath_clicked(self):
        """
        Slot documentation goes here.
        """
        self.dir = QFileDialog.getExistingDirectory(self)
        self.treeView.setRootIndex(self.mode.setRootPath(self.dir))
        
    
    @pyqtSlot()
    def on_pushButton_Generate_clicked(self):
        """
        Slot documentation goes here.
        """
        if not self.dir:
            QMessageBox.about(self, "infromation", "请添加Wav目录！")
            return
        save_file = QFileDialog.getSaveFileName(self)
        if not save_file[0].strip():
            return
        from Lib.Generate import Generate
        generate = Generate(self.dir, self.checkBox_WithEOS_stat)
        generate.GenerateCase()
        generate.Save(save_file[0])
        QMessageBox.about(self, "infromation", "生成成功！")
    
    @pyqtSlot(QModelIndex)
    def on_treeView_clicked(self, index):
        """
        Slot documentation goes here.
        """
        name = self.mode.filePath(index)
        if isdir(name):
            return
        
        f = wave.open(name, 'rb')
        params = f.getparams()
        nchannels, sampwidth, framerate, nframes = params[:4]
        #print(nchannels, sampwidth, framerate, nframes)
        str_data = f.readframes(nframes)
        f.close()

        if not sampwidth == 2:
            QMessageBox.warning(self, "waring", "需要16位位宽文件！")
            return
        wave_data = np.fromstring(str_data, dtype=np.short)
        if not nchannels == 1:
            QMessageBox.warning(self, "waring", "需要单声道文件！")
            return
        time = np.arange(0, nframes) * (1.0 / framerate)
        self.mplw.axes.plot(time, wave_data)
        self.mplw.draw()
    
    @pyqtSlot(int)
    def on_checkBox_WithEOS_stateChanged(self, p0):
        """
        Slot documentation goes here.
        """
        self.checkBox_WithEOS_stat = p0
