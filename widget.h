#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    double Weight, Height, Tal;

    double Formula_1_M(double Weight, double Tal)
    {
        double result = Weight - Weight * 0.01 * (0.31457 * Tal - 0.10969 * Weight + 10.834);
        if (result > 0)
            return result;
        else return 0;
    }
    double Formula_1_F(double Weight, double Tal, double Height)
    {
        double result = Weight - Weight * 0.01 * (100 - (0.11077 * Tal - 0.0017666 * Height + 0.14354 * Weight + 51.033));
        if (result > 0)
            return result;
        else return 0;
    }
    double Formula_2_M(double Weight, double Height)
    {
        double result = 0.407 * Weight + 0.267 * Height - 19.2;
        if (result > 0)
            return result;
        else return 0;
    }
    double Formula_2_F(double Weight, double Height)
    {
        double result = 0.252 * Weight + 0.473 * Height - 48.3;
        if (result > 0)
            return result;
        else return 0;
    }
    double Formula_3_M(double Weight, double Height)
    {
        double result = 0.3281 * Weight + 0.33929 * Height - 29.5336;
        if (result > 0)
            return result;
        else return 0;
    }
    double Formula_3_F(double Weight, double Height)
    {
        double result = 0.29569 * Weight + 0.41813 * Height - 43.2933;
        if (result > 0)
            return result;
        else return 0;
    }
    double Count_M(double Weight, double Height, double Tal)
    {
        double result = (Formula_1_M(Weight, Tal) + Formula_2_M(Weight, Height) + Formula_3_M(Weight, Height))/3;
        return result;
    }
    double Count_F(double Weight, double Height, double Tal)
    {
        double result = (Formula_1_F(Weight, Tal, Height) + Formula_2_F(Weight, Height) + Formula_3_F(Weight, Height))/3;
        return result;
    }

private slots:

    void on_pushButton_Exit_clicked();

    void on_doubleSpinBox_Height_valueChanged(double arg1);

    void on_Button_Count_clicked();

    void on_doubleSpinBox_Weight_valueChanged(double arg1);

    void on_doubleSpinBox_Tal_valueChanged(double arg1);



private:
    Ui::Widget *ui;

  };
#endif // WIDGET_H
