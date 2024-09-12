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
 * FileName :           CTestInterviewQuestion.h
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

#include "CommonGtest.h"
#include "CommonTestModule.h"
#include "InterviewQuestion.h"

struct StruInVctOutIntItem
{
    QVector<int> in;
    int result;
};

struct StruInVctVctOutIntItem
{
    QVector<int> first;
    QVector<int> second;
    int result;
};

struct StruInStringIntOutStringItem
{
    std::string first;
    int second;
    std::string result;
};

class CTestInterviewQuestion : public Test
{
public:
    CTestInterviewQuestion();

protected:
    // Sets up the test fixture.
    virtual void SetUp();

    // Tears down the test fixture.
    virtual void TearDown();

    QString GetCurDateTime() const;
    QString ListToString(const QVector<int> &vct) const;
    void UpdateInfo();

protected:
    InterviewQuestion p;
    CustomTestInfo m_Info;
    QVector<StruInVctOutIntItem> m_Case1Data;
    QVector<StruInVctVctOutIntItem> m_Case2Data;
    QVector<StruInStringIntOutStringItem> m_Case3Data;
};
