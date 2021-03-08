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
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const int INF = 5e8+1;
const ll inf = 1e16;
 
const int maxn = 500;
 
int e,f,cw,n;
ii coin[maxn]; //weight value
 
int dp[10001];
 
void solve(){
	cin >> e >> f;
	cw = f-e;
	cin >> n;
	if (cw==0) {
		cout << "The minimum amount of money in the piggy-bank is "<< 0 << ".\n";
		return;
	}
	for (int i = 0; i < n ; i++) {
		cin >> coin[i].second >> coin[i].first;
	}
	dp[0] = 0;
	for (int i = 1; i <= cw ; i++) {
		dp[i] = INF;
		for(int j = 0; j < n; j++){
			if (i-coin[j].first>=0) {
				dp[i] = min(dp[i],dp[i-coin[j].first]+coin[j].second);
			}
		}
	}
 
	if (dp[cw]==INF&&cw!=0) {
		cout << "This is impossible." << "\n";
	}else {
		cout << "The minimum amount of money in the piggy-bank is "<<dp[cw] << ".\n";
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
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
		solve();
	}
//	solve();
    return 0;
}
