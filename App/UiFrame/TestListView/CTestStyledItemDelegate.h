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

    //    QWidget *createEditor(QWidget *parent,
    //                          const QStyleOptionViewItem &option,
    //                          const QModelIndex &index) const override;
    //    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    //    void updateEditorGeometry(QWidget *editor,
    //                              const QStyleOptionViewItem &option,
    //                              const QModelIndex &index) const override;

    //    void setModelData(QWidget *editor,
    //                      QAbstractItemModel *model,
    //                      const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    // 设置 Item 矩形区域圆角
    void setBorderRadius(int borderRadius);

    // 设置按钮大小
    void setButWidth(int btnWidth);
public slots:
    void Slots_BtnClicked(QPoint mousePoint, const QModelIndex &index);

private:
    int m_borderRadius;
    int m_btnWidth;
signals:
    void itemButClicked(int, int) const;  // 按钮点击信号
};
