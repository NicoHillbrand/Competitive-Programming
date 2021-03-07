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
#define ts to_string
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
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
 
const int maxn = 2e6;
int n,k;
 
void solve(){
	cin >> n >> k;
	vii movies(n);
	for (int i = 0; i < n ; i++) {
		cin >> movies[i].second >> movies[i].first;
	}
	sort(movies.begin(),movies.end());
	int res =0;
	multiset<int> et;
	for (int i = 0; i < n ; i++) {
		int start, end;
		tie(end,start) = movies[i];
		if (et.empty()) {
			et.insert(end);
			res++;
			continue;
		}
		//first guy that can't watch it anymore
		auto it = et.upper_bound(start);
		if (it==et.begin()) {
			//nobody can watch it
			if (et.size()<k) {
				et.insert(end);
				res++;
			}
		}else {
			it--;
			et.erase(it);
			et.insert(end);
			res++;
		}
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
	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
//	
	solve();
	
    return 0;
}
