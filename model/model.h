#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QTime>
#include <QtGlobal>
#include <QRandomGenerator>
#include <QMessageBox>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);
    int grid[16];
    int score;
    int* Random();
    void Reset();
    bool move(int);
    bool change(int k,int f);
    bool check();
signals:

};

#endif // MODEL_H
