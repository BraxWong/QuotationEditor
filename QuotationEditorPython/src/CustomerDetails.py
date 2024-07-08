from PySide6 import QtWidgets
from QuotationEditor import QuotationEditor
import utils
import OrderDetails
import XlsxWriter
import Database

class CustomerDetails(QtWidgets.QWidget):
    def __init__(self) :
        super().__init__()

        self.database = Database.Database()

        self.entryList = [] 
        self.fileNameLabel = QtWidgets.QLabel("檔案名稱")
        self.fileNameLineEdit = QtWidgets.QLineEdit()
        self.fileNameLayout = QtWidgets.QHBoxLayout()
        utils.widgetConfig(self.fileNameLabel, self.fileNameLineEdit, self.fileNameLayout)

        self.customerNameLabel = QtWidgets.QLabel("客戶名稱")
        self.customerNameLineEdit = QtWidgets.QLineEdit()
        self.customerCheckButton = QtWidgets.QPushButton("查對")
        self.customerCheckButton.clicked.connect(self.verifyItem)
        self.customerNameLayout = QtWidgets.QHBoxLayout()
        self.customerNameLayout.addWidget(self.customerNameLabel)
        self.customerNameLayout.addWidget(self.customerNameLineEdit)
        self.customerNameLayout.addWidget(self.customerCheckButton)

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
        self.quotationEditor.editorClosed.connect(self.appendEntryToList)
        self.quotationEditor.resize(800, 600)
        self.quotationEditor.show()
        
    def appendEntryToList(self, entry):
        self.entryList.append(entry)

    def writeToFile(self):
        if self.fileNameLineEdit.text() != "":
            self.orderDetails = OrderDetails.OrderDetails(self.customerNameLineEdit.text(), self.customerAddrLineEdit.text(), self.supervisorLineEdit.text(), self.quotationIDLineEdit.text(), self.staffLineEdit.text(), self.fileNameLineEdit.text(), int(self.customerTelLineEdit.text()), self.customerIDLineEdit.text())
            directory = self.openFilePicker()
            if directory != "":
                self.xlsxWriter = XlsxWriter.XlsxWriter(self.entryList, self.orderDetails, directory)
                self.xlsxWriter.writeToXlsx()
                if not self.database.customerInDatabase(self.orderDetails):
                    self.database.addCustomerToDatabase(self.orderDetails)
                super().close()
                    
    def openFilePicker(self):
        dialog = QtWidgets.QFileDialog(self)
        dialog.setFileMode(QtWidgets.QFileDialog.Directory)
        dialog.setOption(QtWidgets.QFileDialog.ShowDirsOnly, True)
        if dialog.exec():
            return dialog.selectedFiles()[0] + "/"
        return ""
    
    def verifyItem(self):
        customer = self.database.getCustomerByCustomerName(self.customerNameLineEdit.text())
        if customer != None:
            self.customerAddrLineEdit.setText(customer.customerAddr)
            self.customerIDLineEdit.setText(customer.customerID)
            self.customerTelLineEdit.setText(str(customer.customerTel))
            self.supervisorLineEdit.setText(customer.supervisor)