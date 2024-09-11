#pragma once

#include "InterviewQuestion_global.h"

#include <QVector>

class INTERVIEWQUESTION_EXPORT InterviewQuestion
{
public:
    InterviewQuestion();

    int GetSecond(const QVector<int> &vct) const;

    int FindSubSetIndex(const QVector<int> &vct, const QVector<int> &vctSub) const;

    std::string CycleString(std::string &str, int s32Step) const;
};
