#pragma once

#include <QItemDelegate>
#include <QPainter>
#include <QStyledItemDelegate>
#include <QWidget>

class CTestStyledItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CTestStyledItemDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 设置 Item 矩形区域圆角
    void setBorderRadius(int borderRadius);

    // 设置按钮大小
    void setButWidth(int btnWidth);

private:
    int m_borderRadius;
    int m_btnWidth;
};
