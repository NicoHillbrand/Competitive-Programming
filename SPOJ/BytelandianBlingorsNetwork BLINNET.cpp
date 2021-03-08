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
 
const int maxn = 2e5;
int n,m;
 
 
vector<tuple<int,int,ll>> el;
bool compare(tuple<int,int,ll> a, tuple<int,int,ll> b){
	return get<2>(a) < get<2>(b);
}
ll treeSize;
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
	a = find(a);
	b = find(b);
	if (size[a] < size[b]){
		swap(a,b);
	}
	size[a] += size[b];
	link[b] = a;
}
 
 
void kruskal(){
	for (int i = 0; i < n ; i++) {
		size[i] = 1;
		link[i] = i;
	}
	sort(el.begin(),el.end(),compare);
	int u,v;
	ll w;
	for (int i = 0; i < el.size() ; i++) {
		tie(u,v,w) = el[i];
		if (!same(u,v)) {
			unite(u,v);
			treeSize+=w;
		}
	}
}
 
void solve(){
	cin >> n;
	el.clear();
	treeSize = 0;
	for (int i = 0; i < n ; i++) {
		string _;
		cin >> _;
		int c;
		cin >> c;
		for(int j = 0; j < c; j++){
			int v,w;
			cin >> v >> w;
			v--;
			el.pb(mt(i,v,w));
		}
	}
	kruskal();
	cout << treeSize << "\n";
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