#include "QTimer"

#define ON true
#define OFF false

class Button{
public:
    void setState(bool newStateStatus){
        State = newStateStatus;
    }

    bool getState(){
        return State;
    }

    void onClick(){
        timer->start(1);
        setState(!getState());
    }


    Button(QTimer* TIMER, bool defaultState = OFF)
    {
        timer = TIMER;
        State = defaultState;
    }

private:
    QTimer* timer;
    bool State;
};




