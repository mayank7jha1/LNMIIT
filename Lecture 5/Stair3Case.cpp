#include<bits/stdc++.h>
using namespace std;
// const int N = 0;



void StairCase(int *a, int n, int i, int steps, bool *visited, int &ans) {

	if (i == n) {
		ans = min(ans, steps);
		return;
	}



	//You are standing at the stair i:

	visited[i] = 1;

	//When you are taking one box Jump:
	if (i + 1 <= n and !visited[i + 1]) {
		StairCase(a, n, i + 1, steps + 1, visited, ans);
	}

	//When you are taking value amount boxes  of jump

	if (i + a[i] <= n and i + a[i] >= 0 and !visited[i + a[i]]) {
		StairCase(a, n, i + a[i], steps + 1, visited, ans);
	}

	//When you have considered both the ways of travelling and calculated
	//the min number of steps from this path:

	//you have to make the visited array again to its original state
	//as you can visit this box from any other path also.

	visited[i] = 0;
	return;
}



int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool visited[10005] = {0};
		int a[n + 1];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int ans = INT_MAX;
		StairCase(a, n, 0, 0, visited, ans);

		if (ans == INT_MAX) {
			cout << "-1" << endl;
		} else {
			cout << ans << endl;
		}
	}
}