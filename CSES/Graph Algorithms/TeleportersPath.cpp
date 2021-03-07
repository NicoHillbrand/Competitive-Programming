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
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 1e5+1;
int n,m;
vi circuit;
stack<int> curpath;
int edgecount[maxn];
int indeg[maxn];
int outdeg[maxn];
bool vis[maxn];
vector<int> adj[maxn];
 
int checkEuler(){
	for (int i = 0; i < n ; i++) {
		if (i>0&&i<n-1) {
			if (indeg[i]!=outdeg[i]) {
				return false;
			}
		}
		if (i==0) {
			if (indeg[i]!=outdeg[i]-1) {
				return false;
			}
		}
		if (i==n-1) {
			if (indeg[i]!=outdeg[i]+1) {
				return false;
			}
		}
	}
	return true;
}
 
 
void findEuler(int start){
	curpath.push(start);
	int curnode = start;
	for (int i = 0; i < n ; i++) {
		edgecount[i] = adj[i].size();
	}
	while(!curpath.empty()){
		if (edgecount[curnode]!=0) {
			curpath.push(curnode);
			int next = adj[curnode].back();
			edgecount[curnode]--;
			adj[curnode].pop_back();
			curnode = next;
		}else {
			circuit.pb(curnode);
			curnode = curpath.top();
			curpath.pop();
		}
	}
	reverse(circuit.begin(),circuit.end());
}
 
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		indeg[v]++;
		outdeg[u]++;
		adj[u].pb(v);
	}
 
	if(checkEuler()==0){	
		cout << "IMPOSSIBLE" << "\n";
		return;
	}
	adj[n-1].pb(0);
	indeg[0]++;
	outdeg[n-1]++;
		
    findEuler(0); 
	
    if (circuit.size()!=m+2) {
		cout << "IMPOSSIBLE" << "\n";
		return;
	}
    
    //find the point where we use the forbidden edge
    vi res;
    int ind=-1;
    for (int i = 0; i < circuit.size()-1; i++) {
		if (circuit[i]==n-1&&circuit[i+1]==0) {
			ind = i+1;
			for(int j = i+1; j < circuit.size()-1; j++){
				res.pb(circuit[j]);
			}
			break;
		}
	}
	for (int i = 0; i < ind ; i++) {
		res.pb(circuit[i]);
	}
    
    for (int i = 0; i < res.size() ; i++) {
		cout << res[i]+1 << " ";
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
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
 
	solve();
	
    return 0;
}
