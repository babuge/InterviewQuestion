#pragma once

#include "CommonTestModule.h"
#include "InterviewQuestion.h"

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

protected:
    InterviewQuestion p;
    TestInfo info;
};
