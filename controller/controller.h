#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QWidget>
#include <game2048.h>
#include <model.h>
#include <QMessageBox>
class Game2048;
class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void move(int);
    void Reset();
    Game2048 *view;
    Model *model;
signals:


};

#endif // CONTROLLER_H
