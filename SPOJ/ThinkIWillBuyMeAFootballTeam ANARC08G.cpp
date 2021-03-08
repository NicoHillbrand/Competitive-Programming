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
 
const int maxn = 1001;
int n;
int adj[maxn][maxn];
int credit[maxn];
 
void solve(int cass){
	cin >> n;
	if (n==0) {
		exit(0);
	}
	for (int i = 0; i < n ; i++) {
		credit[i] = 0;
	}
	
	ll prev = 0;
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			cin >> adj[i][j];
			prev += adj[i][j];
			credit[j] += adj[i][j];
			credit[i] -= adj[i][j];
		}
	}
	
	ll total = 0;
	for (int i = 0; i < n ; i++) {
		if (credit[i]>0) {
			total += credit[i];
		}
	}
	
	cout << cass << ". " << prev << " " << total << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
	int t=1;
	for(int ti = 1; ti <= 1000000; ti++){
		solve(ti);
	}
	
    return 0;
}
