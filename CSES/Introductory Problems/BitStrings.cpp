#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
 
	long long answer = 1;
	for (int i = 0; i < n ; i++) {
		answer *=2;
		answer %= 1000000007LL;
	}
 
	cout << answer << "\n";
	return 0;
}
