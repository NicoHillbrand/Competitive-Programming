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
	ll a[n];
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	sort(a,a+n);
	ll med = a[n/2];
	ll ans = 0;
	for (int i = 0; i < n ; i++) {
		ans += abs(a[i]-med);
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
