//
// Created by Jae Liu on 2018/11/28 0028.
//

#include "File.h"
#include <fstream>
#include <iostream>
using namespace std;
void output(int RouteNum,int cost[1000][1000],int NextRoute[1000][1000]){
    ofstream file;
    file.open("Route.txt");
    for (int i = 1; i <= RouteNum+1; ++i) {
        file << "**********************************" <<"\r"<<"\n";
        file << "***     路由器" << i << "的路由表        ***" <<"\r"<<"\n";
        file << "***  目的     距离     下一跳  ***" <<"\r"<<"\n";
        for (int j = 1; j <= RouteNum+1; ++j) {
            if (j != i) file<<"*     "<< j << "        " << cost[i][j] << "          " << NextRoute[i][j] <<"      *"<<"\r"<<"\n";
        }
        file << "**********************************" <<"\r"<<"\n";
        file <<"\r"<<"\n";
    }
    file.close();
}
int input(int Array[1000][1000]){
    ifstream file;
    int RouteNum,m,x,y,z;
    file.open("db.txt");
    file >> RouteNum >> m;
    for (int i = 1; i <= RouteNum; ++i) {
        for (int j = 1; j <= RouteNum; ++j) {
            Array[i][j] =1000;
        }
    }
    for (int i = 1; i <= RouteNum; ++i) Array[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        file >> x >> y >> z;
        Array[x][y] = Array[y][x] = z;
    }
    file.close();
    return RouteNum;
}
void Del(int p[1000][1000]){
    for(int   i=0;   i<1000;   ++i)
        delete[] p;
}