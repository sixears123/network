#include <iostream>
#include <fstream>
#define MAX 100
#define max_value 1000
using namespace std;
void Floyd(int Array[MAX][MAX],int RouteNum,int cost[MAX][MAX],int NextRoute[MAX][MAX]){
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
void output(int RouteNum,int cost[MAX][MAX],int NextRoute[MAX][MAX]){
    ofstream file;
    file.open("Route.txt");
  /*  for (int i = 1; i <RouteNum+1 ; ++i) {
        file<<"第"<<i<<"个路由表"<<"\r"<<"\n";
        file<<"目的"<<"距离"<<"下一跳"<<"\r"<<"\n";
        for (int j = 1; j <RouteNum+1; ++j) {
            if(i!=j){
                file<<j<<"   "<<cost[i][j]<<"    "<<NextRoute[i][j]<<"\r"<<"\n";
            }
        }
    }*/
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
int input(int Array[MAX][MAX]){
    ifstream file;
    int RouteNum,m,x,y,z;
    file.open("db.txt");
    file >> RouteNum >> m;
    for (int i = 1; i <= RouteNum; ++i) {
        for (int j = 1; j <= RouteNum; ++j) {
            Array[i][j] =max_value;
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
int AddRoute(int Array[MAX][MAX],int RouteNum){
    int n,j,Dis;
    RouteNum=RouteNum+1;
    for (int i = 1; i <=RouteNum ; ++i) {
        Array[RouteNum][i]=max_value;
        Array[i][RouteNum]=max_value;
    }
    Array[RouteNum][RouteNum]=0;
    cin>>n;
    while(n--){
        cin>>j>>Dis;
        Array[RouteNum][j]=Dis;
        Array[j][RouteNum]=Dis;
    }
    return RouteNum;
}
int DelRoute(int Array[MAX][MAX],int RouteNum,int code){
    for (int i = code; i <RouteNum ; ++i) {
        for (int j = 1; j <=RouteNum ; ++j) {
            Array[i][j]=Array[i+1][j];
        }
    }
    for (int j = code; j <RouteNum ; ++j) {
        for (int i = 1; i <=RouteNum ; ++i) {
            Array[i][j]=Array[i][j+1];
        }
    }
    return RouteNum-1;
}

int main(){
    int Array[MAX][MAX],cost[MAX][MAX],NextRoute[MAX][MAX],RouteNum;
    RouteNum=input(Array);
    Floyd(Array,RouteNum,cost,NextRoute);
    output(RouteNum,cost,NextRoute);
    return 0;
}