#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int main() {
	int t; cin >> t;
	while (t--) {
		string keyboard, word;
		cin >> keyboard >> word;

		int mapping[256] = {0};
		/*
			size::: maximum size that can go is 256 because there
			are 256 asicii character in c++;
		*/

		for (int i = 0; i < 26; i++) {
			mapping[keyboard[i]] = i + 1;//+1 is there because 1 based
			//Indexing
		}

		int ans = 0;
		for (int i = 0; i < word.size() - 1; i++) {
			ans = ans + abs(mapping[word[i + 1]] - mapping[word[i]]);
		}

		cout << ans << endl;
	}
}


/*
keyboard::: adefgh___ _ _ _ _ __ _
mapping[e] = 3;/*
mapping[a] = 1;
mapping[d] = 2;*/