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
#define ts to_string
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
 
 
 
const int maxn = 2e5;
int n,q;
typedef struct Node Node;
struct Node{
	int nend = 0;
	int nc=0;
	map<char,Node*> children;
};
 
 
void dfs(Node* node){
	int endbelow = node->nend;
	if (node->children.empty()) {
		node->nc = endbelow;
		return;
	}
	for(auto it : node->children){
		dfs(it.second);
		endbelow+= it.second->nc;
	}
	node->nc = endbelow;
}
 
 
void solve(){
	cin >> n >> q;
	Node trie;
	Node* cur;
	for (int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		cur = &trie;
		for(int j = 0; j < s.size(); j++){
			if (j<s.size()-1) {
				if (cur->children.find(s[j])!=cur->children.end()) {
					cur = cur->children.find(s[j])->second;
				}else {
					Node* newnode = new Node;
					cur->children.insert(mp(s[j],newnode));
					cur = newnode;
				}
			}else {
				if (cur->children.find(s[j])!=cur->children.end()) {
					cur = cur->children.find(s[j])->second;
					cur->nend++;
				}else {
					Node* newnode = new Node;
					newnode->nend = true;
					cur->children.insert(mp(s[j],newnode));
					cur = newnode;
				}
			}
		}
	}
 
	dfs(&trie);
 
	for (int i = 0; i < q ; i++) {
		string s;
		cin >> s;
		cur = &trie;
		bool exists = 1;
		for(int j = 0; j < s.size(); j++){
			if (cur->children.find(s[j])!=cur->children.end()) {
				cur = cur->children.find(s[j])->second;
			}else {
				exists = 0;
				break;
			}
		}
		if (exists) {
			cout << cur->nc << "\n";
		}else {
			cout << "0" << "\n";
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
