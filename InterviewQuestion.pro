TEMPLATE = subdirs

SUBDIRS += Modules \
    App

#App.depends = Modules/TestModule


OTHER_FILES += \
    .clang-format \
    .qmake.conf
