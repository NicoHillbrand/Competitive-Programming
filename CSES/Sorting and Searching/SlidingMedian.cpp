#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
#define INF INT_MAX;
 
 
int n, k, med=-1, a[200005];
multiset<int> s1, s2;
 
 
void ps(){
	for(auto it : s1){
		cout << it << "\n";
		
	}
	cout << "\n";
	
	for(auto it : s2){
		cout << it << "\n";
		
	}
	cout << "\n";
	cout << "\n";
	
}
 
void fix(){
	int s = 1+s1.size()+s2.size();
	if (s1.size()<s/2-1) {
		s1.insert(*s2.begin());
		s2.erase(s2.begin());
	}
	if (s1.size()>s/2-1) {
		s2.insert(*--s1.end());
		s1.erase(--s1.end());
	}
}
 
 
void insert(int a){
	if (a<med) {
		s1.insert(a);
	}else {
		s2.insert(a);
	}
	fix();
	med = *s2.begin();
}
 
void remove(int a){
	if (a<med) {
		s1.erase(s1.find(a));
	}else {
		s2.erase(s2.find(a));
	}
	fix();
	med = *s2.begin();
}
 
 
 
void solve(){
	
	cin >> n >> k;
	
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	if (k==1) {
		for (int i = 0; i < n ; i++) {
			if (i==n-1) {
				cout << a[i] << "\n";
				
			}else {
				cout << a[i] << " ";
				
			}
		}
		return;
	}
	
 
	for (int i = 0; i < k; i++) {
		insert(a[i]);
	}
 
	cout << med << " ";
	for (int i = k; i < n; i++) {
		
		remove(a[i-k]);
		insert(a[i]);
		
		if (i==n-1) {
			cout << med << "\n";
		}else {
			cout << med << " ";
		}
	}
	
}
 
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
//    freopen("text.in", "r", stdin);
	
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
