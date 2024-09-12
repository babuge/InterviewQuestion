#include "CTestEventListener.h"

CTestEventListener::CTestEventListener() {}

void CTestEventListener::OnEnvironmentsSetUpEnd(const UnitTest &unit_test)
{
    qDebug() << "OnEnvironmentsSetUpEnd";
    qDebug() << "run-test-success-count:" << unit_test.successful_test_count();
    qDebug() << "run-test-case-success-count:" << unit_test.successful_test_case_count();
}

void CTestEventListener::OnTestCaseStart(const TestCase &test_case)
{
    qDebug() << "OnTestCaseStart";
    qDebug() << "test_case_name" << test_case.name() << "\nsuccessful_test_count"
             << test_case.successful_test_count();
}
void CTestEventListener::OnTestStart(const TestInfo &test_info)
{
    qDebug() << "OnTestStart";
    qDebug() << "test_info_name" << test_info.name() << "\ntest_case_name"
             << test_info.test_case_name() << "\nfile" << test_info.file() << "\nline "
             << test_info.line() << "\nis_in_another_shard " << test_info.is_in_another_shard()
             << "is_reportable " << test_info.is_reportable() << "\nshould_run "
             << test_info.should_run() << "\ntype_param " << test_info.type_param()
             << "\nvalue_param " << test_info.value_param();
}

void CTestEventListener::OnTestPartResult(const TestPartResult &test_part_result)
{
    qDebug() << "OnTestPartResult";
    qDebug() << "test_part_result-file_name" << test_part_result.file_name() << ":"
             << test_part_result.line_number() << "\ntype" << test_part_result.type() << "\nmessage"
             << test_part_result.message() << " passed" << test_part_result.passed() << "\nsummary"
             << test_part_result.summary() << "\nfatally_failed"
             << test_part_result.fatally_failed() << " nonfatally_failed"
             << test_part_result.nonfatally_failed();
}

void CTestEventListener::OnTestEnd(const TestInfo &test_info)
{
    qDebug() << "OnTestEnd";
    qDebug() << "test_info_name" << test_info.name() << "\ntest_case_name"
             << test_info.test_case_name() << "\nfile" << test_info.file() << "\nline "
             << test_info.line() << "\nis_in_another_shard " << test_info.is_in_another_shard()
             << "\nis_reportable " << test_info.is_reportable() << "\nshould_run "
             << test_info.should_run() << "\ntype_param " << test_info.type_param()
             << "\nvalue_param " << test_info.value_param();
    if (test_info.result() != NULL) {
        qDebug() << "\nresult elapsed_time:" << test_info.result()->elapsed_time()
                 << "\nresult total_part_count:" << test_info.result()->total_part_count()
                 << "\nresult Passed :" << test_info.result()->Passed()
                 << "\nresult Failed :" << test_info.result()->Failed();
    }
}

void CTestEventListener::OnTestCaseEnd(const TestCase &test_case)
{
    qDebug() << "OnTestCaseEnd";
    qDebug() << "test_case_name" << test_case.name() << "\nsuccessful_test_count"
             << test_case.successful_test_count();
}

void CTestEventListener::OnEnvironmentsTearDownStart(const UnitTest & /*unit_test*/)
{
    qDebug() << "OnEnvironmentsTearDownStart";
}
