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

int BFS(int N, int K) {
	vector<int> distance(100001, -1);
	queue<int> q;
	distance[N] = 0;
	q.push(N);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == K)
			return distance[here];

		//here-1
		if (here != 0) {
			int there = here - 1;
			if (distance[there] == -1) {
				q.push(there);
				distance[there] = distance[here] + 1;
			}
		}
		//here+1
		if (here != 100000) {
			int there = here + 1;
			if (distance[there] == -1) {
				q.push(there);
				distance[there] = distance[here] + 1;
			}
		}
		//here*2
		if (here < 50000) {
			int there = here * 2;
			if (distance[there] == -1) {
				q.push(there);
				distance[there] = distance[here] + 1;
			}
		}

	}
	return -1;
}
int main() {
	int N, K;
	cin >> N >> K;

	cout << BFS(N, K);
	return 0;
}
