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
int n;
int nop;
ii el[maxn];
int marked[maxn];
int size[maxn];
int link[maxn];
 
int find(int x) {
	while (x != link[x]){
		x = link[x];
	}
	return x;
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
	cin >> n;
	for (int i = 0; i < n ; i++) {
		size[i] = 1;
		link[i] = i;
		marked[i] = 0;
	}
	for (int i = 0; i < n-1 ; i++) {
		cin >> el[i].first >> el[i].second;
		el[i].first--;
		el[i].second--;
	}
	nop = n*(n-1)/2;
	int q;
	cin >> q;
	stack<int> qs;
	for (int i = 0; i < q ; i++) {
		char c;
		cin >> c;
		if (c=='Q') {
			qs.push(-1);
		}else {
			int ind;
			cin >> ind;
			ind--;
			qs.push(ind);
			marked[ind] = 1;
		}
	}
	//unite non interesting edges.
	for (int i = 0; i < n-1 ; i++) {
		if (!marked[i]) {
			nop -= size[find(el[i].first)]*size[find(el[i].second)];
			unite(el[i].first,el[i].second);
		}
	}
	stack<int> ans;
	while(qs.size()){
		int t = qs.top(); qs.pop();
		if (t==-1) {
			ans.push(nop);
		}else {
			//remove edge t
			nop -= size[find(el[t].first)]*size[find(el[t].second)];
			unite(el[t].first,el[t].second);
		}
	}
	while(ans.size()){
		cout << ans.top() << "\n";
		ans.pop();
	}
	cout << "\n";
	
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
