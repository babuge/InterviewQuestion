TEMPLATE=subdirs

SUBDIRS += InterviewQuestion \
    TestModule

App.depends += TestModule
TestModule.depends += InterviewQuestion
