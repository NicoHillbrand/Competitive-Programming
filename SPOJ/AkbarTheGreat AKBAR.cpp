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
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
 
const int maxn = 1e6;
int n,m,s;
vector<int> adj[maxn];
int sol[maxn];
int cnt;
bool done;
 
void bfs( int snode, int d, int id){
	if (sol[snode]!=0) {
		done = true;
		return;
	}
	queue<ii> q;
	q.push(mp(snode,d));
	sol[snode] = id;
	cnt++;
	ii node;
	while(!q.empty()){
		node=q.front();q.pop();
		if (node.second==0) {
			continue;
		}
		for(int c:adj[node.first]){
			if (sol[c]==0) {
				sol[c] = id;
				cnt++;
				q.push(mp(c,node.second-1));
			}else if(sol[c]!=id){
				done = true;
				return;
			}
		}
	}
}
 
 
void solve(){
	cin >> n >> m >> s;
	done = 0;
	cnt = 0;
	for (int i = 0; i < n ; i++) {
		adj[i].clear();
		sol[i] = 0;
	}
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (int i = 0; i < s ; i++) {
		int c,str;
		cin >> c >> str;
		if (done) {
			continue;
		}
		c--;
		bfs(c,str,i+1);
	}
	if (done||cnt!=n) {
		cout << "No" << "\n";
	}else {
		cout << "Yes" << "\n";
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
