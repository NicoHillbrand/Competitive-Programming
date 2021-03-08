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
 
const int maxn = 1e5;
 
 
vector<int> adj[maxn];
bool vis[maxn];
 
void dfs(int node){
	if (!vis[node]) {
		vis[node] = true;
		for(int c : adj[node]){
			dfs(c);
		}
	}
}
 
int n;
void solve(){
	cin >> n;
	vi indeg = vi(26,0);
	vi outdeg = vi(26,0);
	for (int i = 0; i < 26 ; i++) {
		adj[i].clear();
		vis[i] = 0;
	}
	for (int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		indeg[s[s.length()-1]-'a']++;
		adj[s[0]-'a'].pb(s[s.length()-1]-'a');
		adj[s[s.length()-1]-'a'].pb(s[0]-'a');
		outdeg[s[0]-'a']++;
	}
	
	//connected check
	bool connected = false;
	for (int i = 0; i < 26 ; i++) {
		if (!vis[i]&&outdeg[i]!=0) {
			dfs(i);
			if (connected) {
				cout << "The door cannot be opened." << "\n";
				return;
			}
			connected = true;
		}
	}
	
	
	
	bool source = false;
	bool sink = false;
	for (int i = 0; i < 26 ; i++) {
		if (indeg[i]!=outdeg[i]) {
			if (indeg[i]==outdeg[i]+1) {
				if (source) {
					cout << "The door cannot be opened." << "\n";
					return;
				}
				source = true;
			}else if(indeg[i]+1 == outdeg[i]){
				if (sink) {
					cout << "The door cannot be opened." << "\n";
					return;
				}
				sink = true;
			}else{
				cout << "The door cannot be opened." << "\n";
				return;
			}
		}
	}
	cout << "Ordering is possible." << "\n";
	
	
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
//		cout << "Case " << ti  << ":\n";
		solve();
	}
//	solve();
    return 0;
}
