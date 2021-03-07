#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string s;
	cin >> s;
	
	char cu = s[0];
	int len=0, maxlen=0;
	
	for (int i = 0; i < s.length() ; i++) {
		if (cu == s[i]) {
			len++;
		}else{
			cu = s[i];
			maxlen = max(len,maxlen);
			len = 1;
		}
	}
	maxlen = max(len,maxlen);
	
	cout << maxlen << "\n";
	
	return 0;
}
