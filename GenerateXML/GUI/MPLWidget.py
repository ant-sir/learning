'''
Created on 2015年6月19日

@author: zyl
'''
import matplotlib
matplotlib.use('Qt5Agg')
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg as FigureCanvas
from matplotlib.figure import Figure


class MatPlotLibWidget(FigureCanvas):
    '''
    def widget
    '''


    def __init__(self, parent=None):
        '''
        Constructor
        '''
        fig = Figure()
        self.axes = fig.add_subplot(111)
        # We want the axes cleared every time plot() is called
        self.axes.hold(False)
        super(MatPlotLibWidget, self).__init__(fig)
        