#ifndef OPEWIDGET_H
#define OPEWIDGET_H

#include <QWidget>
#include <QListWidget>
#include "friend.h"
#include "book.h"
#include <QStackedWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QLineEdit>)
class Document;

class OpeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OpeWidget(QWidget *parent = nullptr);
    Friend *getFriend();
    Document *getDocument();

    static OpeWidget &getInstance();

signals:

protected:
    //鼠标事件处理函数
    void mousePressEvent(QMouseEvent *event) override;          //鼠标点击
    void mouseMoveEvent(QMouseEvent *event) override;           //鼠标移动
    void mouseReleaseEvent(QMouseEvent *event) override;        //鼠标释放
private:
    QListWidget *m_pListW;
    Friend *m_pFriend;
    Book *m_pBook;
    Document *m_pDocument;

    QStackedWidget *m_pSW;
    QLineEdit *m_pLE;


    // 添加窗口拖拽相关变量
    bool m_bDragging;
    QPoint m_dragPosition;
    bool m_bMaximized;
    QRect m_normalGeometry;


};

#endif // OPEWIDGET_H
