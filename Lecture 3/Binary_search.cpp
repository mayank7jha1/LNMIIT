#include<bits/stdc++.h>
using namespace std;
// const int N = 0;


int Solve(int a[], int n, int x) {
	int s = 0;
	int e = n - 1;
	int ans = -1;

	while (s <= e) {
		int mid = (s + e) / 2;//Middle index ko find karta hain.
		if (a[mid] == x) {
			ans = mid;
			break;
		} else if (x > a[mid]) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int x;
	cin >> x;
	//cout << x << endl;
	cout << Solve(a, n, x) << endl;
}