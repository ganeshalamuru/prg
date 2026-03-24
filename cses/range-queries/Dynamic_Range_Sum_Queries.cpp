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


vector<ll>bit;

void update(int i, int val) {
    while (i<int(bit.size())) {
        bit[i]+=val;
        i+=(i&-i);
    }
}

ll sum(int a, int b) {
    ll ans = 0;
    while (b>0) {
        ans+=bit[b];
        b-=(b&-b);
    }
    a--;
    while(a>0) {
        ans-=bit[a];
        a-=(a&-a);
    }
    return ans;
}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    bit.resize(n+1);
    for(int i=1;i<=n;i++) {
        update(i,arr[i]);
    }
    while(q--) {
        int t,k,u,a,b;
        cin >> t;
        if (t==1) {
            cin >> k >> u;
            update(k,u-arr[k]);
            arr[k]=u;
        } else {
            cin >> a >> b;
            cout << sum(a,b) << "\n";
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
