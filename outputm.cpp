//
// Created by Jae Liu on 2018/12/3 0003.
//

#include "outputm.h"
void outputm(int RouteNum,int cost[1000][1000],int NextRoute[1000][1000],int m){
        cout << "**********************************" <<endl;
        cout << "***     路由器" << m << "的路由表        ***" <<endl;
        cout << "***  目的     距离     下一跳  ***" <<endl;
        for (int j = 1; j <= RouteNum; ++j) {
            if (j != m) cout<<"       "<< j << "        " << cost[m][j] << "          " << NextRoute[m][j] <<"       "<<endl;
        }
        cout << "**********************************" <<endl;
        cout <<endl;
}