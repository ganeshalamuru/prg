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
	ll n,k;
    cin >> n >> k;
    vector<ll> quo(n),rem(n);
    for(int i=0;i<n;i++)
        cin >> quo[i];
    for(int i=0;i<n;i++)
        cin >> rem[i];
    sort(all(quo));
    sort(all(rem));
    int i=0,j=n-1;
    int ans = 0;
    while(i<n && j>=0) {
        while(j>=0 && quo[j]*(rem[i]+1)+rem[i]>k)
            j--;
        if (j>=0) {
            i++,j--;
            ans++;
        } else {
            break;
        }
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
