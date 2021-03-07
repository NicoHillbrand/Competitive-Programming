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
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 2500;
int n, m, q;
vector<tuple<int,int,ll>> el;
 
 
void solve(){
	cin >> n >> m;
	ll u,v,w;
	for (int i = 0; i < m ; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		el.pb({u,v,w});
	}
	vi parent(n,-1);
	vector<ll> dists(n,inf);
	dists[0] = 0;
	int x;
	for (int i = 0; i < n ; i++) {
		x=-1;
		for(int j = 0; j < m; j++){
			int u,v;
			ll w;
			tie(u,v,w) = el[j];
			if (dists[v]>dists[u]+w) {
				dists[v]=dists[u]+w;
				parent[v] = u;
				x=v;
			}
		}
	}
	
	if (x==-1) {
		cout << "NO" << "\n";
		
	}else {
		cout << "YES" << "\n";
					
		for (int i = 0; i < n ; i++) {
			x = parent[x];
		}
		
		stack<int> res;
		int node = x;
		res.push(x+1);
		node = parent[node];
		while(node!=x){
			res.push(node+1);
			node = parent[node];
		}
		res.push(x+1);
		
		while(!res.empty()){
			cout << res.top() << " ";
			res.pop();
		}						
	}	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
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
 
