TEMPLATE = app
TARGET = radio

QT += multimediakit

HEADERS = \
    radio.h
  
SOURCES = \
    main.cpp \
    radio.cpp

target.path = $$[QT_INSTALL_EXAMPLES]/qtmultimediakit/radio
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/qtmultimediakit/radio

INSTALLS += target sources

