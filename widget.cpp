#include "widget.h"
#include "ui_widget.h"
#include <chrono>

unsigned short TPS = 30;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setWindowTitle("TimerEasy");
    setLocale(QLocale::English);
    setFixedSize(280, 190);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot()));

    ui->toolButton->setToolTip("Количество обновлений секундомера в секунду. При меньших значениях больше точность, но возврастает погрешность.");


}

Widget::~Widget()
{
    delete ui;
}

QString inline Widget::addForwardZero(ull time){
    return (time < 10 ? "0" + QString::number(time) : QString::number(time));
}

QString inline Widget::getFormatedTime(ull ms, ull s, ull m){
    return(addForwardZero(m) + ":" + addForwardZero(s) + ":" + addForwardZero(ms));
}

void Widget::timerReset(){
    milliseconds = seconds = minutes = 0;
}

void Widget::timerSlot()
{
    milliseconds+= TPS;

    if(milliseconds >= 1000){
        milliseconds = 0;
        seconds++;
    }
    if(seconds >= 60){
        seconds = 0;
        minutes++;
    }

    ui->label->setText(getFormatedTime(milliseconds, seconds, minutes));

}

void Widget::on_pushButton_clicked()
{
    buttonState = !buttonState;

    if(!buttonState){
        timer->start(TPS);
        buttonStatusText = "Stop";
    }
    else{
        timer->stop();
        buttonStatusText = "Start";
    }

    ui->pushButton->setText(buttonStatusText);
}

void Widget::on_pushButton_2_clicked()
{
    timer->stop();
    ui->pushButton->setText("Start");
    milliseconds = 0;
    seconds = 0;
    minutes = 0;
    ui->label->setText(getFormatedTime(milliseconds, seconds, minutes) + "0");
}

void Widget::on_tabWidget_tabBarClicked(int index)
{
    if(!(index - 1)){
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->label->hide();

        ui->label_2->show();
        ui->label_3->show();
        //ui->label_4->show();
        ui->horizontalSlider->show();
    }
    else{
        ui->pushButton->show();
        ui->pushButton_2->show();
        ui->label->show();

        ui->label_2->hide();
        ui->label_3->hide();
        //ui->label_4->hide();
        ui->horizontalSlider->hide();
    }
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    TPS = value;
}
