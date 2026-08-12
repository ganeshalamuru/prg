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
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    stack<ll> lstk, lorstk, rstk, rorstk;
    ll genx = x;
    for(int i=1;i<k;i++) {
        rstk.push(genx);
        if (rorstk.empty()) {
            rorstk.push(genx);
        } else {
            rorstk.push(rstk.top()|rorstk.top());
        }
        genx = (genx*a+b)%c;
    }
    ll ans = 0;
    for(int i=k;i<=n;i++) {
        rstk.push(genx);
        if (rorstk.empty()) {
            rorstk.push(genx);
        } else {
            rorstk.push(rstk.top()|rorstk.top());
        }
        ll rangeor = (lorstk.empty()?0:lorstk.top()) | rorstk.top();
        ans^=rangeor;
        if (lstk.empty()) {
            while (!rstk.empty()) {
                lstk.push(rstk.top());
                if (lorstk.empty()) {
                    lorstk.push(genx);
                } else {
                    lorstk.push(lstk.top()|lorstk.top());
                }
                rstk.pop();
                rorstk.pop();
            }
        }
        lstk.pop();
        lorstk.pop();
        genx = (genx*a+b)%c;
    }

    cout << ans << "\n";


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
