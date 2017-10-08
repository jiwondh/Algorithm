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

int GCD(int a, int b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main() {
	int N, M;
	cin >> N >> M;

	int totalCut = 0;

	int gcd = GCD(N, M);
	int LCM = N * M / gcd;	//최소공배수

	//전체를 LCM 조각이라고 했을 때
	int piecePerSausage = LCM / N;
	int piecePerReviewer = LCM / M;

	while (1) {

		int cut = 0, remainder = -1, eatPeople = 0;

		if (piecePerSausage < piecePerReviewer) {
			piecePerReviewer = piecePerReviewer - piecePerSausage;
			N = N - M;
			continue;
		} else {
			eatPeople = cut = (piecePerSausage / piecePerReviewer) * N;
			remainder = piecePerSausage % piecePerReviewer;
			if (remainder == 0) {
				cut = cut - N;
			}
		}

		totalCut = totalCut + cut;

		if (remainder == 0 || remainder == 1)
			break;
		else {
			piecePerSausage = remainder;
			M = M - eatPeople;
		}
	}

	cout << totalCut;

	return 0;
}
