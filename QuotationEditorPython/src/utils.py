from PySide6 import QtWidgets
from typing import List


def widgetConfig(label: QtWidgets.QLabel,  lineEdit: QtWidgets.QLineEdit, layout: QtWidgets.QHBoxLayout) -> QtWidgets.QHBoxLayout:
    layout.addWidget(label)
    layout.addWidget(lineEdit)
    return layout

def addLayoutsToMainLayout(mainLayout: QtWidgets.QVBoxLayout, layouts: List[QtWidgets.QHBoxLayout]) -> QtWidgets.QVBoxLayout:
    for layout in layouts:
        mainLayout.addLayout(layout)
    return mainLayout
