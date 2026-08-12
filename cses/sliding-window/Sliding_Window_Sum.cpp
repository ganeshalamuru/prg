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
	int k,n;
    cin >> n >> k;
    ll x,a,b,c;
    cin >> x >> a >> b >> c;
    ll cursum = x,genx = x;
    for(int i=2;i<k;i++) {
        genx=(genx*a+b)%c;
        cursum+=genx;
    }
    ll prevkval = x,xorwsum = 0;
    for(int i=k;i<=n;i++) {
        genx=(genx*a+b)%c;
        cursum+=genx;
        xorwsum^=cursum;
        cursum-=prevkval;
        prevkval=(prevkval*a+b)%c;
    }
    cout << xorwsum << "\n";

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
