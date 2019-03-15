TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    ruptor.cpp \
    algs/caesar.cpp \
    io.cpp \
    cypher.cpp

HEADERS += \
    ruptor.h \
    headers.h \
    algs/caesar.h \
    io.h \
    cypher.h

DISTFILES += \
    langs/en \
    langs/ru \
    fishtext/loremipsum \
    fishtext/yandexreferat
