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
