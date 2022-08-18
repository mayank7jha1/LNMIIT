#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int main() {
	int n;
	cin >> n;
	int a[n];
	int maximum_element = INT_MIN;
	int minimum_element = INT_MAX;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maximum_element = max(maximum_element, a[i]);
		minimum_element = min(minimum_element, a[i]);
	}

	int freq[maximum_element - minimum_element + 1] = {0};

	/*max = 16;

	min = -2;
	freq[16 - (-2) + 1] = freq[19];
	*/

	for (int i = 0; i < n; i++) {
		freq[a[i] - minimum_element]++;
	}

	for (int i = 0; i < maximum_element - minimum_element + 1; i++) {
		if (freq[i] > 0) {
			cout << i + minimum_element << "-->" << freq[i] << endl;
		}
	}
}