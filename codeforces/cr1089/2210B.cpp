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
    while (i < int(bit.size())) {
        bit[i]+=val;
        i+=(i&-i);
    }
}

int sum(int i) {
    int res = 0;
    while (i>0) {
        res+=bit[i];
        i-=(i&-i);
    }
    return res;
}

int sumg(int l, int r) {
    if (l>r)
        return 0;
    return sum(r)-sum(l-1);
}

void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    bit.resize(n+1);
    fill(all(bit),0);
    int ans = INT_MIN;
    int lessumm = 0;
    for(int i=1;i<=n;i++) {
        ans = max(ans, sumg(i+1,n)+lessumm+1);
        if (arr[i]<=i)
            lessumm++;
        else
            update(arr[i],1);
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
