#-------------------------------------------------
#
# Project created by QtCreator 2019-10-19T22:27:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SCHOOL_MANAGEMENT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        homepage.cpp \
        new_student.cpp \
        search_student.cpp \
        student_records.cpp \
        main.cpp \
        login.cpp

HEADERS += \
    homepage.h \
         login.h \
    new_student.h \
    search_student.h \
    student_records.hpp



FORMS += \
        homepage.ui \
        login.ui \
        new_student.ui \
        search_student.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    binary_files.qrc \
    images.qrc



