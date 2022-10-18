#include <iostream>
#include <ctime>
#include "ArrayGraphic.h"
using namespace std;
int main() {//a=3 b=6
    srand((unsigned)time(NULL));
    int number1 =(rand() % (6-3))+ 3;
    ArrayGraphic arrayGraphic(number1);
    for(int j=0;j<number1;j++)
    {
        int number2 = (rand() % (6-3))+ 3;
        int **grp = new int*[number2];
        for(int i=0;i<number2;i++)
        {
            grp[i]= new int [2];
            int x =(rand() % (10-1))+ 1;
            int y = (rand() % (10-1))+ 1;
            grp[i][0]=x;
            grp[i][1]=y;
            delete[] grp[i];
        }
        arrayGraphic.addgraphic(j,grp);
        delete[] grp;
    }
    for(int i=0;i<number1;i++)
    {
        int **getingo = arrayGraphic.showxy(i);
        int z = sizeof (getingo)/sizeof (getingo[0]);
        for(int j=0;j<sizeof (getingo)/sizeof (getingo[0]);j++)
        {
            int t1 = getingo[j][0];
            int t2 = getingo[j][1];
            int t3= 0;
            cout<<'['+getingo[j][0]+'  '+getingo[j][1]+']'+' '<<endl;
        }

    }

    return 0;
}
