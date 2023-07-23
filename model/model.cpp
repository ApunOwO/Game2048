#include "model.h"

Model::Model(QObject *parent)
    : QObject{parent}
{
    memset(grid,0,sizeof(grid));
    score=0;
}

void Model::Reset(){
    memset(grid,0,sizeof(grid));
    score = 0;
}

int* Model::Random(){
    int cnt = 2;
    int cnt2 = 10;
    while (cnt&&cnt2){
        int randx = QRandomGenerator::global()->bounded(4);
        int randy = QRandomGenerator::global()->bounded(4);
        int*x = grid+randx*4+randy;
        if (*x==0){
            cnt--;
            int rand = QRandomGenerator::global()->bounded(10);
            if (rand>8) *x=4;
            else *x=2;
        }
        cnt2--;
    }
    if (cnt==2){
        for (int i = 0; i < 15; i++){
            if (*(grid+i)==0) {*(grid+i)= QRandomGenerator::global()->bounded(10)>8 ? 4:2;break;}
        }
    }
    return grid;
}

bool Model::move(int f){
    if (f==1) return this->change(4,1);
    if (f==2) return this->change(1,1);
    if (f==3) return this->change(4,-1);
    if (f==4) return this->change(1,-1);
}

bool Model::change(int k, int f){
    int *c= new int[16];
    int *v= new int[16];
    memset(c,0,16*sizeof(int));
    memset(v,0,16*sizeof(int));
    int s = 0;
    if (f==1) s = 0;
    else s = 15;
    int si;
    if (k==1) si = 4;
    else si = 1;
    bool changeflag=false;
    for (int i = 0; i < 4; i++){
        int j = s+i*si*f;
        int p = j;
        for (int l = 0; l < 4; l++){
            if (*(grid+j)!=0) {
                int x = p-k*f;
                if (l!=0){
                    if (*(c+x)==*(grid+j)&&*(v+x)==0) {
                        *(c+x)=2*(*(grid+j));
                        this->score+=*(grid+j);
                        *(v+x)=1;
                        j+=k*f;
                        changeflag=true;
                        continue;
                    }
                }
                *(c+p)=*(grid+j);
                if (p!=j) changeflag=true;
                p+=k*f;
            }
            j+=k*f;
        }
    }
    for (int i = 0; i < 16; i++){
        grid[i]=c[i];
    }
    delete[] c;
    delete[] v;
    return changeflag;
}

bool Model::check(){
    int p = 0;
    int pp = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            int x = *(grid+i*4+j);
            if (x==0) {p=1;break;}
            if (j-1>=0&&*(grid+i*4+j-1)==x||j+1<=3&&*(grid+i*4+j+1)==x||i-1>=0&&*(grid+(i-1)*4+j)==x||i+1<4&&*(grid+(i+1)*4+j)==x){pp=1;break;}
        }

    }
    if (p==0&&pp==0) return false;
    else return true;
}
