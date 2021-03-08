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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 1e2+1;
 
//https://titanwolf.org/Network/Articles/Article?AID=26395ef8-5ed9-4647-b32a-e90f9b931c7b#gsc.tab=0
 
 
//do some kind of search where you try in order of fuel
 
 
int n;
void solve(){
	cin >> n;
	ii a[n];
	for (int i = 0; i < n ; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a,a+n,greater<ii>());
	int pos;
	int fuel;
	int ans = 0;
	cin >> pos >> fuel;
	multiset<int> heap;
	for (int i = 0; i < n ; i++) {
		if (pos-fuel<=0) {
			cout << ans << "\n";
			return;
		}
		int j = i;
		while(j<n&&abs(pos-a[j].first)<=fuel){
			heap.insert(a[j].second);
			j++;
		}
		i = j-1;
		if (heap.empty()) {
			break;
		}
		ans++;
		fuel+=*(--heap.end());
		heap.erase(--heap.end());
	}
	if (pos-fuel<=0) {
		cout << ans << "\n";
		return;
	}
	cout << -1 << "\n";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
////	
	int t;
	cin >> t;
	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
		solve();
	}
 
//	solve();
	
	
	
    return 0;
}
 
