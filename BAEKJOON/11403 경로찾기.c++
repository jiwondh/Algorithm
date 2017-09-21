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

using namespace std;

vector<bool> bfs(vector<vector<int> >& adj, int start) {
	vector<bool> discovered(adj.size(), false);
	queue<int> q;
	vector<int> order;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		order.push_back(here);
		for (int i = 0; i < adj[here].size(); i++) {
			if (adj[here][i] == 1) {
				int there = i;
				if (discovered[there] != true)
					q.push(there);
				discovered[there] = true;
			}
		}
	}
	return discovered;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int> > adj(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		vector<bool> result = bfs(adj, i);
		for (int j = 0; j < N; j++) {
			if (result[j] == true)
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}

	return 0;
}
