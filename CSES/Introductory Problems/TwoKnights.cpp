#include <bits/stdc++.h>
using namespace std;
 
 
long long val(long long n) {
	return ((n - 1) * (n + 4) * (n * n - 3 * n + 4)) / 2;
}
 
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cout << val(i) << "\n";
	return 0;
}
