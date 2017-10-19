#ifndef MODEL_H
#define MODEL_H

#include <QNetworkAccessManager>
#include <QNetworkReply>

class Model : public QObject
{
    Q_OBJECT

public:
    Model();

    //Getter for the last value
    float LastExchangeValue();

    //Starts a new request for the latest exchange value
    void exchangeValueRequest();

    //Increment the countdown counter
    void stepTimer();

signals:
    //Contains the latest update for the exchange value
    void lastValueUpdate(QString newValue);

    //Contains the current amount of seconds left before the next request
    void secondsLeft(int sec);

    //Notfy that a request has been sent
    void sendingRequest();

private:
    //Latest retrieved exchange value
    float lastExchangeValue;

    //The network manager for the http request
    QNetworkAccessManager *manager;

    //The amount of seconds left until the next update
    int time;

private slots:
    //The method to call when a reply to the api request is received
    void replyFinished(QNetworkReply*);
};

#endif // MODEL_H
