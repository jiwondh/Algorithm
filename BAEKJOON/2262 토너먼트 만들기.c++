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

int N;

int Dif(int a, int b) {
	if (a > b)
		return a - b;
	else
		return b - a;
}
int Small(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int DP(vector<int>& people) {

	vector<int> temp;
	int difSum = 0;

	for (int i = 0; i < people.size(); i++) {
		if ((people[i] < people[i + 1]) || (i == people.size() - 1)) {
			temp.push_back(people[i]);
		} else {
			if (people[i] > people[i - 1]) {
				int difSum1 = Dif(people[i], people[i + 1]);
				int difSum2 = Dif(people[i], people[i - 1]);
				if (difSum1 < difSum2) {
					difSum = difSum + difSum1;
					temp.push_back(Small(people[i], people[i + 1]));
					for (int j = i + 2; j < people.size(); j++) {
						temp.push_back(people[j]);
					}
				} else {
					difSum = difSum + difSum2;
					for (int j = i + 1; j < people.size(); j++) {
						temp.push_back(people[j]);
					}
				}
			} else {
				difSum = difSum + Dif(people[i], people[i + 1]);
				temp.push_back(Small(people[i], people[i + 1]));
				for (int j = i + 2; j < people.size(); j++) {
					temp.push_back(people[j]);
				}
			}
			break;
		}
	}

	if (temp.size() == 1)
		return difSum;

	if (people.size() != temp.size()) {
		difSum = difSum + DP(temp);
	} else {
		vector<int> anotherTemp;
		for (int i = people.size() - 1; i >= 0; i--) {
			if (i == people.size() - 1) {
				difSum = difSum + Dif(people[i], people[i - 1]);
				anotherTemp.insert(anotherTemp.begin(),
						Small(people[i], people[i - 1]));
				i--;
			} else {
				anotherTemp.insert(anotherTemp.begin(), people[i]);
			}
		}
		if (anotherTemp.size() == 1) {
			return difSum;
		} else {
			difSum = difSum + DP(anotherTemp);
		}
	}
	return difSum;
}
int main() {
	cin >> N;

	vector<int> people(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}

	cout << DP(people);

	return 0;
}
