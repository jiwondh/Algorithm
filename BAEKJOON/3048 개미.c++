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

int main() {
	int N1, N2;
	cin >> N1 >> N2;

	string S1, S2;
	cin >> S1 >> S2;

	int T;
	cin >> T;

	vector<pair<char, int> > G(N1 + N2);

	for (int i = 0; i < N1; i++) {
		G[N1 - 1 - i].first = S1[i];
		G[N1 - 1 - i].second = 0;
	}
	for (int i = 0; i < N2; i++) {
		G[N1 + i].first = S2[i];
		G[N1 + i].second = 1;
	}

	while (T > 0) {
		T--;
		for (int i = 0; i < G.size() - 1; i++) {
			if (G[i].second == 0 && G[i + 1].second == 1) {
				pair<int, int> temp = G[i];
				G[i] = G[i + 1];
				G[i + 1] = temp;
				i++;
			}
		}
	}

	for (int i = 0; i < G.size(); i++) {
		cout << G[i].first;
	}
	return 0;
}
