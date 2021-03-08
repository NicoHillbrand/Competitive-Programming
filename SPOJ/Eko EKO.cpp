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
 
const int maxn = 1e6+1;
 
ll n, m;
ll tree[maxn];
 
bool good(ll height){
	ll sum = 0;
	for (int i = 0; i < n ; i++) {
		if (tree[i]>height) {
			sum += tree[i]-height;
		}
	}
	if (sum>=m) {
		return true;
	}else {
		return false;
	}
}
 
void solve(){
	cin >> n >> m;
	for (int i = 0; i < n ; i++) {
		cin >> tree[i];
	}
	ll low = 0, high = 1e12;
	while(low<high){
		ll mid = (high+low)/2;
		if (!good(mid+1)) {
			high = mid;
		}else {
			low = mid+1;
		}
	}
	cout << low << "\n";
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
////		cout << "Case " << ti  << ":\n";
//		solve();
//	}
	solve();
    return 0;
}
