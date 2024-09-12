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
 * FileName :           CTestModule.h
 * FileIdentification :
 * Abstract :
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#pragma once

#include "CTestModule_global.h"
#include "CommonTestModule.h"
#include <QObject>

class CTestModulePrivate;
class TESTMODULE_EXPORT CTestModule : public QObject, public Environment
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
    void Signale_RunAllTest();
public Q_SLOTS:
    void Slot_RunAllTest();

private:
    Q_DISABLE_COPY_MOVE(CTestModule)
    Q_DECLARE_PRIVATE(CTestModule)
    CTestModulePrivate *d_ptr;
};

#define g_pTestModule (CTestModule::instance())
