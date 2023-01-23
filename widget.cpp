#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_doubleSpinBox_Height_valueChanged(double arg1)
{
    Height = arg1;
}

void Widget::on_doubleSpinBox_Weight_valueChanged(double arg1)
{
    Weight = arg1;
}


void Widget::on_doubleSpinBox_Tal_valueChanged(double arg1)
{
    Tal = arg1;
}

void Widget::on_Button_Count_clicked()
{
    if (ui->radioButton_M->isChecked() && Count_M(Weight, Height, Tal) > 0)
    ui->lineEdit->setText(QString :: number(Count_M(Weight, Height, Tal)));


    if (ui->radioButton_F->isChecked() && Count_F(Weight, Height, Tal) > 0)
    ui->lineEdit->setText(QString :: number(Count_F(Weight, Height, Tal)));
}

void Widget::on_pushButton_Exit_clicked()
{
    qApp->exit();
}


