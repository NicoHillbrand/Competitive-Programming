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
int n;
ll a[maxn];
vector<ll> seg;
vector<ll> lazy;
 
ll neutral = 0;
ll merge(ll a, ll b){
	return a+b;
}
 
void build(int v, int tl , int tr){
	if (tl==tr) {
		seg[v] = a[tl];
	}else {
		int mid = (tl+tr)/2;
		build(v*2,tl,mid);
		build(v*2+1,mid+1,tr);
		seg[v] = merge(seg[v*2],seg[v*2+1]);
	}
}
 
void construct(){
	seg.resize(4*n,neutral);
	lazy.resize(4*n,0);
	build(1,0,n-1);
}
 
void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        seg[v] = x;
    }else {
        int mid = (tl + tr) / 2;
        if (pos <= mid){
            update(v*2, tl, mid, pos, x);
        }else{
            update(v*2+1, mid+1, tr, pos, x);
        }
        seg[v] = merge(seg[v*2],seg[v*2+1]);
    }
}
 
ll query(int v, int tl, int tr, int l, int r){
	if (lazy[v]!=0) {
		seg[v] += (tr-tl+1)*lazy[v];
		if (tl!=tr) {
			lazy[v*2] += lazy[v];
			lazy[v*2+1] += lazy[v];
		}
		lazy[v] = 0;
	}
	if (l<=tl&&tr<=r) {
		return seg[v];
	}
	if (l>tr||r<tl) {
		return neutral;
	}
	int mid = (tl+tr)/2;
	return merge(query(v*2,tl,mid,l,r),query(v*2+1,mid+1,tr,l,r));
}
 
 
void updateRange(int v, int tl, int tr, int l, int r, int x){
	//push away previous lazy value
	if (lazy[v]!=0) {
		seg[v] += (tr-tl+1)*lazy[v];
		if (tl!=tr) {
			lazy[v*2] += lazy[v];
			lazy[v*2+1] += lazy[v];
		}
		lazy[v] = 0;
	}
	//out of range
	if (tl>r||tr<l) {
		return;
	}
	//completely in range
	if (l<=tl&&tr<=r) {		
		seg[v] += (tr-tl+1)*x;
		if (tl!=tr) {
			lazy[v*2] += x;
			lazy[v*2+1] += x;
		}
		return;
	}
	//partially in range
	int mid = (tl+tr)/2;
	updateRange(v*2, tl, mid, l, r, x);
	updateRange(v*2+1, mid+1, tr, l, r, x);
	seg[v] = seg[v*2]+seg[v*2+1];
}
 
 
 
void solve(){
	int q;
	cin >> n >> q;
	for (int i = 0; i < n ; i++) {
		cin >> a[i];
	}
	
	construct();
	
	for (int i = 0; i < q ; i++) {
		int type;
		cin >> type;
		if (type==1) {
			int l,r,x;
			cin >> l >> r >> x;
			l--;
			r--;
			updateRange(1,0,n-1,l,r,x);
		}else {
			int l;
			cin >> l;
			l--;
			cout << query(1,0,n-1,l,l) << "\n";
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
