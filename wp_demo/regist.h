#ifndef REGIST_H
#define REGIST_H

#include <QWidget>
#include <QTextEdit>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>  //垂直布局
#include <QHBoxLayout>  //水平布局

class regist : public QWidget
{
    Q_OBJECT
public:
    explicit regist(QWidget *parent = nullptr);
    static regist &getInstance();

public slots:

private:


signals:
};

#endif // REGIST_H
