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
 
 
void solve(){
	int n;
	cin >> n;
	vii a;
	for (int i = 0; i < n ; i++) {
		int ar,l;
		cin >> ar >> l;
		a.pb({l,ar});
	}
	sort(a.begin(),a.end());
	int ans = 0;
	int lb = 0;
	for (int i = 0; i < n ; i++) {
		if (a[i].second>=lb) {
			ans++;
			lb = a[i].first;
		}
	}
	
	cout << ans << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("text.in", "r", stdin);
	solve();
	
    return 0;
}
