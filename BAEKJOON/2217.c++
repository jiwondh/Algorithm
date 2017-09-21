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
	int N;
	cin >> N;

	vector<int> rope(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end());

	int minRope = rope[N-1];
	int maxWeight = rope[N-1];

	for(int i=N-2; i>=0; i--){
		minRope = rope[i];
		if(maxWeight<minRope*(N-i)){
			maxWeight = minRope*(N-i);
		}
	}
	cout<<maxWeight;
	return 0;
}
