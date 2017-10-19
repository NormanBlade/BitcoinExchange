#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QTimer>

#include "model.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    Controller(QObject *parent = 0);
    void setModel(Model *model);

private slots:
    //The method to call when the timer reaches 0
    void timerUpdate();

private:
    Model *model;
    QTimer *timer;
};

#endif // CONTROLLER_H
