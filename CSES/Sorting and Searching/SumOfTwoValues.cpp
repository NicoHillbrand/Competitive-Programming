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
	int n,x;
	cin >> n >> x;
	vii a(n);
	for (int i = 0; i < n ; i++) {
		int k;
		cin >> k;
		a[i] = {k,i};
	}
	sort(a.begin(),a.end());
	int lp = 0, rp = n-1;
	while(lp<rp){
		if (a[lp].first+a[rp].first==x) {
			cout << a[lp].second+1 << " " << a[rp].second+1 << "\n";
			return;
		}else if (a[lp].first+a[rp].first>x) {
			rp--;
		}else {
			lp++;
		}
	}
	cout << "IMPOSSIBLE" << "\n";
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("text.in", "r", stdin);
	solve();
	
    return 0;
}
