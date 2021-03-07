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
 
 
const int maxn = 2e5+1;
ll n,x;
ll a[maxn];
 
void solve(){
	cin >> n;
	ll res = 0;
	ll s = 0;
	map<ll,int> mp;
	mp[0]++;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
		s= (s+a[i]%n+n)%n;
		res+=mp[s-x];
		mp[s]++;
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
 
