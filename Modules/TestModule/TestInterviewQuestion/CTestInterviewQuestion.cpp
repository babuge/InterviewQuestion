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
 * FileName :           CTestInterviewQuestion.cpp
 * FileIdentification :
 * Abstract :
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#include "CTestInterviewQuestion.h"
#include "CTestModule.h"
#include <QDateTime>
#include <QDebug>

CTestInterviewQuestion::CTestInterviewQuestion() {}

QString CTestInterviewQuestion::GetCurDateTime() const
{
    return QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
}

QString CTestInterviewQuestion::ListToString(const QVector<int> &vct) const
{
    QString ret;
    foreach (const int &i, vct) {
        ret.append(" " + QString::number(i));
    }
    return ret;
}

void CTestInterviewQuestion::UpdateInfo()
{
    if (g_pTestModule != nullptr) {
        emit g_pTestModule->Signal_UpdateTestInfo(QVariant::fromValue<CustomTestInfo>(m_Info));
    }
}

void CTestInterviewQuestion::SetUp()
{
    m_Info.itemName  = "InterviewQuestion";
    m_Info.indexName = "";
    m_Info.isFold    = false;
    m_Info.date      = GetCurDateTime();
    m_Info.rowName << QString("SetUp");
    m_Info.rowData << QString("InterviewQuestion");
    UpdateInfo();
    m_Case1Data = {
        { {}, -1 },
        { { 1 }, -1 },
        { { 5, 5, 5, 5, 5, 2 }, 5 },
        { { 5, 5, 5, 5, 5, 5 }, 5 },
        { { 2, 4, 4, 4, 4, 5 }, 4 },
        { { 1, 2, 3, 4, 5, 6 }, 5 },
        { { 5, 4, 3, 2, 1, 0 }, 4 },
        { { 5, 4, 3, 3, 4, 5 }, 5 },
        { { 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3,
            4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3,
            3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4,
            3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5,
            4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4,
            5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3,
            4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3,
            3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4,
            3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5,
            4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4,
            5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3,
            4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3,
            3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4,
            3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5,
            4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4,
            5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5 },
          5 },
    };

    m_Case2Data = {
        { {}, {}, 0 },
        { {}, { 7 }, -1 },
        { { 7 }, { 7 }, 0 },
        { { 1, 1, 7, 3, 7 }, { 3, 7, 4 }, -1 },
        { { 1, 1, 7, 3, 7, 4 }, { 3, 7, 4 }, 3 },
        { { 3, 7, 4, 1, 1, 7 }, { 3, 7, 4 }, 0 },
        { { 3, 7, 4, 1, 1, 7 }, { 3, 7, 4, 1, 1, 7 }, 0 },
        { { 3, 7, 4, 1, 3, 7, 4 }, { 3, 7, 4 }, 0 },
        { { 3, 7, 4, 1, 3, 7, 4, 1, 3 }, { 4, 1, 3 }, 2 },
        { { 3, 7, 4, 1, 3, 7, 4, 1, 6 }, { 6 }, 8 },
        { { 6, 7, 4, 1, 3, 7, 4, 1, 6 }, { 6 }, 0 },
    };

    m_Case3Data = {
        { "", 1, "" },
        { "1", 1, "1" },
        { "12", 1, "21" },
        { "12bc", 1, "2bc1" },
        { "abcdefg", 3, "defgabc" },
        { "abcdefg123", 3, "defg123abc" },
        { "abcdefg123", 100000000, "abcdefg123" },

        { "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123",
          100,
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdef"
          "g123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcd"
          "efg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123ab"
          "cdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123"
          "abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg1"
          "23abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123abcdefg123" },
    };
}

void CTestInterviewQuestion::TearDown()
{
    qDebug() << "CTestInterviewQuestion::TearDown";

    m_Info.itemName  = "InterviewQuestion";
    m_Info.indexName = "";
    m_Info.isFold    = false;
    m_Info.date      = GetCurDateTime();
    m_Info.rowName << QString("TearDown");
    m_Info.rowData << QString("InterviewQuestion");
    UpdateInfo();
    m_Case1Data.clear();
    m_Case1Data.squeeze();
    m_Case2Data.clear();
    m_Case2Data.squeeze();
    m_Case3Data.clear();
    m_Case3Data.squeeze();
}

