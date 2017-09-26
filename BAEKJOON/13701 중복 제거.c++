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
	map<int, int> m;
	pair<map<int, int>::iterator, bool> pr;

	int n;
	bitset<1 << 25> bit;

	do {
		scanf("%d", &n);
		if (!bit.test(n - 1)) {
			cout << n << " ";
			bit.flip(n - 1);
		}
	} while (getc(stdin) == ' ');

	return 0;

}
