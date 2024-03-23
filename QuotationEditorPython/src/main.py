from PySide6 import QtWidgets
import sys
import MainMenu
import XlsxWriter
import Entry
import OrderDetails

if __name__ == "__main__":
    entry = Entry.Entry("addOn", "product1", "model1", "12", "13", "14", "approveNum", "12", "130000", 13.21, 1)
    order = OrderDetails.OrderDetails("Brax", "Flat C", "Nicole", "1234", "Nobody", "testing.xlsx", 91001426, "TX-1000")
    xlsxWriter = XlsxWriter.XlsxWriter([entry], order)
    xlsxWriter.writeToXlsx()
    # app = QtWidgets.QApplication([])
    #
    # widget = MainMenu.MainMenu()
    # widget.resize(800, 600)
    # widget.show()
    #
    # sys.exit(app.exec())
