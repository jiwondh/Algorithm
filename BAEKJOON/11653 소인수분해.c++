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

	int N;
	cin >> N;

	int primeFactor = 2;
	while (N != 1) {
		while (N % primeFactor == 0) {
			cout << primeFactor << endl;
			N = N / primeFactor;
		}
		primeFactor++;
	}

	return 0;
}
