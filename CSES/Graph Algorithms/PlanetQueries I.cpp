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
 
const int maxn = 2e5;
int n,q;
int up[maxn][31];
 
int ancestor(int x, int k){
	for(int i = 30; i>=0 ; i--){
		if (!!(k&(1<<i))) {
			x = up[x][i];
		}
	}
	return x;
}
 
void solve(){
	cin >> n >> q;
	for (int i = 0; i < n ; i++) {
		cin >> up[i][0];
		up[i][0]--;
	}
	for (int h = 1; h <= (int)ceil(log2(1e9+1)) ; h++) {
		for (int i = 0; i < n ; i++) {
			up[i][h] = up[up[i][h-1]][h-1];
		}
	}
	
	
	for (int i = 0; i < q ; i++) {
		int x,k;
		cin >> x >> k;
		cout << ancestor(x-1,k)+1 << "\n";
	}
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
//	
	solve();
	
    return 0;
}
