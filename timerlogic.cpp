#include "widget.h"
#include "buttonlogic.cpp"


class Time{
public:
    QString addForwardZero(unsigned int a){
        return(a < 10 ? "0" + a : "" + a);
    }

    QString getFormatedTime(){
        return (addForwardZero(hours) + ":" + addForwardZero(minutes) + ":" + addForwardZero(seconds));
    }

    void tick(){

    };

    unsigned seconds: 6;
    unsigned minutes: 6;
    unsigned hours: 16;

    Time(unsigned s = 0, unsigned m = 0, unsigned h = 0){
        seconds = s;
        minutes = m;
        hours = h;
    }
};



class Timer{
public:
    Button button;
    Time time;
};
