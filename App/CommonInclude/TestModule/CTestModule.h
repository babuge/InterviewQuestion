#pragma once

#include "CTestModule_global.h"
#include "CommonGtest.h"
#include "CommonTestModule.h"
#include <QObject>

class CTestModulePrivate;
class CTESTMODULE_EXPORT CTestModule : public QObject, public Environment
{
    Q_OBJECT
public:
    CTestModule();
    virtual ~CTestModule();
    static CTestModule *instance();
    // Override this to define how to set up the environment.
    void SetUp() override;

    // Override this to define how to tear down the environment.
    void TearDown() override;

Q_SIGNALS:
    void Signal_UpdateTestInfo(const QVariant &);

private:
    Q_DISABLE_COPY_MOVE(CTestModule)
    Q_DECLARE_PRIVATE(CTestModule)
    CTestModulePrivate *d_ptr;
};

#define g_pTestModule (CTestModule::instance())
