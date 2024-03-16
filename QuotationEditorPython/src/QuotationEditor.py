from PySide6 import QtWidgets, QtCore
import sys

class QuotationEditor(QtWidgets.QWidget):
    def __init__(self):
        super().__init__()
        self.addNewItemLabel = QtWidgets.QLabel("添加新物品")

        self.quantityLabel = QtWidgets.QLabel("數量")
        self.quantityLineEdit = QtWidgets.QLineEdit()
        self.quantityLayout = QtWidgets.QHBoxLayout()
        self.quantityLayout.addWidget(self.quantityLabel)
        self.quantityLayout.addWidget(self.quantityLineEdit)
        self.quantityLayout.setSpacing(40)

        self.pricePerUnitLabel = QtWidgets.QLabel("單價")
        self.pricePerUnitLineEdit = QtWidgets.QLineEdit()
        self.pricePerUnitLayout = QtWidgets.QHBoxLayout()
        self.pricePerUnitLayout.addWidget(self.pricePerUnitLabel)
        self.pricePerUnitLayout.addWidget(self.pricePerUnitLineEdit)
        self.pricePerUnitLayout.setSpacing(40)

        self.MJHRLabel = QtWidgets.QLabel("兆焦耳") 
        self.MJHRLineEdit = QtWidgets.QLineEdit()
        self.MJHRLayout = QtWidgets.QHBoxLayout()
        self.MJHRLayout.addWidget(self.MJHRLabel)
        self.MJHRLayout.addWidget(self.MJHRLineEdit)
        self.MJHRLayout.setSpacing(27)

        self.modelLabel = QtWidgets.QLabel("模型")
        self.modelLineEdit = QtWidgets.QLineEdit()
        self.modelLayout = QtWidgets.QHBoxLayout()
        self.modelLayout.addWidget(self.modelLabel)
        self.modelLayout.addWidget(self.modelLineEdit)
        self.modelLayout.setSpacing(40)

        self.productLabel = QtWidgets.QLabel("產品名稱")
        self.productLineEdit = QtWidgets.QLineEdit()
        self.productCheckButton = QtWidgets.QPushButton("查對")
        self.productCheckButton.clicked.connect(self.verifyItem)
        self.productLayout = QtWidgets.QHBoxLayout()
        self.productLayout.addWidget(self.productLabel)
        self.productLayout.addWidget(self.productLineEdit)
        self.productLayout.addWidget(self.productCheckButton)

        self.approvalNumLabel = QtWidgets.QLabel("批核編號") 
        self.approvalNumLineEdit = QtWidgets.QLineEdit()
        self.approvalNumLayout = QtWidgets.QHBoxLayout()
        self.approvalNumLayout.addWidget(self.approvalNumLabel)
        self.approvalNumLayout.addWidget(self.approvalNumLineEdit)
        self.approvalNumLayout.setSpacing(14)

        self.dimensionXLabel = QtWidgets.QLabel("X")
        self.dimensionXLineEdit = QtWidgets.QLineEdit()
        self.dimensionYLabel = QtWidgets.QLabel("Y")
        self.dimensionYLineEdit = QtWidgets.QLineEdit()
        self.diensionZLabel = QtWidgets.QLabel("Z")
        self.dimensionZLineEdit = QtWidgets.QLineEdit()
        self.dimensionsLayout = QtWidgets.QHBoxLayout()
        self.dimensionsLayout.addWidget(self.dimensionXLabel)
        self.dimensionsLayout.addWidget(self.dimensionXLineEdit)
        self.dimensionsLayout.addWidget(self.dimensionYLabel)
        self.dimensionsLayout.addWidget(self.dimensionYLineEdit)
        self.dimensionsLayout.addWidget(self.diensionZLabel)
        self.dimensionsLayout.addWidget(self.dimensionZLineEdit)

        self.discountLabel = QtWidgets.QLabel("香港中華煤氣有限公司(尊貴客戶)優惠")
        self.discountLineEdit = QtWidgets.QLineEdit()
        self.discountLayout = QtWidgets.QHBoxLayout()
        self.discountLayout.addWidget(self.discountLabel)
        self.discountLayout.addWidget(self.discountLineEdit)

        self.preOwnedLabel = QtWidgets.QLabel("客戶現有爐具")
        self.preOwnedComboBox = QtWidgets.QComboBox()
        self.preOwnedComboBox.addItems(["Yes", "No"])
        self.providedLabel = QtWidgets.QLabel("煤氣公司提供")
        self.providedComboBox = QtWidgets.QComboBox()
        self.providedComboBox.addItems(["Yes", "No"])
        self.providedLayout = QtWidgets.QHBoxLayout()
        self.providedLayout.addWidget(self.providedLabel)
        self.providedLayout.addWidget(self.providedComboBox)
        self.providedLayout.addWidget(self.preOwnedLabel)
        self.providedLayout.addWidget(self.preOwnedComboBox)

        self.additionalLabel = QtWidgets.QLabel("額外增加")
        self.additionalLineEdit = QtWidgets.QLineEdit()
        self.additionalLayout = QtWidgets.QHBoxLayout()
        self.additionalLayout.addWidget(self.additionalLabel)
        self.additionalLayout.addWidget(self.additionalLineEdit)
        self.additionalLayout.setSpacing(14)

        self.submitButton = QtWidgets.QPushButton("完成")
        self.submitButton.clicked.connect(self.writeToFile)

        self.mainLayout = QtWidgets.QVBoxLayout()
        self.mainLayout.addWidget(self.addNewItemLabel, 0, QtCore.Qt.AlignTop | QtCore.Qt.AlignHCenter)
        self.mainLayout.addLayout(self.productLayout)
        self.mainLayout.addLayout(self.quantityLayout)
        self.mainLayout.addLayout(self.pricePerUnitLayout)
        self.mainLayout.addLayout(self.MJHRLayout)
        self.mainLayout.addLayout(self.modelLayout)
        self.mainLayout.addLayout(self.additionalLayout)
        self.mainLayout.addLayout(self.approvalNumLayout)
        self.mainLayout.addLayout(self.dimensionsLayout)
        self.mainLayout.addLayout(self.providedLayout)
        self.mainLayout.addLayout(self.discountLayout)
        self.mainLayout.addWidget(self.submitButton, 0, QtCore.Qt.AlignBottom | QtCore.Qt.AlignHCenter)

        self.setLayout(self.mainLayout)

    def writeToFile(self):
        sys.exit()        

#       ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
#       ┃                                                                 ┃
#       ┃ TODO: Create a File class that handles files related operations ┃
#       ┃                                                                 ┃
#       ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯


    def verifyItem(self):
        sys.exit()
#                        ╭━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╮
#                        ┃                               ┃
#                        ┃ TODO: Create a Database class ┃
#                        ┃                               ┃
#                        ╰━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╯

