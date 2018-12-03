#include <iostream>
#include <fstream>
#include "File.h"
#include "Floyd.h"
#include "Route.h"
#include "Edge.h"
using namespace std;
//int Array[1000][1000],cost[1000][1000],NextRoute[1000][1000];
int main() {
    int (*Array)[1000]=new int[1000][1000],(*cost)[1000]=new int[1000][1000],(*NextRoute)[1000]=new int[1000][1000];
    int RouteNum, num;
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
        cout << "          *       1.增加一个路由器，并重新生成路由表        *" << endl;
        cout << "          *       2.删除一个路由器，并重新生成路由表        *" << endl;
        cout << "          *       3.增加若干条边，并重新生成路由表          *" << endl;
        cout << "          *       4.删除若干条边，并重新生成路由表          *" << endl;
        cout << "          *       5.退出                                  *" << endl;
        cout << "          *************************************************" << endl << endl;
        cout << "请输入相应的数字，执行相应的操作:";
        cin >> num;
        switch (num) {
            case 1:{RouteNum=AddRoute(Array,RouteNum);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            case 2:{RouteNum=DelRoute(Array,RouteNum);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            case 3:{AddEdge(Array);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            case 4:{DelEdge(Array);Floyd(Array,RouteNum,cost,NextRoute);output(RouteNum,cost,NextRoute);};break;
            default:{Del(Array);Del(cost);Del(NextRoute);exit(0);};
        }
        cout << endl;
    }
}
