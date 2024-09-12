QT -= gui

TEMPLATE = lib
DEFINES += TESTMODULE_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include($${ProConfig}/ModuleConfig.pri)

SOURCES += \
    CTestEventListener.cpp \
    CTestModule.cpp \
    TestInterviewQuestion/CTestInterviewQuestion.cpp

HEADERS += \
    CTestEventListener.h \
    CTestModule.h \
    CTestModule_global.h \
    CommonTestModule.h \
    TestInterviewQuestion/CTestInterviewQuestion.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

# gtest
if(win32){
    if(mingw){
        $$headersLibCopyFunc($${OUTLIB},"", $${ProjectRootDir}/3rdparty/GTest-1.8.x/lib/mingw/libgtest.dll)
        LIBS += -L$${OUTLIB}/ -lgtest
    } else {
        $$headersLibCopyFunc($${OUTLIB},"", $${ProjectRootDir}/3rdparty/GTest-1.8.x/lib/win/libgtest.dll)
        LIBS += $${OUTLIB}/libgtest.dll
    }
} esle {
    $$headersLibCopyFunc($${OUTLIB},"", $${ProjectRootDir}/3rdparty/GTest-1.8.x/lib/linux/libgtest.so)
    LIBS += -L$${OUTLIB}/ -lgtest
}

LIBS += -L$${OUTLIB}/ -lInterviewQuestion


INCLUDEPATH += $${ThridParty}/GTest-1.8.x/include
INCLUDEPATH += $${CommonDir}/InterviewQuestion

$$headersLibCopyFunc($${CommonDir},"TestModule", $${Modules}/TestModule/CTestModule.h \
    $${Modules}/TestModule/CommonTestModule.h \
    $${Modules}/TestModule/CTestModule_global.h)
message(TESTMODULE_LIBRARY)
