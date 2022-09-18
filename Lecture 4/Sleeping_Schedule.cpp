#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
int n, h, l, r;
int a[100005] = {0};

int Sleeping_Schedule(int i, int waking_hour) {

	if (i == n) {
		return 0;
	}


	int x = (waking_hour + a[i]) % h;// ith sleep ke liye
	int y = (waking_hour + a[i] - 1) % h;


	int ans1 = 0, ans2 = 0;

	if (x >= l and x <= r) {
		ans1 = 1;
	}
	if (y >= l and y <= r) {
		ans2 = 1;
	}

	int option1 = Sleeping_Schedule(i + 1, x) + ans1;
	int option2 = Sleeping_Schedule(i + 1, y) + ans2;


	return max(option1, option2);

}





int main() {
	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << Sleeping_Schedule(0, 0) << endl;;

}

// 10