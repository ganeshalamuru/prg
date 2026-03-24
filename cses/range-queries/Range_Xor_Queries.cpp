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

vector<int> bit;

void update(int i, int val) {
    while (i<int(bit.size())) {
        bit[i]^=val;
        i+=(i&-i);
    }
}

int xsum(int i) {
    int ans = 0;
    while (i>0) {
        ans^=bit[i];
        i-=(i&-i);
    }
    return ans;
}

int xorsum(int l, int r) {
    return xsum(r)^xsum(l-1); 
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
        update(i,arr[i]);
    }
    while (q--) {
        int a,b;
        cin >> a >> b;
        cout << xorsum(a,b) << "\n";
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
