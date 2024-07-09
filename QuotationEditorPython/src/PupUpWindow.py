from PySide6 import QtWidgets, QtCore

class PopUpWindow(QtWidgets.QWidget):

    def __init__(self, popTitle, popUpMessages):
        super().__init__()

        self.popUpTitleLabel = QtWidgets.QLabel(popTitle)
        self.acknowledgeButton = QtWidgets.QPushButton("OK")
        self.acknowledgeButton.clicked.connect(self.closePopUpWindow)

        self.layout = QtWidgets.QVBoxLayout()
        self.layout.addWidget(self.popUpTitleLabel, 0, QtCore.Qt.AlignTop | QtCore.Qt.AlignHCenter)
        for popUpMessage in popUpMessages:
            self.popUpMessage = QtWidgets.QLabel(popUpMessage)
            self.layout.addWidget(self.popUpMessage, 0, QtCore.Qt.AlignTop | QtCore.Qt.AlignHCenter)
        self.layout.addWidget(self.acknowledgeButton)
        self.setLayout(self.layout)

        self.setFixedSize(QtCore.QSize(400,200))

        
    def closePopUpWindow(self):
        super().close()

