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

const ll MOD = 1e9+7;


ll modpow(ll x, ll n) {
    if (n==0)
        return 1;
    ll res = 1;
    while (n>0) {
        if (n&1) {
            res = (res*x)%MOD;
        }
        x = (x*x)%MOD;
        n>>=1;
    }
    return res;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<ll>> mat(n,vector<ll>(m+1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m+1;j++) {
            cin >> mat[i][j];
        }
    }
    int numindpcol = 0;
    vector<int> tmp(n,-1);
    for(int i=0;i<m && numindpcol<n;i++) {
        int z=numindpcol;
        for(;z<n;z++) {
            if (mat[z][i]!=0)
                break;
        }
        if (z==n)
            continue;
        tmp[numindpcol]=i;
        swap(mat[numindpcol],mat[z]);
        ll modinvpele = modpow(mat[numindpcol][i],MOD-2);
        for(int j=i;j<=m;j++) {
            mat[numindpcol][j]=(modinvpele*mat[numindpcol][j])%MOD;
        }
        for(int j=numindpcol+1;j<n;j++) {
            ll multiplier = mat[j][i];
            for(int a=i;a<=m;a++) {
                mat[j][a]=(mat[j][a]-(multiplier*mat[numindpcol][a])%MOD + MOD)%MOD;
            }
        }
        numindpcol++;
    }
    vector<ll> variables(m,-1);

    for(int i=n-1;i>=0;i--) {
        if (tmp[i]==-1) {
            if (mat[i][m]!=0) {
                cout << -1 << "\n";
                return;
            }
            continue;
        }
        ll sum = 0;
        for(int j=m-1;j>tmp[i];j--) {
            if (variables[j]==-1) {
                variables[j]=0;
            } else {
                sum = (sum+(variables[j]*mat[i][j])%MOD)%MOD;
            }
        }
        variables[tmp[i]]=(mat[i][m]-sum+MOD)%MOD;
    }
    for(int i=0;i<m;i++) {
        if (variables[i]==-1) {
            cout << 0 << " ";
        } else {
            cout << variables[i] << " ";
        }
    }
    cout << flush << "\n";
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
