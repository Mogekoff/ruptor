TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    analysis.cpp \
    alphabet.cpp \
    text.cpp \
    caesar.cpp

DISTFILES += \
    loremipsum \
    en \
    ru \
    GITHUBTEST

HEADERS += \
    headers.h \
    analysis.h \
    alphabet.h \
    text.h \
    caesar.h
