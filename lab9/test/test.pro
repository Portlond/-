QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

CONFIG(debug, debug|release){
    LIBS += -L../Objects/debug -lObjects
}
CONFIG(release, debug|release){
    LIBS += -L../Objects/release -lObjects
}

SOURCES +=  tst_test_objects.cpp
