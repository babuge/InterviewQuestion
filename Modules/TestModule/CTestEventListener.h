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
