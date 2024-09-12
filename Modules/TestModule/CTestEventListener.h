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
 * FileName :           CTestEventListener.h
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

#include "CommonTestModule.h"
#include <QDebug>
#include <QObject>

class CTestEventListener : public QObject, public EmptyTestEventListener
{
public:
    CTestEventListener();
    // 在env StartUp添加监听，TearDown移除监听，目前未启用
    void OnEnvironmentsSetUpEnd(const UnitTest &unit_test) override;
    void OnTestCaseStart(const TestCase &test_case) override;
    void OnTestStart(const TestInfo &test_info) override;
    void OnTestPartResult(const TestPartResult &test_part_result) override;
    void OnTestEnd(const TestInfo &test_info) override;
    void OnTestCaseEnd(const TestCase &test_case) override;
    void OnEnvironmentsTearDownStart(const UnitTest &unit_test) override;
};
e;
};
