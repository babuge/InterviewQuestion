/******************************************************************************
 * Copyright (C) [2024] [github.com/babuge]
 *
 * [InterviewQuestion] is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 *
 * FileName :           CTestModule.cpp
 * FileIdentification :
 * Abstract :           
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :   
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

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
    CustomTestInfo m_info;
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
    d->m_info.isFold    = false;
    d->m_info.date      = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    d->m_info.itemName  = "TestModule";
    d->m_info.indexName = "SetUp";
    emit this->Signal_UpdateTestInfo(QVariant::fromValue<CustomTestInfo>(d->m_info));
}

void CTestModule::TearDown()
{
    qDebug() << "CTestModule::TearDown";
    Q_D(CTestModule);
    if (d->m_pListener != nullptr) {
        ::testing::UnitTest::GetInstance()->listeners().Release(d->m_pListener);
    }

    d->m_info.isFold    = false;
    d->m_info.date      = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    d->m_info.itemName  = "TestModule";
    d->m_info.indexName = "TearDown";
    emit this->Signal_UpdateTestInfo(QVariant::fromValue<CustomTestInfo>(d->m_info));
}

void CTestModule::Slot_RunAllTest()
{
    int i = RUN_ALL_TESTS();
    qDebug() << (i == 0 ? "success" : "failed");
}
");
}
