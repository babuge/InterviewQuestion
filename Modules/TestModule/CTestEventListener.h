#pragma once

#include "CommonGtest.h"
#include "CommonTestModule.h"
#include <QDebug>
#include <QObject>

class CTestEventListener : public QObject, public EmptyTestEventListener
{
public:
    CTestEventListener();
    //    void OnTestProgramStart(const UnitTest &unit_test) override
    //    {
    //        int len = unit_test.total_test_case_count();
    //        qDebug() << "OnTestProgramStart" << len;
    //        //        for (int i = 0; i < len; ++len) {
    //        //            const TestCase *test_Case = unit_test.GetTestCase(i);
    //        //            if (test_Case != NULL) {
    //        //                qDebug() << "test_Case-name" << test_Case->name() <<
    //        "\niterationtest" <<
    //        //                i
    //        //                         << "\ntype_param" << test_Case->type_param() <<
    //        "\nshould_run"
    //        //                         << test_Case->should_run();
    //        //            }
    //        //        }
    //    }
    //    void OnTestIterationStart(const UnitTest &unit_test, int iterationtest) override
    //    {
    //        qDebug() << "OnTestIterationStart";

    //        const TestCase *test_case = unit_test.current_test_case();
    //        if (test_case != NULL) {
    //            qDebug() << "current_test_case-name" << test_case->name();
    //        }
    //        qDebug() << "\niterationtest" << iterationtest;
    //    }
    //    void OnEnvironmentsSetUpStart(const UnitTest &unit_test) override
    //    {
    //        qDebug() << "OnEnvironmentsSetUpStart";
    //        qDebug() << "run-test-count:" << unit_test.total_test_count();
    //        qDebug() << "run-case-count:" << unit_test.total_test_case_count();
    //    }
    void OnEnvironmentsSetUpEnd(const UnitTest &unit_test) override;
    void OnTestCaseStart(const TestCase &test_case) override;
    void OnTestStart(const TestInfo &test_info) override;
    void OnTestPartResult(const TestPartResult &test_part_result) override;
    void OnTestEnd(const TestInfo &test_info) override;
    void OnTestCaseEnd(const TestCase &test_case) override;
    void OnEnvironmentsTearDownStart(const UnitTest &unit_test) override;

    //    void OnEnvironmentsTearDownEnd(const UnitTest &unit_test) override
    //    {
    //        qDebug() << "OnEnvironmentsTearDownEnd";
    //        if (unit_test.current_test_case()) {
    //            qDebug() << "current_test_case-name" << unit_test.current_test_case()->name();
    //        }
    //    }
    //    void OnTestIterationEnd(const UnitTest &unit_test, int iterationtest) override
    //    {
    //        qDebug() << "OnTestIterationEnd" << iterationtest;
    //        if (unit_test.current_test_case()) {
    //            qDebug() << "current_test_case-name" << unit_test.current_test_case()->name()
    //                     << "\niterationtest" << iterationtest << "\ntotal_test_count"
    //                     << unit_test.current_test_case()->total_test_count();
    //        }
    //    }
    //    void OnTestProgramEnd(const UnitTest &unit_test) override
    //    {
    //        qDebug() << "OnTestProgramEnd";
    //        int len = unit_test.total_test_case_count();
    //        for (int i = 0; i < len; ++len) {
    //            const TestCase *test_Case = unit_test.GetTestCase(i);
    //            if (test_Case != NULL) {
    //                qDebug() << "test_Case-name" << test_Case->name() << "\ntype_param"
    //                         << test_Case->type_param() << "\nshould_run" <<
    //                         test_Case->should_run()
    //                         << "\nPassed" << test_Case->Passed() << "\nfailed_test_count"
    //                         << test_Case->failed_test_count() << "\nsuccessful_test_count"
    //                         << test_Case->successful_test_count();
    //            }
    //        }
    //    }
};
