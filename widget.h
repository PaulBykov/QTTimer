#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QString>

#define ON true
#define OFF false

typedef unsigned long long ull;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QString addForwardZero(ull);
    QString getFormatedTime(ull, ull, ull);
    void timerReset();

private:
    Ui::Widget *ui;
    QTimer *timer;
    ull volatile seconds = 0, minutes = 0, milliseconds = 0;
    bool buttonState = ON;
    QString buttonStatusText;
    bool checkboxState = false;

private slots:
    void timerSlot();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_tabWidget_tabBarClicked(int index);
    void on_horizontalSlider_valueChanged(int value);
};

#endif // WIDGET_H
