//
// Created by Jae Liu on 2018/11/28 0028.
//

#include <iostream>
using namespace std;
void AddEdge(int Array[1000][1000]){
    int st,ed,dis,judge;
    do{
        cout<<"请输入起点路由：  终点路由：  距离：  "<<endl;
        cin>>st>>ed>>dis;
        Array[st][ed]=dis;
        Array[ed][st]=dis;
        cout<<"是否继续增加边？"<<endl;
        cout<<"1.是     2.否"<<endl;
        cin>>judge;
    }while(judge==1);
}
//
void DelEdge(int Array[1000][1000]){
    int st,ed,judge;
    do{
        cout<<"请输入起点路由：  终点路由："<<endl;
        cin>>st>>ed;
        Array[st][ed]=1000;
        Array[ed][st]=1000;
        cout<<"是否删除增加边？"<<endl;
        cout<<"1.是     2.否"<<endl;
        cin>>judge;
    }while(judge==1);
}