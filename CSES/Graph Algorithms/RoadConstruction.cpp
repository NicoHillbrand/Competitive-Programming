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
 
const int maxn = 1e5;
int n,m,comps;
int maxcomp;
 
int size[maxn];
int link[maxn];
 
int find(int x) {
	while (x != link[x]){
		x = link[x];
	}
	return x;
}
 
bool same(int a, int b){
	return find(a)==find(b);
}
 
void unite(int a, int b) {
	comps--;
	a = find(a);
	b = find(b);
	if (size[a] < size[b]){
		swap(a,b);
	}
	size[a] += size[b];
	maxcomp = max(maxcomp,size[a]);
	link[b] = a;
}
 
 
 
void solve(){
	cin >> n >> m;
	comps = n;
	maxcomp = 1;
	for (int i = 0; i < n ; i++) {
		size[i] = 1;
		link[i] = i;
	}
	for (int i = 0; i < m ; i++) {
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		if (!same(u,v)) {
			unite(u,v);
		}
		cout << comps << " " << maxcomp << "\n";
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
