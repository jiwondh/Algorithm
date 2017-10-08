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

	int N, M;

	cin >> N >> M;

	vector<vector<int> > student(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		student[a].push_back(b);
		student[b].push_back(a);
	}

	set<int> invitation;

	for (int i = 0; i < student[1].size(); i++) {
		int myFriend = student[1][i];
		invitation.insert(myFriend);
		for (int j = 0; j < student[myFriend].size(); j++) {
			int friendOffriend = student[myFriend][j];
			if (friendOffriend != 1)
				invitation.insert(friendOffriend);
		}
	}

	int totalInvitation = invitation.size();

	cout << totalInvitation;

	return 0;
}
