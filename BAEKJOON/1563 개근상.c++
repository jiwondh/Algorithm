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

#define O 0
#define L 1
#define A 2

int N;	// 한 학기 일수
int check[3][1000][3][4];

int CheckAttend(int c, int days, int late, int absence) {

	if (c == O) {
		absence = 0;
	}
	if (c == L) {
		late++;
		absence = 0;
	}
	if (c == A) {
		absence++;
	}
	if (late == 2 || absence == 3)
		return 0;
	if (days == N - 1)
		return 1;
	int & thisday = check[c][days][late][absence];

	if (thisday != -1) {
		return thisday;
	}
	thisday = (CheckAttend(O, days + 1, late, absence)
			+ CheckAttend(L, days + 1, late, absence)
			+ CheckAttend(A, days + 1, late, absence)) % 1000000;
	return thisday;
}
int main() {

	cin >> N;
	memset(check, -1, sizeof(check));

	cout
			<< (CheckAttend(O, 0, 0, 0) + CheckAttend(L, 0, 0, 0)
					+ CheckAttend(A, 0, 0, 0)) % 1000000;

	return 0;
}
