#include "CTestInterviewQuestion.h"
#include <QDateTime>
#include <QDebug>

CTestInterviewQuestion::CTestInterviewQuestion() {}

QString CTestInterviewQuestion::GetCurDateTime() const
{
    return QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
}

void CTestInterviewQuestion::SetUp()
{
    qDebug() << __FUNCTION__;
}

void CTestInterviewQuestion::TearDown()
{
    qDebug() << __FUNCTION__;
}

TEST_F(CTestInterviewQuestion, GetSecond)
{
    struct StruTestItem
    {
        QVector<int> in;
        int result;
    };
    const StruTestItem arrTestItem[] = {
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
    for (quint64 i = 0; i < (sizeof(arrTestItem) / sizeof(arrTestItem[0])); ++i) {
        const StruTestItem &item = arrTestItem[i];
        ASSERT_EQ(p.GetSecond(item.in), item.result);
    }
}

TEST_F(CTestInterviewQuestion, FindSubSetIndex)
{
    struct StruTestItem
    {
        QVector<int> first;
        QVector<int> second;
        int result;
    };
    const StruTestItem arrTestItem[] = {
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
    for (quint64 i = 0; i < (sizeof(arrTestItem) / sizeof(arrTestItem[0])); ++i) {
        const StruTestItem &item = arrTestItem[i];
        ASSERT_EQ(p.FindSubSetIndex(item.first, item.second), item.result);
    }
}

TEST_F(CTestInterviewQuestion, CycleString)
{
    struct StruTestItem
    {
        std::string first;
        int second;
        std::string result;
    };
    const StruTestItem arrTestItem[] = {
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
    for (quint64 i = 0; i < (sizeof(arrTestItem) / sizeof(arrTestItem[0])); ++i) {
        StruTestItem item = arrTestItem[i];
        ASSERT_EQ(p.CycleString(item.first, item.second), item.result);
    }
}
