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

int Answer;

int main() {
	int T, test_case;

	cin >> T;

	for (test_case = 0; test_case < T; test_case++) {

		Answer = 0;

		int N;
		cin >> N;

		vector<int> num;
		map<int, int> m;
		pair<map<int, int>::iterator, bool> pr;

		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			Answer = Answer ^ temp;
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
