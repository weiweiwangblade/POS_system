#ifndef PAY_H
#define PAY_H

#include "ui_pay.h"

namespace Ui {
class Pay;
}

class Pay : public QWidget,public Ui::Pay
{
    Q_OBJECT
public:
    Pay(QWidget *parent = 0);
    ~Pay();

private slots:


    void on_pushButton_clicked();

private:

    Ui::Pay *paywindow;
};

#endif // PAY_H
