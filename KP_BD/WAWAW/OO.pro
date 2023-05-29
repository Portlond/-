QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -L ../qq/debug -lqq\

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buy.cpp \
    main.cpp \
    redak_buy.cpp \
    redak_sklad.cpp \
    redak_sold.cpp \
    redak_tovar.cpp \
    save_buy.cpp \
    save_sklad.cpp \
    save_sold.cpp \
    save_tovar.cpp \
    sklad.cpp \
    sold.cpp \
    sprpolzovat.cpp \
    tovar.cpp \
    vibor.cpp

HEADERS += \
    buy.h \
    redak_buy.h \
    redak_sklad.h \
    redak_sold.h \
    redak_tovar.h \
    save_buy.h \
    save_sklad.h \
    save_sold.h \
    save_tovar.h \
    sklad.h \
    sold.h \
    sprpolzovat.h \
    tovar.h \
    vibor.h

FORMS += \
    buy.ui \
    redak_buy.ui \
    redak_sklad.ui \
    redak_sold.ui \
    redak_tovar.ui \
    save_buy.ui \
    save_sklad.ui \
    save_sold.ui \
    save_tovar.ui \
    sklad.ui \
    sold.ui \
    sprpolzovat.ui \
    tovar.ui \
    vibor.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    kartinki.qrc



