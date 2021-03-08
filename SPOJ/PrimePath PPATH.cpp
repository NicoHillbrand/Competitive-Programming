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
 
const int maxn = 10011;
 
bool isPrime(int n){ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
 
int start, goal;
int vis[maxn];
int dists[maxn];
 
void bfs(){
	queue<int> q;
	q.push(start);
	dists[start] = 0;
	vis[start] = true;
	int node;
	while(!q.empty()){
		node=q.front();q.pop();
		for (int i = 0; i < 4 ; i++) {
			for(int j = 0; j <= 9; j++){
				if (i==0&&j==0) {
					continue;
				}
				string s = to_string(node);
				s[i] = to_string(j)[0];
				int c = stoi(s);
				if (!vis[c]&&isPrime(c)) {
					dists[c] = dists[node]+1;
					vis[c] = true;
					q.push(c);
				}
			}
		}
	}
}
 
 
void solve(){
	cin >> start >> goal;
	for (int i = 0; i < 10000 ; i++) {
		vis[i] = 0;
		dists[i] = INF;
	}
	
	bfs();
	
	if (dists[goal]==INF) {
		cout << "Impossible" << "\n";
		
	}else {
		cout << dists[goal] << "\n";
		
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
//		cout << "Case #" << ti  << ": ";
		solve();
	}
 
    return 0;
}
