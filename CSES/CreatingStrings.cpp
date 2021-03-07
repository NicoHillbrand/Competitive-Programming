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
 
string s;
bool incl[8];
string perm;
set<string> res;
void genPerm(){
	if (perm.length() == s.length()) {
		res.insert(perm);
		return;
	}
	int i;
	for (i = 0; i < s.length() ; i++) {
		if (incl[i]) {
			continue;
		}
		incl[i] = true;
		perm += s[i];
		genPerm();
		incl[i] = false;
		perm.pop_back();
	}
}
 
void solve(){
	cin >> s;
	genPerm();
	cout << res.size() << "\n";
	for(auto it: res){
		cout << it << "\n";	
	}
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
