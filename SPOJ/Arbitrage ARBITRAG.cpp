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
 
int n,m;
 
map<string,int> mpp;
 
double adj[31][31];
 
 
void solve(int t){
	cin >> n;
	if (n==0) {
		exit(0);
	}
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			adj[i][j] = 0;
			if (i==j) {
				adj[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		mpp[s] = i;
	}
	cin >> m;
	for (int i = 0; i < m ; i++) {
		string s1,s2;
		double rate;
		cin >> s1 >> rate >> s2;
		adj[mpp[s1]][mpp[s2]] = max(adj[mpp[s1]][mpp[s2]],rate);
//		adj[mpp[s2]][mpp[s1]] = max(adj[mpp[s2]][mpp[s1]],1/rate);
	}
	for(int k = 0; k < n; k++){
		for (int i = 0; i < n ; i++) {
			for(int j = 0; j < n; j++){
				adj[i][j] = max(adj[i][j],adj[i][k]*adj[k][j]);
			}
		}
	}
	
	for (int i = 0; i < n ; i++) {
		if (adj[i][i]>1){
			cout << "Case "<<t<<": Yes" << "\n";
			return;
		}
	}
	cout << "Case "<<t<<": No" << "\n";
	
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
//		cout << "Caso #" << ti  << "\n";
//		solve();
//	}
	int t = 1;
	while(true){
		solve(t);
		t++;
	}
    return 0;
}
