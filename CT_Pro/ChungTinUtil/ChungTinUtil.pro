QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buttonactions.cpp \
    customerDetails.cpp \
    entry.cpp \
    helpfunctions.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    quotationeditor.cpp

HEADERS += \
    buttonactions.h \
    customerDetails.h \
    entry.h \
    helpfunctions.h \
    mainmenu.h \
    mainwindow.h \
    quotationeditor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
