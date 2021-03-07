#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	
	long long sum=0;
	int val,next;
	cin >> val;
	for (int i = 0; i < n -1; i++) {
		cin >> next;
		if (next<val) {
			sum += val -next;
		}else {
			val = next;
		}
		
	}
	cout << sum << "\n";
	return 0;
}
