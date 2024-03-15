from PySide6 import QtWidgets, QtCore, QtWidgets

class QuotationEditor(QtWidgets.QWidget):
    def __init__(self):
        super().__init__()
        self.addNewItemLabel = QtWidgets.QLabel("添加新物品",alignment=QtCore.Qt.AlignCenter)
        self.quantityLabel = QtWidgets.QLabel("數量")
        self.pricePerUnitLabel = QtWidgets.QLabel("單價")
        self.MJHRLabel = QtWidgets.QLabel("兆焦耳") 
        self.modelLabel = QtWidgets.QLabel("模型")
        self.approvalNumLabel = QtWidgets.QLabel("批核編號") 
        self.layout = QtWidgets.QVBoxLayout(self)
        self.layout.addWidget(self.addNewItemLabel)
        self.layout.addWidget(self.quantityLabel)
        self.layout.addWidget(self.pricePerUnitLabel)
        self.layout.addWidget(self.MJHRLabel)
        self.layout.addWidget(self.modelLabel)
        self.layout.addWidget(self.approvalNumLabel)

