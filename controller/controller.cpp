#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject{parent}
{
    view = new Game2048();
    model = new Model();
    view->setupNumber(model->Random());
    view->setController(this);
    view->show();
}

void Controller::move(int f){
    bool c = model->move(f);
    qDebug()<<"move s";
    if (c) {model->Random();
    qDebug()<<"ran s";}
    view->setupNumber(model->grid);
    qDebug()<<"set s";
    view->setScore(model->score);
    qDebug()<<"sets s";
    if (!model->check()) {
        QMessageBox::warning(view, tr("Result"),tr("GameOver"),QMessageBox::Close);
        Reset();
    }
}

void Controller::Reset(){
    model->Reset();
    model->Random();
    view->setupNumber(model->grid);
    view->setScore(model->score);
}
