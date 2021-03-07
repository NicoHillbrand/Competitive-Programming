#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
//#define int long long, int_32main
 
int freq[26];
 
void solve(){
 
	string s;
	cin >> s;
	
	for (int i = 0; i < s.length() ; i++) {
		freq[s[i]-'A']++;
	}
	int no = 0;
	int oi = -1;
	for (int i = 0; i < 26 ; i++) {
		if (freq[i]%2==1) {
			no++;
			oi = i;
			if (no==2) {
				cout << "NO SOLUTION" << "\n";
				return;
			}
		}
	}
	string res = "";
 
	for (int i = 0; i < 26 ; i++) {
		if (i!=oi) {
			for(int j = 0; j < freq[i]/2; j++){
				res+= i+'A';
			}
		}
	}
	if (oi!=-1) {
		for (int i = 0; i < freq[oi] ; i++) {
			res+= oi+'A';
		}
	}
	for (int i = 25; i > -1 ; i--) {
		if (i!=oi) {
			for(int j = 0; j < freq[i]/2; j++){
				res+= i+'A';
			}
		}
	}	
	
	cout << res << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
