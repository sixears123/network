//
// Created by Jae Liu on 2018/11/28 0028.
//

#include "Floyd.h"
#include <iostream>
using namespace std;
void Floyd(int Array[1000][1000],int RouteNum,int cost[1000][1000],int NextRoute[1000][1000]){
    for (int i = 1; i <RouteNum+1 ; ++i) {
        for (int j = 1; j <RouteNum+1 ; ++j) {
            cost[i][j]=Array[i][j];
            NextRoute[i][j]=j;
        }
    }
    for (int k = 1; k <RouteNum+1 ; ++k) {
        for (int i = 1; i<RouteNum+1 ; ++i) {
            for (int j = 1; j <RouteNum+1 ; ++j) {
                if(cost[i][j]>(cost[i][k]+cost[k][j])){
                    cost[i][j]=cost[i][k]+cost[k][j];
                    NextRoute[i][j]=NextRoute[i][k];
                }
            }
        }
    }
}