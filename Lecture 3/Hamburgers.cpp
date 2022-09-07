#include<bits/stdc++.h>
using namespace std;
// const int N = 0;
#define int long long
#define val 10000001000000
char in[1000];
int nb, ns, nc, pb, ps, pc, r;

int Hamburgers() {
	int s = 0;
	int e = val;
	int ans = -1;
	//This tells you ki recipe me bread,sausae and cheese kitni chahiye.
	int cb = 0, cc = 0, cs = 0;

	for (int i = 0; in[i] != '\0'; i++) {
		if (in[i] == 'B') cb++;
		else if (in[i] == 'S') cs++;
		else cc++;
	}
	//cout << cb << " " << cs << " " << cc << endl;


	while (s <= e) {
		int mid = (s + e) / 2;

		int bread = (((cb * mid) - nb) * pb) < 0 ? 0 : ((cb * mid) - nb) * pb;
		int sausage = (((cs * mid) - ns) * ps) < 0 ? 0 : ((cs * mid) - ns) * ps;
		int cheese = (((cc * mid) - nc) * pc) < 0 ? 0 : ((cc * mid) - nc) * pc;

		int price = bread + cheese + sausage;
		if (price == r) {
			return mid;
		} else if (price < r) {
			s = mid + 1;
			ans = mid;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}



int32_t main() {
	cin >> in;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;

	cout << Hamburgers() << endl;

}