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
 * FileName :           InterviewQuestion.cpp
 * FileIdentification :
 * Abstract :
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#include "InterviewQuestion.h"

InterviewQuestion::InterviewQuestion() {}

int InterviewQuestion::GetSecond(const QVector<int> &vct) const
{
    if (vct.size() <= 1) {
        return -1;
    }
    int second = std::numeric_limits<int>::min();
    int max    = std::numeric_limits<int>::min();

    for (int i = 0; i < vct.size(); ++i) {
        if (vct.at(i) >= max) {
            second = max;
            max    = vct.at(i);
        }
        if (vct.at(i) > second && vct.at(i) < max) {
            second = vct.at(i);
        }
    }
    return second;
}

int InterviewQuestion::FindSubSetIndex(const QVector<int> &vct, const QVector<int> &vctSub) const
{
    int index = -1;
    if (vctSub.size() == 0) {
        return 0;
    }
    if (vct.size() < vctSub.size()) {
        return index;
    }
    for (int i = 0; i < vct.size(); ++i) {
        for (int j = 0; j < vctSub.size(); ++j) {
            if (index == -1) {
                if (j == 0 && vct.at(i) == vctSub.at(j)) {
                    index = i;
                    if (j == vctSub.size() - 1) {
                        return index;
                    }
                }
            }
            else {
                if ((i + j) >= vct.size()) {
                    index = -1;
                    return index;
                }

                if (vct.at(i + j) != vctSub.at(j)) {
                    index = -1;
                    break;
                }
                else if (j == vctSub.size() - 1) {
                    return index;
                }
            }
        }
    }
    return index;
}

std::string InterviewQuestion::CycleString(std::string &str, int s32Step) const
{
    int len = str.size();
    if (len <= 1) {
        return str;
    }
    s32Step = s32Step % len;
    if (s32Step <= 0) {
        return str;
    }
    char buff[len + 1];
    memset(buff, '\0', sizeof(buff));
    str.copy(buff, len - s32Step, s32Step);
    str.copy(&buff[len - s32Step], s32Step);
    str = std::string(buff);
    return str;
}
