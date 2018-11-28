//
// Created by Jae Liu on 2018/11/28 0028.
//

#include "Route.h"
#include <iostream>
using namespace std;
int AddRoute(int Array[1000][1000],int RouteNum){
    int n,j,Dis;
    RouteNum=RouteNum+1;
    for (int i = 1; i <=RouteNum ; ++i) {
        Array[RouteNum][i]=1000;
        Array[i][RouteNum]=1000;
    }
    Array[RouteNum][RouteNum]=0;
    cout<<"请输入增加路径数："<<endl;
    cin>>n;
    while(n--){
        cout<<"终点路由：    距离："<<endl;
        cin>>j>>Dis;
        Array[RouteNum][j]=Dis;
        Array[j][RouteNum]=Dis;
    }
    return RouteNum;
}
int DelRoute(int Array[1000][1000],int RouteNum){
    int code;
    cout<<"输入删除路由器："<<endl;
    cin>>code;
    for (int i = 1; i <=RouteNum ; ++i) {
        Array[i][code]=1000;
        Array[code][i]=1000;
    }
    return RouteNum-1;
}