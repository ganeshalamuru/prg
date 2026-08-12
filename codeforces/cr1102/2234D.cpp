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
    array<string,2> strs;
    cin >> strs[0] >> strs[1];
    array<ll,2>numbits{};
    for(int j=0;j<2;j++) {
        for(int i=0;i<n;i++) {
            if (strs[j][i]=='1')
                numbits[j]++;
        }
    }
    ll commonbits = 0;
    for(int i=0;i<n;i++) {
        if (strs[0][i]=='1' && strs[1][i]=='1')
            commonbits++;
    }
    ll times = ((1<<k)+1)/3;
    ll firsttwo = numbits[0]*(n-numbits[0])+numbits[1]*(n-numbits[1]);
    ll xorfirstwobits = numbits[0]+numbits[1]-2*(commonbits); 
    ll ans = (firsttwo+xorfirstwobits*(n-xorfirstwobits))*(times);
    if (k%2 == 0)
        ans += firsttwo;
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
