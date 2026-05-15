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


vector<ll> fact(21);



void solve() {
	ll t,n,k;
    cin >> t >> n;
    if (t==1) {
        cin >> k;
        ll curpermno = 0;
        vector<int> res(n+1);
        vector<int> used(n+1,0);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if (used[j]!=0)
                    continue;;
                if (k<=curpermno+fact[n-i]) {
                    res[i]=j;
                    used[j]=1;
                    break;
                } else {
                    curpermno+=fact[n-i];
                }
            }
        }
        for(int i=1;i<=n;i++) {
            cout << res[i] << " \n"[i==n];
        }
    } else {
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        ll ans = 0;
        vector<int> used(n+1,0);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if (used[j]!=0)
                    continue;
                if (arr[i]==j) {
                    used[j]=1;
                    break;
                }
                ans+=fact[n-i];
            }
        }
        cout << ans+1 << "\n";
    }



}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    fact[0] = 1;
    for(int i=1;i<21;i++) {
        fact[i]=fact[i-1]*i;
    }

    while(t--) {
    	solve();
    }
    
    return 0;
}
