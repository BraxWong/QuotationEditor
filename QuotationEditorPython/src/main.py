from PySide6 import QtWidgets
import sys
import MainMenu
import XlsxWriter
import Entry
import OrderDetails

if __name__ == "__main__":
    entry = Entry.Entry("addOn", "product1", "model1", "12", "13", "14", "approveNum", "12", "130000", 13.21, 1)
    entry2 = Entry.Entry("addOn2", "product2", "model2", "13", "13", "14", "approveNum2", "8", "30000", 10.21, 0)
    entry3 = Entry.Entry("addOn3", "product3", "model3", "14", "13", "14", "approveNum3", "9", "20000", 11.21, 0)
    entry4 = Entry.Entry("addOn4", "product4", "model4", "15", "13", "14", "approveNum4", "10", "10000", 12.21, 1)
    entry5 = Entry.Entry("addOn5", "product5", "model5", "15", "13", "14", "approveNum5", "10", "10000", 12.21, 1)


    order = OrderDetails.OrderDetails("Brax", "Flat C", "Nicole", "1234", "Nobody", "testing.xlsx", 91001426, "TX-1000")
    xlsxWriter = XlsxWriter.XlsxWriter([entry, entry2, entry3, entry4, entry5, entry5, entry5, entry5], order)
    xlsxWriter.writeToXlsx()
    # app = QtWidgets.QApplication([])
    #
    # widget = MainMenu.MainMenu()
    # widget.resize(800, 600)
    # widget.show()
    #
    # sys.exit(app.exec())
