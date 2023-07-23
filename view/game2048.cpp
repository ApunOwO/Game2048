#include "game2048.h"
#include "ui_game2048.h"

Game2048::Game2048(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Game2048)
{
    this->setFixedSize(400, 500);
    QGridLayout *Glayout = new QGridLayout(this);
    QLabel* scorel = new QLabel();
    QFont font;
    font.setPointSize(14);
    this->setFont(font);
    scorel->setText("Score:");
    score = new QLabel("0");
    restart = new QPushButton("Restart");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            grid[i][j]=new QLabel("");
            grid[i][j]->setFixedSize(75,75);
            grid[i][j]->setStyleSheet("background:rgb(255,223,125)");
            grid[i][j]->setFont(font);
            grid[i][j]->setAlignment(Qt::AlignCenter);
            Glayout->addWidget(grid[i][j],i+1,j,1,1);
        }
    }
    Glayout->addWidget(scorel,0,0,1,1);
    Glayout->addWidget(score,0,1,1,1);
    Glayout->addWidget(restart,0,3,1,2);
    this->setFocusPolicy(Qt::StrongFocus);
}

void Game2048::setupNumber(int* s){
    for (int i = 0; i <4; i++){
        for (int j = 0; j < 4; j++){
            int* x = s+i*4+j;
            if (*x==0) grid[i][j]->setText("");
            else grid[i][j]->setText(QString::number(*x));
        }
    }
}

void Game2048::keyPressEvent(QKeyEvent *event){
    int f = 0;
    qDebug()<<"press\n";
    if (event->key()==Qt::Key_Left){
        f = 2;
        qDebug()<<"left\n";
    }
    if (event->key()==Qt::Key_Right){
        f = 4;
        qDebug()<<"Key_Right\n";
    }
    if (event->key()==Qt::Key_Up){
        f = 1;
        qDebug()<<"Key_Up\n";
    }
    if (event->key()==Qt::Key_Down){
        f = 3;
        qDebug()<<"Key_Down\n";
    }
    c->move(f);
}

void Game2048::setScore(int s){
    score->setText(QString::number(s));
}

void Game2048::setController(Controller *c){
    this->c = c;
    connect(restart,&QPushButton::clicked,c,&Controller::Reset);
}

Game2048::~Game2048()
{
    delete ui;
}

