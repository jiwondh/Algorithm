#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>
#include <bitset>

using namespace std;

//4 6
//101111
//101010
//101011
//111011

int N, M;
int bfs(vector<vector<int> >&adj, pair<int, int> start) {
	vector<vector<int> > discovered(N, vector<int>(M, -1));
	queue<pair<int, int> > q;
	vector<pair<int, int> > order;
	discovered[start.first][start.second] = true;
	q.push(start);
	while (!q.empty()) {
		//(y, x)
		pair<int, int> here = q.front();
		int x = here.second;
		int y = here.first;

		q.pop();
		order.push_back(here);

		//오른쪽
		if (x != M - 1) {
			pair<int, int> there = make_pair(y, x + 1);
			int road = adj[y][x + 1];
			if (road && discovered[y][x + 1]==-1) {
				q.push(there);
				discovered[y][x + 1] = discovered[y][x]+1;
			}
		}
		//왼쪽
		if (x != 0) {
			pair<int, int> there = make_pair(y, x - 1);
			int road = adj[y][x - 1];
			if (road && discovered[y][x - 1]==-1) {
				q.push(there);
				discovered[y][x - 1] =  discovered[y][x]+1;
			}
		}
		//위쪽
		if (y != 0) {
			pair<int, int> there = make_pair(y - 1, x);
			int road = adj[y - 1][x];
			if (road && discovered[y - 1][x]==-1) {
				q.push(there);
				discovered[y - 1][x] =  discovered[y][x]+1;
			}
		}
		//아래
		if (y != N - 1) {
			pair<int, int> there = make_pair(y + 1, x);
			int road = adj[y + 1][x];
			if (road && discovered[y + 1][x]==-1) {
				q.push(there);
				discovered[y + 1][x] =  discovered[y][x]+1;
			}
		}
	}
	return discovered[N-1][M-1];
}

int main() {
	cin >> N >> M;

	vector<vector<int> > maze(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		char str[M + 1];
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == '1')
				maze[i][j] = 1;
			else
				maze[i][j] = 0;
		}
	}
	cout<<bfs(maze, make_pair(0, 0));
	return 0;
}
