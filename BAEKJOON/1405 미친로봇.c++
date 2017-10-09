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

const int E = 0;
const int W = 1;
const int N = 2;
const int S = 3;

int length;
double prob[4];

int direc[4] = { E, W, N, S };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int visited[30][30];

double result;
double notResult;

double DFS(pair<int, int> here, double pro, int len) {

	int hereY = here.first;
	int hereX = here.second;

	len++;
	if (len == length + 1)
		return pro;

	visited[hereY][hereX] = true;

	for (int i = 0; i < 4; i++) {

		int thereY = hereY + dy[i];
		int thereX = hereX + dx[i];
		pair<int, int> there = make_pair(thereY, thereX);

		if (!visited[thereY][thereX]) {
			if (len == length)
				result = result + DFS(there, pro * prob[i], len);
			else
				DFS(there, pro * prob[i], len);
		}
	}

	visited[hereY][hereX] = false;
	return pro;
}

int main() {

	cin >> length;

	for (int i = 0; i < 4; i++) {
		cin >> prob[i];
		prob[i] = prob[i] / 100;
	}

	memset(visited, 0, sizeof(visited));

	DFS(make_pair(15, 15), 1, 0);
	printf("%.9lf", result);

	return 0;
}
