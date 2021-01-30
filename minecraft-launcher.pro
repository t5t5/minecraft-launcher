TEMPLATE = subdirs

SUBDIRS += 3rdparty
SUBDIRS += include
SUBDIRS += src

include.depends = 3rdparty
src.depends = 3rdparty include

OTHER_FILES += \
    .qmake.conf \
	README.md \
	ml-include.pri
