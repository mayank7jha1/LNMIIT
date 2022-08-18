#include<bits/stdc++.h>
using namespace std;
// const int N = 0;



int main() {
	int n;
	cin >> n;
	int a[n];
	int maximum_element = INT_MIN;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maximum_element = max(maximum_element, a[i]);
	}
	/*	maximum size can go will depend on a[i];

		maximum limit of a value of integer that can be stored
		in an array:*/
	/*
		the maximum size of an array that you can create inside
		a main is 10^6 ~~~ 10^7;

		if array is created globally it can store upto
		10^8 ~~~~ 10^9
	*/
	int freq[maximum_element + 1] = {0};
	// beacuse we are talking about zero based indexing:

	//Sir humne to sirf 16 tak element store kare
	//baaki spaces vo sab empty hain unka use kya hain?
	//extra space kyu kare?

	for (int i = 0; i < n; i++) {
		freq[a[i]] = freq[a[i]] + 1;
		// freq[a[i]]++;
	}

	for (int i = 0; i < maximum_element + 1; i++) {
		if (freq[i] > 0) {
			cout << i << "--->" << freq[i] << endl;
		}
	}
}

