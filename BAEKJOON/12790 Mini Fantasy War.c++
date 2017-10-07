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
	for (int j = 0; j < N; j++) {
		vector<int> power(4, 0);
		for (int i = 0; i < 4; i++) {
			cin >> power[i];
		}
		for (int i = 0; i < 4; i++) {
			int temp;
			cin >> temp;
			power[i] = power[i] + temp;
		}
		if(power[0]<1) power[0]=1;
		if(power[1]<1) power[1]=1;
		if(power[2]<0) power[2]=0
				;
		cout << 1 * power[0] + 5 * power[1] + 2 * power[2] + 2 * power[3]
				<< endl;
	}

	return 0;
}
