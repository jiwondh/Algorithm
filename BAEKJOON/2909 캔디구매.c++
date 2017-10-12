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
	long long C;
	int K;
	cin >> C;
	cin >> K;

	double num = (double) C;

	for (int i = 0; i < K; i++) {
		num = num / 10;
	}
	num = round(num);
	for (int i = 0; i < K; i++) {
		num = num * 10;
	}
	cout << (int)num;
	return 0;
}
