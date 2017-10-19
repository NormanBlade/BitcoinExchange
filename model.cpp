#include "Model.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#define COUNT_DOWN 10

Model::Model() : QObject(){
    this->time = COUNT_DOWN;
    this->manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
}

void Model::exchangeValueRequest(){
    emit sendingRequest();
    manager -> get(QNetworkRequest(QUrl("https://www.bitstamp.net/api/v2/ticker/btceur/")));
}

void Model::replyFinished(QNetworkReply* reply){
    QString data;

    if (reply->error() == QNetworkReply::NoError){
        data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
        QJsonObject obj = doc.object();
        QJsonValue val = obj.take("last");
        if (val == QJsonValue::Undefined)
            data = "Request not valid. Trying again in 10 sec.";
        else
            data = val.toString();
    }
    else
        data = "Connetion Error. Trying again in 10 sec.";

    reply->deleteLater();
    emit lastValueUpdate(data);
}

void Model::stepTimer(){
    if(time == 1){
        exchangeValueRequest();
        time = COUNT_DOWN;
    }
    else{
        time--;
        emit secondsLeft(time);
    }
}
