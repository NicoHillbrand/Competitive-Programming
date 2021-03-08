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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 101;
string s="l";
int dp[maxn][maxn];
 
 
void solve(){
	int ite = 1;
	while(true){
		cin >> s;
		if (s[0]=='-') {
			break;
		}
		int len = s.length();
		int count = 0;
		int ss = 0;
		for (int i = 0; i < len ; i++) {
			if (s[i]=='{') {
				ss++;
			}else {
				if (ss==0) {
					count++;
					ss++;
				}else {
					ss--;
				}
			}
		}
		cout << ite << ". "<<  count + ss/2 << "\n";
		ite++;
	}
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
 
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
////	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		cout << ti << ". " ;
//		solve();
//	}
//	
	solve();
	
    return 0;
}
