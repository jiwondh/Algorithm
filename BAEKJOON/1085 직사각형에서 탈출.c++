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

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int shortestX = x < (w - x) ? x : (w - x);
	int shortestY = y < (h - y) ? y : (h - y);
	int result = shortestX < shortestY ? shortestX : shortestY;

	cout << result;

	return 0;
}
