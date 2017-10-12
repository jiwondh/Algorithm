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

int Dif(int cri, int n) {
	if (cri >= n)
		return cri - n;
	else
		return cri + 1;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> card(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	int min = M + 1;
	int result;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int temp = card[i] + card[j] + card[k];
				int dif = Dif(M, temp);
				if (min > dif) {
					min = dif;
					result = temp;
				}
			}
		}
	}
	cout << result;
	return 0;
}
