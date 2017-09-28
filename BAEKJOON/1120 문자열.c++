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
	string A, B;
	cin >> A >> B;

	vector<int> dif;

	for (int i = 0; i <= B.length() - A.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < A.length(); j++) {
			if (A[j] != B[j + i])
				cnt++;
		}
		dif.push_back(cnt);
	}
	sort(dif.begin(), dif.end());

	cout << dif[0];

	return 0;
}
