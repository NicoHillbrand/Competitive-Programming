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
 
const int maxn = 1e6;
 
 
int start;
 
//string mod
bool good(string s){
    int res = 0; 
    // One by one process all digits of 'num' 
    for (int i = 0; i < s.length(); i++){ 
         res = (res*10 + (int)s[i] - '0') %start; 
    }
    return res==0; 
}
 
void bfs(){
	queue<string> q;
	q.push("1");
	string node;
	while(!q.empty()){
		node=q.front();q.pop();
		if (good(node)) {
			cout << node << "\n";
			return;
		}
		q.push(node+"0");
		q.push(node+"1");	
	}
}
 
 
void solve(){
	cin >> start;
	bfs();
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
 
