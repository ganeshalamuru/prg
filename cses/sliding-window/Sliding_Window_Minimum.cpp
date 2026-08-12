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



void solve() {
	int n,k;
    cin >> n >> k;
    int x,a,b,c;
    cin >> x >> a >> b >>c;
    int genx = x;
    deque<pii> dq;
    for(int i=1;i<k;i++) {
        while (!dq.empty() && dq.back().S>=genx)
            dq.pop_back();
        dq.push_back({i,genx});
        genx=int((1ll*genx*a+b)%c);
    }
    int xorwmins = 0;
    for(int i=k;i<=n;i++) {
        while (!dq.empty() && dq.back().S>=genx)
            dq.pop_back();
        dq.push_back({i,genx});
        if (i-dq.front().F>=k)
            dq.pop_front();
        xorwmins^=dq.front().S;
        genx=int((1ll*genx*a+b)%c);
    }
    cout << xorwmins << "\n";
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
