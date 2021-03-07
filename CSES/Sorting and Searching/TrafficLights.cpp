#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <string>
using namespace std;
#define pb push_back
#define mp make_pair
#define mt make_tuple
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX
const ll inf = 1e16;
 
 
const int maxn = 2e5;
 
 
void solve(){
	int n, x;
	cin >> x >> n;
	multiset<int> p;
	set<int> lat;
	p.insert(x);
	lat.insert(0);
	lat.insert(x);
	for (int i = 0; i < n ; i++) {
		int t;
		cin >> t;
		auto it = lat.upper_bound(t);
		int t1 = *it;
		it--;
		int t2 = *it;
		p.erase(p.find(t1-t2));
		p.insert(t1-t);
		p.insert(t-t2);
		lat.insert(t);
		auto it2 = p.end();
		it2--;
		cout << *it2 << " ";
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
 
	
	solve();
	
    return 0;
}
