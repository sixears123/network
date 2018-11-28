#include<iostream>
#include<algorithm>
using namespace std;
const int maxint = 10000000;
const int maxn = 1000;
int x, y, z;
int dis[maxn][maxn]; //表示两个点之间的距离
int n, m;
int next_[maxn][maxn]; //表示i到j的下一跳
void floyd() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			next_[i][j] = j;
		}
	}//
	for (int k = 1; k <= n; ++k) {   //枚举中间点k
		for (int i = 1; i <= n; ++i) {   //枚举端点i
			for (int j = 1; j <= n; ++j) {   //枚举端点j
				if (dis[i][j] > (dis[i][k] + dis[k][j])) {
					dis[i][j] = dis[i][k] + dis[k][j];
					next_[i][j] = next_[i][k];
				}
			}
		}
	}
}
int main() {
	while (cin >> n >> m && n&&m) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dis[i][j] = maxint;
			}
		}
		for (int i = 1; i <= n; ++i) dis[i][i] = 0;
		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> z;
			dis[x][y] = dis[y][x] = z;
		}
		floyd();
		for (int i = 1; i <= n; ++i) {
			cout << "**********************************" << endl;
			cout << "***     路由器" << i << "的路由表        ***" << endl;
			cout << "***  目的     距离     下一跳  ***" << endl;
			for (int j = 1; j <= n; ++j) {
				if (j != i) cout<<"*     "<< j << "        " << dis[i][j] << "          " << next_[i][j] <<"      *"<< endl;
			}
			cout << "**********************************" << endl;
			cout << endl;
		}
	}
	return 0;
}


/*
9 16
1 2 2
1 6 1
1 7 1
2 3 2
2 4 4
3 4 1
3 6 3
3 7 2
4 5 1
4 7 6
4 8 5
4 9 2
5 6 5
6 7 1
7 8 3
8 9 2
*/