#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int n, k;


int ans(string s, char x) {
	int ans1 = INT_MIN;

	int j = 0;
	int count = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != x) {
			count++;
		}
		while (count > k and j <= i) {
			if (s[j++] != x) {
				count--;
			}
		}

		if (i - j + 1 > ans1) {
			ans1 = i - j + 1;
		}
	}
	return ans1;
}



int main() {
	cin >> k;
	string s;
	cin >> s;


	//First Try: Convert b->a;
	int value = ans(s, 'a');// hostile character send kar raha hu.

	//Second Try: COnvert a->b
	int value2 = ans(s, 'b');
	cout << max(value, value2) << endl;

}



