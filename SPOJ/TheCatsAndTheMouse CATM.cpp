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
int n,m,t;
int md[maxn][maxn];
int cd[maxn][maxn];
bool vis[maxn][maxn];
 
int mx,my,cx1,cy1,cx2,cy2;
 
void solve(){
	cin >> n >> m >> t;
	for (int i1 = 0; i1 < t ; i1++) {
		//reset
		cin >> mx >> my >> cx1 >> cy1 >> cx2 >> cy2;
		if ((mx<cx1+abs(my-cy1)&&mx<cx2+abs(my-cy2)) || (m-mx<m-cx1+abs(my-cy1)&&m-mx<m-cx2+abs(my-cy2)) || (my<cy1+abs(mx-cx1)&&my<cy2+abs(mx-cx2)) || (n-my<n-cy1+abs(mx-cx1)&&n-my<n-cy2+abs(mx-cx2))) {
			cout << "YES" << "\n";
		}else {
			cout << "NO" << "\n";
		}
	}
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
//	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		solve();
//	}
 
	solve();
	
	
	
    return 0;
}
