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
    for (int i = 1; i <= RouteNum; ++i) {
        file << "**********************************" <<"\r"<<"\n";
        file << "***     路由器" << i << "的路由表        ***" <<"\r"<<"\n";
        file << "***  目的     距离     下一跳  ***" <<"\r"<<"\n";
        for (int j = 1; j <= RouteNum; ++j) {
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
    cout<<"输入增加边数："<<endl;
    cin>>n;
    while(n--){
        cout<<"输入终点路由：    距离："<<endl;
        cin>>j>>Dis;
        Array[RouteNum][j]=Dis;
        Array[j][RouteNum]=Dis;
    }
    return RouteNum;
}
int DelRoute(int Array[MAX][MAX],int RouteNum){
    int code;
    cout<<"输入删除路由器："<<endl;
    cin>>code;
    for (int i = 1; i <=RouteNum ; ++i) {
        Array[i][code]=max_value;
        Array[code][i]=max_value;
    }
    return RouteNum-1;
}
void AddEdge(int Array[MAX][MAX]){
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
void DelEdge(int Array[MAX][MAX]){
    int st,ed,judge;
    do{
        cout<<"请输入起点路由：  终点路由："<<endl;
        cin>>st>>ed;
        Array[st][ed]=max_value;
        Array[ed][st]=max_value;
        cout<<"是否删除增加边？"<<endl;
        cout<<"1.是     2.否"<<endl;
        cin>>judge;
    }while(judge==1);
}
int main(){
    int Array[MAX][MAX],cost[MAX][MAX],NextRoute[MAX][MAX],RouteNum,num;
    RouteNum=input(Array);
    Floyd(Array,RouteNum,cost,NextRoute);
    output(RouteNum,cost,NextRoute);
    cout << "             *****欢迎使用路由表生成算法及其他功能*****" << endl;
    cout << "             ******请输入对应的数字执行相应的功能******" << endl;
    while (true) {
        cout << "          *************************************************" << endl;
        cout << "          *                   菜      单                  *" << endl;
        cout << "          *************************************************" << endl;
        cout << "          *************************************************" << endl;
        /*cout << "          *       1.将网络拓扑图存入文件                  *" << endl;
        cout << "          *       2.路由表生成算法                        *" << endl;*/
        cout << "          *       1.增加一个路由器，并重新生成路由表      *" << endl;
        cout << "          *       2.删除一个路由器，并重新生成路由表      *" << endl;
        cout << "          *       3.增加若干条边，并重新生成路由表        *" << endl;
        cout << "          *       4.删除若干条边，并重新生成路由表        *" << endl;
        cout << "          *       5.退出        *" << endl;
        cout << "          *************************************************" << endl << endl;
        cout << "请输入相应的数字，执行相应的操作:";
        cin >> num;
        switch (num) {
            case 1:{RouteNum=AddRoute(Array,RouteNum);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            case 2:{RouteNum=DelRoute(Array,RouteNum);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            case 3:{AddEdge(Array);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            case 4:{DelEdge(Array);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            default:exit(0);
                break;
        }
        cout << endl;
    }
}