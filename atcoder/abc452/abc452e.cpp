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

const int mod = 998244353;

int madd(int a, int b) {
    a%=mod,b%=mod;
    return (a+b)%mod;
}
int mmul(int a, int b) {
    a%=mod,b%=mod;
    return int((1ll*a*b)%mod);
}
int msub(int a, int b) {
    a%=mod,b%=mod;
    return(a-b+mod)%mod;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
        cin >> b[i];
    vector<int>psuma(n+1),ppsuma(n+1);
    for(int i=1;i<=n;i++)
        psuma[i]=madd(psuma[i-1],a[i]);
    for(int i=1;i<=n;i++)
        ppsuma[i]=madd(ppsuma[i-1],psuma[i]);
    int ans = 0; 
    for(int j=2;j<=m;j++) {
        int tmp = 0;
        for(int z=j;z<=n;z+=j)
            tmp = madd(tmp,mmul(b[j],msub(mmul(j,psuma[z-1]),msub(ppsuma[z-1],ppsuma[max(0,z-1-j)]))));
        if (n%j!=0) {
            int md = n%j;
            tmp = madd(tmp,mmul(b[j],msub(mmul(md,psuma[n]),msub(ppsuma[n-1],ppsuma[n-1-md]))));
        }
        ans = madd(ans, tmp);
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
