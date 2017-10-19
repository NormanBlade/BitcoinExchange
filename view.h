#ifndef VIEW_H
#define VIEW_H

#include <QLabel>
#include <QWidget>
#include "model.h"

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = 0);

    //Set the model to the view
    void setModel(Model *model);

private:
   Model *model;
   QLabel *l_main;
   QLabel *l_msg;
   QLabel *l_update;

private slots:
   //Notifies a new exchange value
   void updateExchange (QString newValue);

   //Notifies a new value for the countdown
   void updateSecLeft (int secLeft);

   //Notifies that an api request has been sent
   void requestSent();
};

#endif // VIEW_H
