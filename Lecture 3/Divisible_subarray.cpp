#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
int a[100005], freq[100005];


int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(freq, 0, sizeof(freq));

		freq[0] = 1;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			sum = sum % n;
			sum = (sum + n) % n;
			freq[sum]++;
		}
		int ans = 0;

		for (int i = 0; i < n; i++) {
			int value = freq[i];
			ans += (value * (value - 1)) / 2;
		}
		cout << ans << endl;
	}
}


// -2+5 % 5 == 3;