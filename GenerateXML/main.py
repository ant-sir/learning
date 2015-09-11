'''
Created on 2015年6月16日

@author: zyl
'''
from PyQt5 import QtWidgets as QW
from GUI.MainDialog import MainDialog

if __name__ == '__main__':
    import sys
    app = QW.QApplication(sys.argv)
    dlg = MainDialog()
    dlg.show()
    sys.exit(app.exec_())
