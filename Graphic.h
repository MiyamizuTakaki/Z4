//
// Created by com12 on 2022/10/14.
//

#ifndef Z4_GRAPHIC_H
#define Z4_GRAPHIC_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
class Graphic {
protected:
    int gragol;

    int center =0;
    int **macciv;
public:
    int x=2;
    int *y = new int[z];
    int z;
    /*explicit Graphic(int number){
        this->gragol=number;
        this->macciv = new int*[gragol];
        for(int i=0;i<gragol;i++)
            macciv[i] = new int[2];
    }*/


    /*~Graphic()
    {
        for(int i=0;i<2;i++)
            delete[] macciv[i];
        delete[] macciv;
    }*/
    virtual void addgraphic(int index,int **mas,int number2)=0;
    virtual void addgraphic(int **mas)=0;
    virtual void movegraphic(int index,bool *wasd[],int *number[]) = 0;
    virtual void bigsmall(int number) = 0;
    virtual int **showxy(int index) = 0;
    virtual int * area(int index) = 0;
};


#endif //Z4_GRAPHIC_H
