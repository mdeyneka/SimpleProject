TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    employeebase.cpp \
    employeehourlypay.cpp \
    employeefixedpay.cpp \
    employeecontainer.cpp

HEADERS += \
    employeebase.h \
    employeehourlypay.h \
    employeefixedpay.h \
    employeecontainer.h

