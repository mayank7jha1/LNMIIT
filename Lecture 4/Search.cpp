#include<bits/stdc++.h>
using namespace std;
// const int N = 0;


bool Search(int *a, int s, int target) {

	if (s < 0) {
		return false;
	}

	if (a[s] == target) {
		return true;
	}

	//Next Stage:

	return Search(a, s - 1, target);

}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	int target;
	cin >> target;

	if (Search(a, n - 1, target) == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}