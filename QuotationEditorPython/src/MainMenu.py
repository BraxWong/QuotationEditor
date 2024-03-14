from PySide6 import QtCore, QtWidgets
import sys

class MainMenu(QtWidgets.QWidget):
    def __init__(self):
        super().__init__()
        self.newQuotationButton = QtWidgets.QPushButton("新報價單")
        self.exitApplicationButton = QtWidgets.QPushButton("關閉程序")
        self.exitApplicationButton.clicked.connect(self.exitApplication)
        self.modifyDatabaseButton = QtWidgets.QPushButton("改數據庫")
        self.text = QtWidgets.QLabel("中天廚房設備有限公司報價單編輯器",alignment=QtCore.Qt.AlignCenter)
        self.text.setStyleSheet(''' font-size: 30px; ''')

        self.layout = QtWidgets.QVBoxLayout(self)
        self.layout.addWidget(self.text)
        self.layout.addWidget(self.newQuotationButton)
        self.layout.addWidget(self.modifyDatabaseButton)
        self.layout.addWidget(self.exitApplicationButton)

    @QtCore.Slot()
    def exitApplication(self):
        sys.exit()

