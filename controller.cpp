#include "controller.h"
#include <QTimer>

Controller::Controller(QObject *parent) : QObject(parent){
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
}

void Controller::timerUpdate(){
    model->stepTimer();
}

void Controller::setModel(Model *model){
    //Sets the model to the controller
    this->model = model;

    //Tells the model to send the first request
    model->exchangeValueRequest();

    //Starts the timer
    timer->start(1000);
}
