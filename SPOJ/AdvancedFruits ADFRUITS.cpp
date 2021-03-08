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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define INF INT_MAX
const ll inf = 1e16;
 
const int maxn = 101;
 
 
 
string lcs(string ss1, string ss2){
	
	int m = ss1.length(), n = ss2.length();
	int L[m+1][n+1];
	
	for (int i=0; i<=m; i++) { 
		for (int j=0; j<=n; j++) { 
		    if (i == 0 || j == 0) {
		    	L[i][j] = 0;  
		    }else if (ss1[i-1] == ss2[j-1]){
			    L[i][j] = L[i-1][j-1] + 1;
		    }else {
			    L[i][j] = max(L[i-1][j], L[i][j-1]); 
		    }
	    } 
	}
	
	string lcs;
	int i = m, j = n;
	while(i>0&&j>0){
		if (ss1[i-1]==ss2[j-1]) {
			lcs.pb(ss1[i-1]);
			i--;
			j--;
		}else if(L[i-1][j]>L[i][j-1]){
			i--;
		}else {
			j--;
		}
	}
	reverse(lcs.begin(),lcs.end());
	return lcs;
}
 
 
void solve(){
	string s1,s2;
	while(cin >> s1 && cin >> s2){
		string lcss = lcs(s1,s2);
		string res = s1;
		int lp = 0;
		int lcsp = 0;
		for (int i = 0; i < s2.length() ; i++) {
			if (lcsp<lcss.length()&&lp<res.length()&&s2[i]==lcss[lcsp]) {
				while(res[lp]!=s2[i]){
					lp++;
				}
				lp++;
				lcsp++;
			}else {
				res.insert(lp, string(1,s2[i]));
				lp++;
			}
		}
		
		cout << res << "\n";
	}
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	freopen("text.in", "r", stdin);
 
	
//	freopen("task.in", "r", stdin);
//	freopen("task.out", "w", stdout);
////	
////	
//	int t;
//	cin >> t;
//	for(int ti = 1; ti <= t; ti++){
////		cout << "Case #" << ti  << ": ";
//		cout << ti << ". " ;
//		solve();
//	}
//	
	solve();
 
	
	
    return 0;
}
