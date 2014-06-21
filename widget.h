#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "ui_widget.h"
#include "work.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget,public Ui::Widget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void show_work_window(void);


    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_lineEdit_2_editingFinished();

private:
    Form workwindow;

    QWidget *window;
    Ui::Widget *loginwindow;
};

#endif // WIDGET_H
