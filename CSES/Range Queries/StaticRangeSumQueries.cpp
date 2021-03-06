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
int n;
ll pref[maxn];
 
ll sum(int a ,int b){
	if (a==0) {
		return pref[b];
	}else {
		return pref[b]-pref[a-1];
	}
}
 
void solve(){
	int q;
	cin >> n >> q;
	for (int i = 0; i < n ; i++) {
		cin >> pref[i];
		if (i!=0) {
			pref[i]+=pref[i-1];
		}
	}
	for (int i = 0; i < q ; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum(a-1,b-1) << "\n";
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
