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
int n,m,q;
 
vector<ti> el;
bool compare(ti a, ti b){
	return get<2>(a) > get<2>(b);
}
 
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
 
 
void solve(){
	cin >> n >> m >> q;
	for (int i = 0; i < n ; i++) {
		size[i] = 1;
		link[i] = i;
	}
	
	for (int i = 0; i < m ; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		el.pb(mt(u,v,w));
	}
	sort(el.begin(),el.end(),compare);
	vector<ti> qs;
	for (int i = 0; i < q; i++) {
		int u,v;
		cin >> u >> v;
		qs.pb(mt(v,u,i));
	}
	sort(qs.rbegin(),qs.rend());
	vii res;
	int p = 0;
	for (int i = 0; i < q ; i++) {
		int w = get<0>(qs[i]);
		int v = get<1>(qs[i]);
		
		while(p<el.size()&&w<=get<2>(el[p])){
			if (!same(get<0>(el[p]),get<1>(el[p]))) {
				unite(get<0>(el[p]),get<1>(el[p]));
			}
			p++;
		}
		res.pb(mp(get<2>(qs[i]),size[find(v)]));
	}
	sort(res.begin(),res.end());
	for (int i = 0; i < res.size() ; i++) {
		cout << res[i].second << "\n";
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
