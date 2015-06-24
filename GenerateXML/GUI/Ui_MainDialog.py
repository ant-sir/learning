# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/zyl/workspace/GenerateXML/GUI/MainDialog.ui'
#
# Created by: PyQt5 UI code generator 5.4.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(847, 562)
        Dialog.setSizeGripEnabled(True)
        self.treeView = QtWidgets.QTreeView(Dialog)
        self.treeView.setGeometry(QtCore.QRect(0, 0, 561, 561))
        self.treeView.setObjectName("treeView")
        self.gridLayoutWidget = QtWidgets.QWidget(Dialog)
        self.gridLayoutWidget.setGeometry(QtCore.QRect(570, 10, 271, 141))
        self.gridLayoutWidget.setObjectName("gridLayoutWidget")
        self.gridLayout = QtWidgets.QGridLayout(self.gridLayoutWidget)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.pushButton_AddPath = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.pushButton_AddPath.setObjectName("pushButton_AddPath")
        self.gridLayout.addWidget(self.pushButton_AddPath, 0, 0, 1, 1)
        self.pushButton_Close = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.pushButton_Close.setObjectName("pushButton_Close")
        self.gridLayout.addWidget(self.pushButton_Close, 2, 0, 1, 1)
        self.pushButton_Generate = QtWidgets.QPushButton(self.gridLayoutWidget)
        self.pushButton_Generate.setObjectName("pushButton_Generate")
        self.gridLayout.addWidget(self.pushButton_Generate, 0, 1, 1, 1)
        self.checkBox_WithEOS = QtWidgets.QCheckBox(self.gridLayoutWidget)
        self.checkBox_WithEOS.setObjectName("checkBox_WithEOS")
        self.gridLayout.addWidget(self.checkBox_WithEOS, 2, 1, 1, 1)
        self.verticalLayoutWidget = QtWidgets.QWidget(Dialog)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(570, 380, 271, 181))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")

        self.retranslateUi(Dialog)
        self.pushButton_Close.clicked.connect(Dialog.close)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "Dialog"))
        self.pushButton_AddPath.setText(_translate("Dialog", "AddPath"))
        self.pushButton_Close.setText(_translate("Dialog", "Close"))
        self.pushButton_Generate.setText(_translate("Dialog", "Generate"))
        self.checkBox_WithEOS.setText(_translate("Dialog", "WithEOS"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Dialog = QtWidgets.QDialog()
    ui = Ui_Dialog()
    ui.setupUi(Dialog)
    Dialog.show()
    sys.exit(app.exec_())

