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
	int N, M;
	cin >> N >> M;

	map<string, int> name;

	for (int i = 0; i < N; i++) {
		string tempName;
		cin >> tempName;
		name.insert(pair<string, int>(tempName, 1));
	}
	for (int i = 0; i < M; i++) {
		string tempName;
		cin >> tempName;
		name[tempName]++;
	}
	map<string, int>::iterator iter;
	vector<string> result;

	for (iter = name.begin(); iter != name.end(); ++iter) {
		if ((*iter).second == 2)
			result.push_back((*iter).first);
	}
	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

}
