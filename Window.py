from PySide6.QtCore import Qt
from PySide6.QtGui import QAction, QPalette, QColor
from PySide6.QtWidgets import QMainWindow, QToolBar, QPushButton

import sys
import random
import time

class Window(QMainWindow):
    def __init__(self, x: int, y:int):
        super().__init__()
        self.setWindowTitle("A new window") 
        self.setMinimumSize(x, y)
        self.setMaximumSize(x, y)
        self.setWindowFlag(Qt.Window)
        self.setWindowFlag(Qt.WindowMaximizeButtonHint)
        self.setWindowFlag(Qt.WindowMinimizeButtonHint)
        self.setWindowFlag(Qt.WindowCloseButtonHint)

    def createMenuBar(self):
        menuBar = self.menuBar()
        fileMenu = menuBar.addMenu("&File")

        saveAction = fileMenu.addAction("Save")
        quitAction = fileMenu.addAction("Quit")
        
        saveAction.triggered.connect(self.savingProgram)
        quitAction.triggered.connect(self.shuttingProgram)

        editMenu = menuBar.addMenu("&Edit")

        copyAction = editMenu.addAction("Copy")
        cutAction = editMenu.addAction("Cut")
        pasteAction = editMenu.addAction("Paste")
        undoAction = editMenu.addAction("Undo")
        redoAction = editMenu.addAction("Redo")

        windowMenu = menuBar.addMenu("&Window")
        resizeAction = windowMenu.addAction("Resize")

        resizeAction.triggered.connect(self.resizeProgram)

        settingsMenu = menuBar.addMenu("&Settings")
        helpMenu = menuBar.addMenu("&Help")

    def shuttingProgram(self):
        self.close()

    def savingProgram(self):
        self.saveState()
        print("Saved")
    def resizeProgram(self):
        if(self.maximumSize == self.minimumSize):
            self.resizeAction.setText("Resize")

        self.setMaximumSize(16777215, 16777215)
        
        print("Now you can resize your window by dragging it's edges!")

    def createToolBar(self):
        toolBar = QToolBar("My toolbar")
        self.addToolBar(Qt.BottomToolBarArea, toolBar)
        action1 = QAction("Click this!", self)
        action1.setStatusTip("You will be delighted if you press this!!!")
        button = QPushButton("Click Me!")
        toolBar.addWidget(button)
        button.clicked.connect(self.action2Event)
        action1.triggered.connect(self.action1Event)
        toolBar.addAction(action1)

    def action1Event(self):
        self.windowList = []
        while(True):
            x = random.randint(0, 1920)
            y = random.randint(0, 1080)
            window = Window(900, 500)
            window.createMenuBar()
            window.createToolBar()
            self.windowList.append(window)
            window.show()
            window.move(x, y)

    def action2Event(self):        
        self.statusBar().showMessage("Hihihiha!", 2000)



       



