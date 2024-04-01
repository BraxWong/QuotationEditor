from PySide6 import QtWidgets
import utils

class database(QtWidgets.QWidget):
    
    def __init__(self):
        super().__init__()

        self.addNewItemLabel = QtWidgets.QLabel("添加新物品")

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
        self.productLayout = QtWidgets.QHBoxLayout()
        self.productLayout.addWidget(self.productLabel)
        self.productLayout.addWidget(self.productLineEdit)

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

        self.submitButton = QtWidgets.QPushButton("完成")
        self.submitButton.clicked.connect(self.checkItemInDatabase)
        self.mainLayout = QtWidgets.QVBoxLayout()
        self.mainLayout.addWidget(self.addNewItemLabel, 0, QtCore.Qt.AlignTop | QtCore.Qt.AlignHCenter)
        utils.addLayoutsToMainLayout(self.mainLayout, [self.productLayout, self.pricePerUnitLayout, self.MJHRLayout, self.modelLayout, self.approvalNumLayout, self.dimensionsLayout])
        self.mainLayout.addWidget(self.submitButton, 0, QtCore.Qt.AlignBottom | QtCore.Qt.AlignHCenter)

        self.setLayout(self.mainLayout)



    def checkItemInDatabase(self):
        return True

    
