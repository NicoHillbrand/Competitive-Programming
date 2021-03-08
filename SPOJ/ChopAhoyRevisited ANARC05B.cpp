#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
//using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 27;
string s;
int len;
 
int nway(int pos, int prevsum){
	int res = 0;
	if (pos==s.length()) {
		return 1;
	}
	int sum = 0;
	for (int i = pos; i < s.length() ; i++) {
		sum += s[i]-'0';
		if (sum>=prevsum) {
			res+=nway(i+1,sum);
		}
	}
	return res;
}
 
void solve(){
	int i1  = 1;
	while(true){
		cin >> s;
		if (s=="bye") {
			exit(0);
		}
		cout << i1 << ". " << nway(0,0) << "\n";
		i1++;
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
