from PySide6 import QtWidgets, QtCore
from QuotationEditor import QuotationEditor
import utils
import Entry

class CustomerDetails(QtWidgets.QWidget):
    def __init__(self) :
        super().__init__()

        self.entryList = [] 
        self.fileNameLabel = QtWidgets.QLabel("檔案名稱")
        self.fileNameLineEdit = QtWidgets.QLineEdit()
        self.fileNameLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.fileNameLabel, self.fileNameLineEdit, self.fileNameLayout)

        self.customerNameLabel = QtWidgets.QLabel("客戶名稱")
        self.customerNameLineEdit = QtWidgets.QLineEdit()
        self.customerNameLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.customerNameLabel, self.customerNameLineEdit, self.customerNameLayout)

        self.customerAddrLabel = QtWidgets.QLabel("客戶地址")
        self.customerAddrLineEdit = QtWidgets.QLineEdit()
        self.customerAddrLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.customerAddrLabel, self.customerAddrLineEdit, self.customerAddrLayout)

        self.supervisorLabel = QtWidgets.QLabel("負責人")
        self.supervisorLineEdit = QtWidgets.QLineEdit()
        self.supervisorLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.supervisorLabel, self.supervisorLineEdit, self.supervisorLayout)

        self.customerTelLabel = QtWidgets.QLabel("電話")
        self.customerTelLineEdit = QtWidgets.QLineEdit()
        self.customerTelLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.customerTelLabel, self.customerTelLineEdit, self.customerTelLayout)

        self.customerIDLabel = QtWidgets.QLabel("客戶編號")
        self.customerIDLineEdit = QtWidgets.QLineEdit()
        self.customerIDLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.customerIDLabel, self.customerIDLineEdit, self.customerIDLayout)

        self.quotationIDLabel = QtWidgets.QLabel("報價單號碼")
        self.quotationIDLineEdit = QtWidgets.QLineEdit()
        self.quotationIDLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.quotationIDLabel, self.quotationIDLineEdit, self.quotationIDLayout)

        self.staffLabel = QtWidgets.QLabel("職員")
        self.staffLineEdit = QtWidgets.QLineEdit()
        self.staffLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.staffLabel, self.staffLineEdit, self.staffLayout)

        self.addNewItemButton = QtWidgets.QPushButton("添加項目")
        self.addNewItemButton.clicked.connect(self.openQuotationEditor)
        self.submitButton = QtWidgets.QPushButton("完成")
        self.submitButton.clicked.connect(self.writeToFile)
        self.buttonLayout = QtWidgets.QHBoxLayout()
        self.buttonLayout.addWidget(self.addNewItemButton)
        self.buttonLayout.addWidget(self.submitButton)

        self.mainLayout = QtWidgets.QVBoxLayout()
        utils.addLayoutsToMainLayout(self.mainLayout, [self.fileNameLayout, self.customerNameLayout, self.customerAddrLayout, self.supervisorLayout, self.customerTelLayout, self.customerIDLayout, self.quotationIDLayout, self.staffLayout, self.buttonLayout])
        self.setLayout(self.mainLayout)

    def openQuotationEditor(self):
        self.quotationEditor = QuotationEditor()
        self.quotationEditor.editorClosed.connect(self.testing)
        self.quotationEditor.resize(800, 600)
        self.quotationEditor.show()
        
    def testing(self, entry):
        self.entryList.append(entry)

    def writeToFile(self):
        print("Will write to file soon")
