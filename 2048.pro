QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \

HEADERS += \


INCLUDEPATH += $$PWD/main/
INCLUDEPATH += $$PWD/model/
INCLUDEPATH += $$PWD/controller/
INCLUDEPATH += $$PWD/view/

include($$PWD/view/view.pri)
include($$PWD/main/main.pri)
include($$PWD/model/model.pri)
include($$PWD/controller/controller.pri)

FORMS += \
    game2048.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
