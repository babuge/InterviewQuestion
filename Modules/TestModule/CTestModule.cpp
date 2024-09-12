#include "CTestModule.h"
#include "CTestEventListener.h"
#include <QDateTime>
#include <QDebug>

class CTestModulePrivate
{
    Q_DECLARE_PUBLIC(CTestModule)
public:
    explicit CTestModulePrivate(CTestModule *qPtr);
    ~CTestModulePrivate();

private:
    CTestModule *q_ptr;
    CTestEventListener *m_pListener;
};

CTestModulePrivate::CTestModulePrivate(CTestModule *qPtr)
    : q_ptr(qPtr)
    , m_pListener(nullptr)  //(new CTestEventListener)
{
}

CTestModulePrivate::~CTestModulePrivate()
{
    if (m_pListener != nullptr) {
        delete m_pListener;
        m_pListener = nullptr;
    }
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
    qDebug() << "CTestModule::SetUp";

    Q_D(CTestModule);
    if (d->m_pListener != nullptr) {
        ::testing::UnitTest::GetInstance()->listeners().Append(d->m_pListener);
    }
    CustomTestInfo info;
    info.isFold    = false;
    info.date      = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    info.itemName  = "TestModule";
    info.indexName = "SetUp";
    emit this->Signal_UpdateTestInfo(QVariant::fromValue<CustomTestInfo>(info));
}

void CTestModule::TearDown()
{
    qDebug() << "CTestModule::TearDown";
    Q_D(CTestModule);
    if (d->m_pListener != nullptr) {
        ::testing::UnitTest::GetInstance()->listeners().Release(d->m_pListener);
    }

    CustomTestInfo info;
    info.isFold    = false;
    info.date      = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    info.itemName  = "TestModule";
    info.indexName = "TearDown";
    emit this->Signal_UpdateTestInfo(QVariant::fromValue<CustomTestInfo>(info));
}

void CTestModule::Slot_RunAllTest()
{
    int i = RUN_ALL_TESTS();
    qDebug() << (i == 0 ? "success" : "failed");
}
