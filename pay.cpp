#include "pay.h"

Pay::Pay(QWidget *parent) :
    QWidget(parent),
    paywindow(new Ui::Pay)
{
    paywindow->setupUi(this);
}

Pay::~Pay()
{
    delete paywindow;
}

void Pay::on_pushButton_clicked()
{
    this->close();
}
