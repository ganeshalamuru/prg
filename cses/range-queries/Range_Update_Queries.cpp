#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;


vector<ll> bit;

void updatesingle(int i,int val) {
    while (i<int(bit.size())) {
        bit[i]+=val;
        i+=(i&-i);
    }
}

void update(int l,int r,int val) {
    updatesingle(l,val);
    updatesingle(r+1,-val);
}

ll sum(int i) {
    ll ans = 0;
    while (i>0) {
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    bit.resize(n+1);
    for(int i=1;i<=n;i++) {
        update(i,i,arr[i]);
    }
    while (q--) {
        int t,a,b,u,k;
        cin >> t;
        if (t==1) {
            cin >> a >> b >> u;
            update(a,b,u);
        } else {
            cin >> k;
            cout << sum(k) << "\n";
        }
    }
    


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
