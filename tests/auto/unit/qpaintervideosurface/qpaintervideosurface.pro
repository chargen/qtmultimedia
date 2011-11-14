CONFIG += testcase
TARGET = tst_qpaintervideosurface

QT += multimedia-private multimediawidgets-private testlib
CONFIG += no_private_qt_headers_warning
contains(QT_CONFIG, opengl) | contains(QT_CONFIG, opengles2) {
   QT += opengl
} else {
   DEFINES += QT_NO_OPENGL
}

contains(QT_CONFIG, opengl): QT += opengl

SOURCES += tst_qpaintervideosurface.cpp

# QPA-minimal and OpenGL don't get along
CONFIG += insignificant_test
QT+=widgets