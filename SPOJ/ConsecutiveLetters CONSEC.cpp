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
 
const int maxn = 3e5+1;
int q;
string s;
string s2;
 
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
	cin >> s;
	s2 = s;
	int n = s.size();
	cin >> q;
	stack<ii> qs;
	for (int i = 0; i < q ; i++) {
		int type, ind;
		cin >> type >> ind;
		if (type==2) {
			s2[ind] = '#';
		}
		qs.push(mp(type,ind));
	}
	for (int i = 0; i < n; i++) {
		size[i] = 1;
		link[i] = i;
	}
	
	//calc union
	for (int i = 0; i < n-1 ; i++) {
		if (s2[i]!='#'&&s2[i]==s2[i+1]) {
			unite(i,i+1);
		}
	}
	
	stack<int> ans;
	while(qs.size()){
		int t,i;
		tie(t,i) = qs.top(); qs.pop();
		if (t==1) {
			ans.push(size[find(i)]);
		}else {
			s2[i] = s[i];
			if (i>0&&i<n-1) {
				if (s2[i-1]==s2[i]) {
					unite(i-1,i);
				}
				if (s2[i+1]==s2[i]) {
					unite(i+1,i);
				}
			}else if(i==0){
				if (s2[i+1]==s2[i]) {
					unite(i+1,i);
				}
			}else {
				if (s2[i-1]==s2[i]) {
					unite(i-1,i);
				}
			}
		}
	}
	while(ans.size()){
		cout << ans.top() << "\n";
		ans.pop();
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
		cout << "Case " << ti  << ":\n";
		solve();
	}
 
//	solve();
	
    return 0;
}
