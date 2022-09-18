#include<bits/stdc++.h>
using namespace std;
// const int N = 0;


int power2(int x, int n, int i) {

	if (i > n) {
		return 1;
	}
	int ans = x * power2(x, n, i + 1);
	return ans;
}

int power(int x, int n) {

	if (n == 0) {
		return 1;
	}


	int ans = x * power(x, n - 1);

	return ans;
}


int main() {
	int x, n;
	cin >> x >> n;

	cout << power(x, n) << endl;
	cout << power2(x, n, 1) << endl;
}

/*
1 2 3 4 5 6 7 8 9 10:

10 9 8 7 6 5 4 3 2 1:
*/