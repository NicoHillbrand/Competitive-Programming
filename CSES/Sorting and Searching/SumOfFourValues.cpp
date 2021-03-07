#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
int n,x;
ii a[5000];
vector<tuple<int,int,int>> aux;
 
void solve(){
	cin >> n >> x;
	for (int i = 0; i < n ; i++) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	
	for (int i = 0; i < n ; i++) {
		for(int j = 0; j < n; j++){
			if (i!=j) {
				aux.push_back(make_tuple(a[i].first+a[j].first,a[i].second,a[j].second));
			}
		}
	}
	sort(aux.begin(),aux.end());
	int lp=0, rp=aux.size()-1;
	while(lp<rp){
		if (x==get<0>(aux[lp])+get<0>(aux[rp])) {
			if (get<1>(aux[lp])!=get<1>(aux[rp])&&get<1>(aux[lp])!=get<2>(aux[rp])&&get<2>(aux[lp])!=get<1>(aux[rp])&&get<2>(aux[lp])!=get<2>(aux[rp])) {
				cout << get<1>(aux[lp]) << " " << get<1>(aux[rp]) << " " << get<2>(aux[lp])<< " " << get<2>(aux[rp])<< "\n";
				return;
			}
		}
		if (x<get<0>(aux[lp])+get<0>(aux[rp])) {
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
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
//	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
//		cout << "Case #" << ti  << ": ";
//		solve();
//	}
	
	solve();
	
    return 0;
}