TEST_F(CTestInterviewQuestion, GetSecond)
{
    m_Info.indexName = "GetSecond";
    m_Info.date      = GetCurDateTime();
    m_Info.rowName << QString("runing case::GetSecond");
    m_Info.rowData << QString("获取数组中第二大的值，只循环一次");
    UpdateInfo();
    struct ResultItem
    {
        const StruInVctOutIntItem &Input;
        int retReal;
    };

    auto IsSecond = [=](const ResultItem &result) {
        QString str = ListToString(result.Input.in) + " ,ret: " + QString::number(result.retReal)
                      + " ,Expected: " + QString::number(result.Input.result);
        if (result.retReal == result.Input.result) {
            str = "SuccessResult: in: " + str;
            return testing::AssertionSuccess() << str.toStdString();
        }
        else {
            str = "FaulureResult: in: " + str;
            return testing::AssertionFailure() << str.toStdString();
        }
    };
    for (int i = 0; i < m_Case1Data.size(); ++i) {
        ResultItem resultItem = { m_Case1Data.at(i), 0 };
        resultItem.retReal    = p.GetSecond(resultItem.Input.in);
        ::testing::AssertionResult AssertResult(IsSecond(resultItem));
        EXPECT_TRUE(AssertResult);

        m_Info.date = GetCurDateTime();
        m_Info.rowName << QString("Part_%1").arg(i + 1);
        m_Info.rowData << QString(AssertResult.message());
        UpdateInfo();
    }

    m_Info.date = GetCurDateTime();
    m_Info.rowName << QString("runing end");
    m_Info.rowData << QString("all case");
    UpdateInfo();
}

TEST_F(CTestInterviewQuestion, FindSubSetIndex)
{
    m_Info.indexName = "FindSubSetIndex";
    m_Info.date      = GetCurDateTime();
    m_Info.rowName << QString("runing case::FindSubSetIndex");
    m_Info.rowData << QString("获取数组a的子集b第一次出现在a的位置");
    UpdateInfo();

    struct ResultItem
    {
        const StruInVctVctOutIntItem &Input;
        int retReal;
    };

    auto IsFindSubSetIndex = [=](const ResultItem &result) {
        QString str = "firstIn: " + ListToString(result.Input.first)
                      + " secondIn: " + ListToString(result.Input.second)
                      + " ,ret: " + QString::number(result.retReal)
                      + " ,Expected: " + QString::number(result.Input.result);
        if (result.retReal == result.Input.result) {
            str = "SuccessResult: in: " + str;
            return testing::AssertionSuccess() << str.toStdString();
        }
        else {
            str = "FaulureResult: in: " + str;
            return testing::AssertionFailure() << str.toStdString();
        }
    };
    for (int i = 0; i < m_Case2Data.size(); ++i) {
        ResultItem resultItem = { m_Case2Data.at(i), -1 };
        resultItem.retReal    = p.FindSubSetIndex(resultItem.Input.first, resultItem.Input.second);
        ::testing::AssertionResult AssertResult(IsFindSubSetIndex(resultItem));
        EXPECT_TRUE(AssertResult);

        m_Info.date = GetCurDateTime();
        m_Info.rowName << QString("Part_%1").arg(i + 1);
        m_Info.rowData << QString(AssertResult.message());
        UpdateInfo();
    }

    m_Info.date = GetCurDateTime();
    m_Info.rowName << QString("runing end");
    m_Info.rowData << QString("all case");
    UpdateInfo();
}

TEST_F(CTestInterviewQuestion, CycleString)
{
    m_Info.indexName = "CycleString";
    m_Info.date      = GetCurDateTime();
    m_Info.rowName << QString("runing case::CycleString");
    m_Info.rowData << QString("获取字符串循环n次后的值，如‘abcdef’循环2次为‘cdefab’");
    UpdateInfo();
    struct ResultItem
    {
        StruInStringIntOutStringItem Input;
        std::string retReal;
    };

    auto IsCycleString = [=](const ResultItem &result) {
        QString str = "firstIn: " + QString::fromStdString(result.Input.first)
                      + " secondIn: " + QString::number(result.Input.second)
                      + " ,ret: " + QString::fromStdString(result.retReal)
                      + " ,Expected: " + QString::fromStdString(result.Input.result);
        if (result.retReal == result.Input.result) {
            str = "SuccessResult: in: " + str;
            return testing::AssertionSuccess() << str.toStdString();
        }
        else {
            str = "FaulureResult: in: " + str;
            return testing::AssertionFailure() << str.toStdString();
        }
    };

    for (int i = 0; i < m_Case3Data.size(); ++i) {
        ResultItem resultItem = { m_Case3Data.at(i), "" };
        std::string str_First = resultItem.Input.first;
        resultItem.retReal    = p.CycleString(str_First, resultItem.Input.second);
        ::testing::AssertionResult AssertResult(IsCycleString(resultItem));
        EXPECT_TRUE(AssertResult);

        m_Info.date = GetCurDateTime();
        m_Info.rowName << QString("Part_%1").arg(i + 1);
        m_Info.rowData << QString(AssertResult.message());
        UpdateInfo();
    }

    m_Info.date = GetCurDateTime();
    m_Info.rowName << QString("runing end");
    m_Info.rowData << QString("all case");
    UpdateInfo();
}
