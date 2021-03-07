#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
 
const int maxn = 1e5+1;
int n;
 
void solve(){
	cin >> n;
	map<int,int> et;
	vector<tuple<int,int,int>> p;
	for (int i = 0; i < n ; i++) {
		int s,e,r;
		cin >> s >> e >> r;
		p.pb({e,s,r});
		
	}
	sort(p.begin(),p.end());
	for (int i = 0; i < n ; i++) {
		if (et.find(get<0>(p[i]))!=et.end()) {
			et.erase(et.find(get<0>(p[i])));
		}
		et.insert({get<0>(p[i]),i});
	}
	//what happens with two end times 
	vector<ll> dp(n+1,0);
	for (int i = 1; i <= n ; i++) {
		dp[i] = dp[i-1];
		ll start, end, reward;
		tie(end,start,reward) = p[i-1];
		int where = 0;
		auto it = et.lower_bound(start); 
		if (it!=et.begin()) {
			it--;
			where = (*it).second+1;
		}
		dp[i] = max(dp[i],reward+dp[where]); //last project 
	}
	cout << dp[n] << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
 
	
	solve();
	
    return 0;
}
