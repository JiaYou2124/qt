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
private:
    QListWidget *m_pListW;
    Friend *m_pFriend;
    Book *m_pBook;
    Document *m_pDocument;

    QStackedWidget *m_pSW;
    QLineEdit *m_pLE;


};

#endif // OPEWIDGET_H
