#ifndef GAME2048_H
#define GAME2048_H

#include <QMainWindow>
#include <QGridLayout>
#include <QVBoxlayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>
#include <QPushButton>
#include <controller.h>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Game2048; }
QT_END_NAMESPACE
class Controller;
class Game2048 : public QWidget
{
    Q_OBJECT

public:
    Game2048(QWidget *parent = nullptr);
    void setController(Controller*);
    void setupNumber(int* s);
    void setScore(int s);
    ~Game2048();
    QLabel* grid[4][4];
    QLabel* score;
    QPushButton* restart;
    Controller *c;
private:
    void keyPressEvent(QKeyEvent *event);
    Ui::Game2048 *ui;
};
#endif // GAME2048_H
