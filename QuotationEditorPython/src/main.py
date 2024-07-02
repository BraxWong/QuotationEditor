from PySide6 import QtWidgets
import sys
import MainMenu

if __name__ == "__main__":
    app = QtWidgets.QApplication([])

    widget = MainMenu.MainMenu()
    widget.resize(800, 600)
    widget.show()

    sys.exit(app.exec())
