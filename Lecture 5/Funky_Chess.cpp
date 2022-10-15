#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int n;
int grid[10][10], Saare_One, ans = -1, N = 10;

int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] = {2, -2, 1, -1, 2, -2, -1, 1};


void Input_Grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				Saare_One++;
				//This is one of the possible boxes where the
				//knight can travel ideally.
			}
		}
	}
}



void Knight(int x, int y, int count) {
	//THis count represents the number of boxes the knight
	//was able to travel in a single path.

	//ans variable represents the max number of boxes the
	//knight was able to travel across all the paths.

	ans = max(count, ans);
	for (int i = 0; i < 8; i++) {
		int x_coordinate = x + dx[i];
		int y_coordinate = y + dy[i];

		if (x_coordinate >= 0 and x_coordinate < N and y_coordinate >= 0
		        and y_coordinate < N and
		        grid[x_coordinate][y_coordinate] == 1) {


			//NOw i have reached the x_coordinate and y_coordinate
			// i will mark this as visited.

			grid[x_coordinate][y_coordinate] = 0;

			Knight(x_coordinate, y_coordinate, count + 1);

			grid[x_coordinate][y_coordinate] = 1;//Backtracking

		}
	}
}



int main() {
	cin >> n;
	Input_Grid();

	grid[0][0] = 0;//Because i am assuming this box of
	//0,0 will always be in your solution as you are starting from this
	//point.

	Knight(0, 0, 1);//THis one represents the count of the
	//box 0,0 index.

	cout << Saare_One - ans << endl;
}