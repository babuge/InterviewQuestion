#include "CTestStyledItemDelegate.h"
#include "CommonTestModule.h"
#include <QPainterPath>

CTestStyledItemDelegate::CTestStyledItemDelegate(QObject *parent)
    : QStyledItemDelegate{ parent }
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
        painter->setRenderHints(QPainter::Antialiasing);
        painter->setFont(QFont("Microsoft YaHei", 10));
        int rowLineNum, rowHeight;
        QVariant var            = index.data(Qt::UserRole + 1);
        CustomTestInfo itemData = var.value<CustomTestInfo>();

        // Item 矩形区域
        QRectF rect = QRectF(option.rect);
        // 绘制Item阴影
        painter->setPen(QPen(QColor("#c7c7c7")));
        painter->setBrush(QColor("#c7c7c7"));
        painter->drawRoundedRect(QRectF(rect.x() + 4, rect.y() + 4, rect.width(), rect.height()),
                                 m_borderRadius,
                                 m_borderRadius);
        // 鼠标悬停或者选中时改变背景色
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setPen(QPen(QColor("#c4f0ff")));
            painter->setBrush(QColor("#c4f0ff"));
            painter->drawRoundedRect(rect, m_borderRadius, m_borderRadius);
        }
        else if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(QColor("#e4f0ff")));
            painter->setBrush(QColor("#e4f0ff"));
            painter->drawRoundedRect(rect, m_borderRadius, m_borderRadius);
        }
        else {
            painter->setPen(QPen(QColor("#BCF2F5")));
            painter->setBrush(QColor("#BCF2F5"));
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
        // 鼠标悬停或者选中时改变背景色
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setPen(QPen(QColor("#000000")));
        }
        else if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(QColor("#000000")));
        }
        else {
            painter->setPen(QPen(QColor("#000000")));
        }
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
            painter->setPen(QPen(QColor("#c7c7c7")));
            painter->setBrush(QColor("#c7c7c7"));
            painter->drawRoundedRect(butShadowRect, m_borderRadius, m_borderRadius);

            // 绘制按钮
            QRectF butRect(rect.width() - m_btnWidth - 10,
                           rect.y() + rowHeight * rowLineNum + (butHeight + 5) * i + 5,
                           50,
                           butHeight);
            // 根据按钮选中状态绘制按钮
            if (itemData.btnSelected[i]) {
                painter->setPen(QPen(QColor("#8f9ae6")));
                painter->setBrush(QColor("#8f9ae6"));
            }
            else {
                painter->setPen(QPen(QColor("#FFFFFF")));
                painter->setBrush(QColor("#FFFFFF"));
            }
            painter->drawRoundedRect(butRect, m_borderRadius, m_borderRadius);

            // 添加按钮文字
            painter->setPen(QPen(QColor("#000000")));
            painter->drawText(butRect, Qt::AlignCenter, itemData.btnNames.value(i));
        }
        painter->restore();
    }
}

void CTestStyledItemDelegate::on_but_clicked(QPoint mousePoint, const QModelIndex &index) {}
