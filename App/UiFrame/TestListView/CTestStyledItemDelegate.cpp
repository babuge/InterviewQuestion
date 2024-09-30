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
 * FileName :           CTestStyledItemDelegate.cpp
 * FileIdentification :
 * Abstract :
 * CurrentVersion :     v0.1.0
 * author:              babuge
 * CompletionDate :
 * AlternateVersion :
 * authorship :         babuge
 * CompletionDate :     2024/09/12
 ******************************************************************************/

#include "CTestStyledItemDelegate.h"
#include "CommonTestModule.h"
#include <QPainterPath>

namespace
{
const QColor clr_showdow(0xc7, 0xc7, 0xc7);
const QColor clr_hover(0xc4, 0xf0, 0xff);
const QColor clr_defalut(0xBC, 0xF2, 0xF5);
const QColor clr_white(0xFF, 0xFF, 0xFF);
const QColor clr_selected(0x8f, 0x9a, 0xe6);
const QColor clr_gray(0xc7, 0xc7, 0xc7);
const QColor clr_darkgray(0x33, 0x33, 0x33);
const QColor clr_block(0x0, 0x0, 0x0);
}  // namespace

CTestStyledItemDelegate::CTestStyledItemDelegate(QObject *parent)
    : QStyledItemDelegate{ parent }
    , m_borderRadius(4)
    , m_btnWidth(126)
{
}

// 设置 Item 矩形区域圆角
void CTestStyledItemDelegate::setBorderRadius(int borderRadius)
{
    m_borderRadius = borderRadius;
}

// 设置按钮大小
void CTestStyledItemDelegate::setButWidth(int btnWidth)
{
    m_btnWidth = btnWidth;
}
void CTestStyledItemDelegate::paint(QPainter *painter,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const
{
    if (index.isValid()) {
        painter->save();
        // 图形和文本抗锯齿
        painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
        painter->setFont(QFont("Microsoft YaHei", 10));
        int rowLineNum, rowHeight;
        QVariant var            = index.data(Qt::UserRole + 1);
        CustomTestInfo itemData = var.value<CustomTestInfo>();

        // Item 矩形区域
        QRectF rect = QRectF(option.rect);
        // 绘制Item阴影
        painter->setPen(QPen(clr_showdow));
        painter->setBrush(clr_showdow);
        painter->drawRoundedRect(QRectF(rect.x() + 4, rect.y() + 4, rect.width(), rect.height()),
                                 m_borderRadius,
                                 m_borderRadius);
        // 鼠标悬停或者选中时改变背景色
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setPen(QPen(clr_hover));
            painter->setBrush(clr_hover);
            painter->drawRoundedRect(rect, m_borderRadius, m_borderRadius);
        }
        else if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(clr_selected));
            painter->setBrush(clr_selected);
            painter->drawRoundedRect(rect, m_borderRadius, m_borderRadius);
        }
        else {
            painter->setPen(QPen(clr_defalut));
            painter->setBrush(clr_defalut);
            painter->drawRoundedRect(rect, m_borderRadius, m_borderRadius);
        }
        QPainterPath rowPath;
        // 判断选项卡是否折叠
        if (!itemData.isFold) {
            // 计算行高和行数
            rowLineNum = itemData.rowName.length() + 1;
            rowHeight  = rect.height() / (itemData.rowName.length() + 3);
            for (int i = 1; i <= rowLineNum; i++) {
                rowPath.moveTo(QPointF(rect.x(), rect.y() + rowHeight * i));
                rowPath.lineTo(QPointF(rect.width() + 5, rect.y() + rowHeight * i));
            }
            // 绘制item
        }
        else {
            rowLineNum = 1;
            rowHeight  = rect.height() / 3;
            rowPath.moveTo(QPointF(rect.x(), rect.y() + rowHeight));
            rowPath.lineTo(QPointF(rect.width() + 5, rect.y() + rowHeight));
        }

        painter->setPen(QPen(clr_darkgray));
        painter->drawPath(rowPath);  // 绘制行线
        for (int i = 1; i < rowLineNum; i++) {

            QRectF textRect(rect.x(), rect.y() + rowHeight * i, rect.width(), rowHeight);
            painter->drawText(textRect, Qt::AlignVCenter, itemData.rowName.value(i - 1));
            QRectF dataRect(
                textRect.width() / 3, textRect.y(), textRect.width(), textRect.height());
            painter->drawText(dataRect, Qt::AlignVCenter, itemData.rowData.value(i - 1));
        }
        // 绘制标题
        painter->drawText(QRectF(rect.x(), rect.y(), rect.width(), rowHeight),
                          Qt::AlignCenter,
                          itemData.itemName);
        painter->setFont(QFont("Microsoft YaHei", 11));
        painter->drawText(
            QRectF(rect.x(), rect.y() + rowHeight * rowLineNum, rect.width(), rowHeight * 1.2),
            Qt::AlignVCenter,
            itemData.indexName);
        painter->setFont(QFont("Microsoft YaHei", 9));
        painter->drawText(QRectF(rect.x(),
                                 rect.y() + rowHeight * rowLineNum + rowHeight * 1.2,
                                 rect.width(),
                                 rowHeight * 0.8),
                          Qt::AlignVCenter,
                          itemData.date);
        // 绘制按钮
        int butHeight = (rowHeight * 2 - 15) / 2;
        for (int i = 0; i < itemData.btnNames.size(); i++) {
            // 绘制按钮阴影
            QRectF butShadowRect(rect.width() - m_btnWidth - 8,
                                 rect.y() + rowHeight * rowLineNum + (butHeight + 5) * i + 7,
                                 50,
                                 butHeight);
            painter->setPen(QPen(clr_gray));
            painter->setBrush(clr_gray);
            painter->drawRoundedRect(butShadowRect, m_borderRadius, m_borderRadius);

            // 绘制按钮
            QRectF butRect(rect.width() - m_btnWidth - 10,
                           rect.y() + rowHeight * rowLineNum + (butHeight + 5) * i + 5,
                           50,
                           butHeight);
            // 根据按钮选中状态绘制按钮
            if (itemData.btnSelected[i]) {
                painter->setPen(QPen(clr_selected));
                painter->setBrush(clr_selected);
            }
            else {
                painter->setPen(QPen(clr_white));
                painter->setBrush(clr_white);
            }
            painter->drawRoundedRect(butRect, m_borderRadius, m_borderRadius);

            // 添加按钮文字
            painter->setPen(QPen(clr_block));
            painter->drawText(butRect, Qt::AlignCenter, itemData.btnNames.value(i));
        }
        painter->restore();
    }
}
QSize CTestStyledItemDelegate::sizeHint(const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    Q_UNUSED(index)
    QVariant var            = index.data(Qt::UserRole + 1);
    CustomTestInfo itemData = var.value<CustomTestInfo>();
    if (itemData.isFold) {
        return QSize(option.rect.width(), 3 * 40);
    }
    else {
        return QSize(option.rect.width(), (itemData.rowName.length() + 3) * 40);
    }
}
