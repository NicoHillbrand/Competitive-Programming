#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
//#define int long long, int_32main
 
 
void solve(){
	ll a, b;
	cin >> a >> b;
	if (a>2*b||b>2*a) {
		cout << "NO" << "\n";
		return;
	}
	if ((a+b)%3==0) {
		cout << "YES" << "\n";
		
	}else {
		cout << "NO" << "\n";
		
	}
	
	//sum is %3 == 0
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
		solve();
	}
 
	
    return 0;
}
