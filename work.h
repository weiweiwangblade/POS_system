#ifndef WORK_H
#define WORK_H

#include "ui_work.h"
#include "pay.h"
#include <QStandardItemModel>

namespace Ui {
class Form;
}

class Form : public QWidget,public Ui::Form
{
    Q_OBJECT
public:
    Form(QWidget *parent = 0);
    ~Form();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_5_editingFinished();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

private:
    int line_number;
    QStandardItemModel *model;

    Pay paywindow;
    Ui::Form *workwindow;
};

#endif // WORK_H
