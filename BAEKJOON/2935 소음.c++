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
	string A, B;
	char operation[2];

	cin >> A >> operation >> B;

	string result;
	switch (operation[0]) {
	case '*':
		A.erase(0, 1);
		B.erase(0, 1);
		cout << "1" << A << B;
		break;
	case '+':
		int dif = 0;
		if (A.length() > B.length()) {
			dif = A.length() - B.length();
			A.erase(dif, B.length());
			cout << A << B;
		} else if (A.length() == B.length()) {
			A.erase(0, 1);
			cout << "2" << A;
		} else {
			dif = B.length() - A.length();
			B.erase(dif, A.length());
			cout << B << A;
		}
		break;
	}
	return 0;
}
