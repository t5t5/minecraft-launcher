include(../ml-include.pri)

QT     += core gui widgets

CONFIG += c++11

TARGET = minecraft-launcher
TEMPLATE = app

MOC_DIR = ./tmp/moc
OBJECTS_DIR = ./tmp/obj
RCC_DIR = ./tmp/rcc
UI_DIR = ./tmp/ui
DESTDIR = $$ML_BUILD_DIR

#LIBS += -L$$QPE_CORE_BUILD_DIR -lqpecore

RC_ICONS = icons/grass.ico

SOURCES += \
    datamodel.cpp \
    main.cpp \
    launcher.cpp

HEADERS += \
    datamodel.h \
    datamodel_p.h \
    launcher.h \
    launcher_p.h

FORMS += \
    launcher.ui

RESOURCES += \
    resources.qrc

OTHER_FILES = \
    icons\grass.ico
