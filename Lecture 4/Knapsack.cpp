#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int Knapsack(int W, int wt[], int val[], int n) {

	if (n == 0 or W == 0) {
		return 0;
	}


	if (wt[n - 1] > W) {
		return Knapsack(W, wt, val, n - 1);
	}
	int option1 = val[n - 1] + Knapsack(W - wt[n - 1], wt, val, n - 1);
	int option2 = 0 + Knapsack(W, wt, val, n - 1);
	return max(option1, option2);
}


int main() {
	int val[] = {60, 90, 120};

	int wt[] = {10, 20, 30};
	int W = 50;

	int n = 3;

	cout << Knapsack(W, wt, val, n);
}