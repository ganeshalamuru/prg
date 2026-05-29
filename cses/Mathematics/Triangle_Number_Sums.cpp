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


 
void solve(vector<ll>&tns) {
    ll n;
    cin >> n;
    auto itr = lower_bound(all(tns),n);
    if ((*itr) == n) {
        cout << 1 << "\n";
        return;
    }
    n=8*n+2;
    for(ll i=1;i*i<n;i+=2) {
        ll req = n-i*i;
        ll reqsqrt = ll(sqrtl(req));
        if (req%2 && reqsqrt*reqsqrt == req) {
            cout << 2 << "\n";
            return;
        }
    }
 
 
    cout << 3 << "\n";
 
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;
    vector<ll> arr(1'415'000);
    for(int i=1;i<int(arr.size());i++)
        arr[i]=(1ll*i*(i+1))/2;
    while(t--) {
    	solve(arr);
    }
    
    return 0;
}
