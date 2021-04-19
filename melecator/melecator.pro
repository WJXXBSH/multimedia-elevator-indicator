CONFIG += \
    c++latest \
    ltcg \
    optimize_full \
    qtquickcompiler

HEADERS += \
    elevator.h \
    media.h \
    ncov.h \
    notification.h \
    weather.h

QT += \
    quick \
    quickcontrols2 \
    svg

SOURCES += \
    elevator.cpp \
    main.cpp \
    media.cpp \
    ncov.cpp \
    notification.cpp \
    weather.cpp

RESOURCES += \
    app.qrc

VERSION = 0.7.0

windows {
    RC_ICONS = res/icons/app_icon.ico
}
