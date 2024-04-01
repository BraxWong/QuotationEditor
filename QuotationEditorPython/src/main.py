from PySide6 import QtWidgets
import sys
import MainMenu
import CustomerDetails
import Entry
import XlsxWriter
import OrderDetails

if __name__ == "__main__":
    # oDetails = OrderDetails.OrderDetails("name", "addr", "Joel", "12", "Nicole", "tt1", 91001426, "1sx-sa")
    # entry = Entry.Entry("sda","p1","dsa","100","1990","100","a1",10,12,13.21,"No","No","No")
    # xWriter = XlsxWriter.XlsxWriter([entry, entry, entry, entry, entry, entry, entry, entry], oDetails)
    # xWriter.writeToXlsx()
    app = QtWidgets.QApplication([])

    widget = MainMenu.MainMenu()
    widget.resize(800, 600)
    widget.show()

    sys.exit(app.exec())
