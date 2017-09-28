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
#include <unordered_map>
#include <bitset>

using namespace std;

int main() {
	int N, S;
	cin >> N >> S;

	vector<int> num(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int cnt = 0;

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				sum = sum + num[j];
			}
		}
		if (sum == S)
			cnt++;
	}
	cout << cnt;
}
