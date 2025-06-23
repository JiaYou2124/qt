#ifndef ONLINE_H
#define ONLINE_H

#include <QWidget>
#include "protocol.h"

namespace Ui {
class Online;
}

class Online : public QWidget
{
    Q_OBJECT

public:
    explicit Online(QWidget *parent = nullptr);
    void showUser(PDU *pdu);
    ~Online();

private slots:
    void on_add_friend_pb_clicked();

private:
    Ui::Online *ui;
};

#endif // ONLINE_H
