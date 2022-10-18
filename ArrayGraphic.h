//
// Created by com12 on 2022/10/17.
//
//mitsuha1@outlook.com
#ifndef Z4_ARRAYGRAPHIC_H
#define Z4_ARRAYGRAPHIC_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Graphic.h"
class ArrayGraphic:public Graphic
{
protected:
    int more;

public:
    int ***massivgra;
    explicit ArrayGraphic(int number)//指示形状数量
    {
        this->z=number;
        this->massivgra = new int**[number];
    }
    ~ArrayGraphic()
    {
        for(int i=0;i<sizeof(this->massivgra)/sizeof(this->massivgra[0]);i++)
        {
            for(int j=0;j<sizeof(this->massivgra[i])/sizeof(this->massivgra[i][0]);j++)
                delete[] massivgra[i][j];
            delete[] massivgra[i];
        }
        delete[] massivgra;
    }
    void addgraphic(int index,int **mas,int number2) override//添加图形(你可以说覆盖图形）
    {
        y[index] = number2;
        massivgra[index]= mas;
    }
    void addgraphic(int **mas) override//添加图形
    {
        for(int i=0;i<sizeof(massivgra);i++)
        {
            if(massivgra[i]== nullptr)
            {
                massivgra[i]==mas;
                break;
            }
        }
    }
    void movegraphic(int index,bool *wasd[],int *number[]) override//移动数组
    {
        for(int i=0;i<sizeof(*wasd)/sizeof(*wasd[0]);i++)
        {
            if(*wasd[i])
                for(int j=0;j<sizeof(*number)/sizeof(*number[0]);j++)
                    massivgra[index][i][0]=*(massivgra[index][i][0]+number[i]);
            else if(!*wasd[i])
                for(int j=0;j<sizeof(*number)/sizeof(*number[0]);j++)
                    massivgra[index][i][1]=*(massivgra[index][i][1]+number[i]);
        }
    }
    void bigsmall(int number) override//对图形的放大
    {
        for(int i=0;i<sizeof(macciv)/sizeof(macciv[0]);i++)
            for(int j=0;j<2;j++)
            {
                if(number>0)
                    macciv[i][j] *= abs(number);
                else if(number<0)
                    macciv[i][j] /= abs(number);
            }
    }
    int **showxy(int index) override//对图形的坐标的显示
    {
        return massivgra[index];
    }
    /*int []showxyy(int index,int index1)
    {
        int massivgra[index]
    }*/
    int * area(int index) override//对图形区域的显示
    {
        int *x[gragol];
        int *y[gragol];
        for(int i=0;i<gragol;i++)
        {
            *x[i] = massivgra[index][i][0];
            *y[i] = massivgra[index][i][1];
        }
        int *xyai[4];

        int tmp =0;
        for(int i = 1; i < gragol; i++) {
            if( x[i] < x[i+1] )
            {
                tmp =*x[i];
                x[i] = x[i+1];
                *x[i+1] = tmp;
            }
            if( y[i] < y[i+1] )
            {
                tmp =*y[i];
                y[i] = y[i+1];
                *y[i+1] = tmp;
            }
        }
        xyai[0] = x[0];
        xyai[1] = x[gragol-1];
        xyai[2] = y[0];
        xyai[3] = y[gragol-1];
        return *xyai;
    }
};
#endif //Z4_ARRAYGRAPHIC_H
