#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long n,a;
	cin >> n;
	long long res = (n * (n+1) )/2;
	for (int i = 0; i < n-1; i++) {
		cin >> a;
		res -=a;
	}
	cout << res << "\n";
	return 0;
}
