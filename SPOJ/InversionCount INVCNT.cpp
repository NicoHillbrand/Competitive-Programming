#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <string>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
 
const int maxn = 2e5;
int n;
int a[maxn];
 
void solve(){
	cin >> n;
	indexed_set itms;
	ll invs = 0;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
		itms.insert(a[i]);
		if (i>0) {
			invs+=i-itms.order_of_key(a[i]);
		}
	}
	cout << invs << "\n";
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
 
