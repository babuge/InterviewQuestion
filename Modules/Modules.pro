TEMPLATE=subdirs

SUBDIRS += InterviewQuestion \
    TestModule

TestModule.depends = InterviewQuestion
