#include "CTestModule.h"

#include <QDebug>

class CTestModulePrivate
{
    Q_DECLARE_PUBLIC(CTestModule)
public:
    explicit CTestModulePrivate(CTestModule *qPtr);

private:
    CTestModule *q_ptr;
};

CTestModulePrivate::CTestModulePrivate(CTestModule *qPtr)
    : q_ptr(qPtr)
{
}

CTestModule::CTestModule()
    : d_ptr(new CTestModulePrivate(this))
{
}

CTestModule::~CTestModule()
{
    if (d_ptr != nullptr) {
        delete d_ptr;
        d_ptr = nullptr;
    }
}

CTestModule *CTestModule::instance()
{
    static auto p_Module = new CTestModule;
    return p_Module;
}

void CTestModule::SetUp()
{
    qDebug() << __FUNCTION__;
}

void CTestModule::TearDown()
{
    qDebug() << __FUNCTION__;
}
