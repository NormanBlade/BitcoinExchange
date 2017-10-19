#include "view.h"
#include "model.h"
#include "QLabel"

#include <QApplication>

View::View(QWidget *parent) : QWidget(parent)
{
    //Window size
    setFixedSize(300, 100);

    //Labels
    l_main = new QLabel(this);
    l_msg = new QLabel(this);
    l_update = new QLabel(this);


    //Labels width
    l_main->setFixedWidth(256);
    l_msg->setFixedWidth(256);
    l_update->setFixedWidth(256);

    //Labels margin
    l_msg->setMargin(20);
    l_update->setMargin(40);

    //Labels text
    l_main->setText("Connecting...");
    l_msg->setText("");
    l_update->setText("");
}

void View::updateExchange(QString newValue)
{
    QString msg;
    msg = "1 BTC is currently exchanged for ";
    msg+= newValue;
    msg+= " EUR";
    l_main->setText(msg);
    l_update->setText("");
}

void View::setModel(Model *model){
    this->model = model;

    //Signal connection
    QObject::connect(model, SIGNAL(lastValueUpdate(QString)), this, SLOT(updateExchange(QString)));
    QObject::connect(model, SIGNAL(secondsLeft(int)), this, SLOT(updateSecLeft(int)));
    QObject::connect(model, SIGNAL(sendingRequest()), this, SLOT(requestSent()));

}

void View::updateSecLeft(int secLeft){
    l_msg->setText("Next update in "+QString::number(secLeft)+" seconds");
}

void View::requestSent(){
    l_update->setText("Updating...");
}
