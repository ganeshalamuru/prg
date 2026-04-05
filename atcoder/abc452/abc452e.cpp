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
    return (1ll*a*b)%mod;
}
int msub(int a, int b) {
    a%=mod,b%=mod;
    return(a-b+mod)%mod;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i=1;i<=m;i++) {
        cin >> b[i];
    }
    vector<int>psumb(n+1),psuma(n+1);
    for(int i=1;i<=n;i++) {
        psuma[i]=madd(psuma[i-1],b[i])%mod;
    }
    for(int i=1;i<=m;i++) {
        psumb[i]=madd(psumb[i-1],b[i])%mod;
    }
    int ans = 0;
    for(int i=1;i<=min(m,n);i++) {
        ans = madd(ans,mmul(i,mmul(a[i],psumb[m]-psumb[i])));
    }
    for(int j=2;j<=min(m,n);j++) {
        int tmp = 0;
        for(int z=j;z<=m;z+=j)
            tmp = madd(tmp, a[z]);
        ans = madd(ans,mmul(b[j],msub(psuma[n]-psuma[j],tmp)));
    }



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
