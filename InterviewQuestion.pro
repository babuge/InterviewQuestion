TEMPLATE = subdirs

SUBDIRS += Modules \
    App

App.depends = Modules


OTHER_FILES += \
    .clang-format \
    .qmake.conf
