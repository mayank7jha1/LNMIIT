#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
int n, m;
char maze[1001][1001];
bool visited[1001][1001], solution[1001][1001];

bool RatInMaze(int i, int j) {
	//You are currently standing at the index of i,j;

	if (i == n and j == m) {
		solution[i][j] = 1;
		for (int x = 0; x <= n; x++) {
			for (int y = 0; y <= m; y++) {
				cout << solution[x][y] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;//THis means you have found a solution
		//and you don't have to find other solution for the
		//problem.

		//if this return statement is false that will give
		//the compiler the signal that even though
		//we have just printed a solution it will
		//think that it has not found one. and will continue the
		//process.
	}


	if (visited[i][j] == 1) {
		//You have already visited this box you don't have to
		//revisit it.
		return false;
	}

	//But agar aapne box ko visit nahi kiya tha/hain toh aap
	//is box ko visit karoge:

	visited[i][j] = 1;
	solution[i][j] = 1;//This means since you have landed on this
	//box, we have assumed this is a part of the solution.

	//NOw you have to move in some direction.

	if (j + 1 <= m and visited[i][j + 1] == 0) {
		bool rightans = RatInMaze(i, j + 1);
		if (rightans == 1) {
			return true;
		}
	}

	if (i + 1 <= n and visited[i + 1][j] == 0) {
		int downans = RatInMaze(i + 1, j);
		if (downans == 1) {
			return true;
		}
	}

	//But in any case if you have reached till line 43 that means
	//you have not found a solution from the i,j box by travelling
	//towards right and down. Hence this box is not the part of solution
	//and hence the assumption in line no. 24 will be reversed.

	solution[i][j] = 0;
	return false;
}




int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'X') {
				visited[i][j] = 1;//This means you have already
				//visited this box.
			}
		}
	}

	n--, m--;//This is to make zero based indexing

	int ans = RatInMaze(0, 0);

	if (ans == 0) {
		cout << "-1" << endl;
	}

}