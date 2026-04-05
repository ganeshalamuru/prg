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
	int n;
    cin >> n;
    vector<int> arr(n),arr2(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++) {
        cin >> arr2[i];
    }
    int ans = 0;
    if (__gcd(arr[0],arr[1])<arr[0])
        ans++;
    for(int i=1;i<n-1;i++) {
        int g1 = __gcd(arr[i-1],arr[i]), g2 = __gcd(arr[i],arr[i+1]);
        if (g1==arr[i] || g2 == arr[i])
            continue;
        int lcmm = g1*g2/__gcd(g1,g2);
        if (lcmm<arr[i] && __gcd(arr[i-1],lcmm)==g1 && __gcd(lcmm,arr[i+1])==g2)
            ans++;
    }
    if (__gcd(arr[n-2],arr[n-1])<arr[n-1])
        ans++;
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
