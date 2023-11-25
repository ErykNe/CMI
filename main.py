from PySide6.QtCore import Qt
from PySide6.QtWidgets import QApplication, QHBoxLayout, QSlider, QWidget, QPushButton, QTextEdit
from Window import Window

import sys


app = QApplication(sys.argv)

window = Window(900, 500)
window.createMenuBar()
window.createToolBar()




layout = QHBoxLayout()


window.setLayout(layout)

window.show()
if(window.isVisible() == False):
    app.quit()
     
app.exec()


# I ended on 1:41:04 - https://www.youtube.com/watch?v=Z1N9JzNax2k