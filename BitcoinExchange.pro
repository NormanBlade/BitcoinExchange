TEMPLATE = app
TARGET = BitcoinExchange

QT = core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    model.cpp \
    view.cpp \
    controller.cpp

HEADERS += \
    model.h \
    view.h \
    controller.h
