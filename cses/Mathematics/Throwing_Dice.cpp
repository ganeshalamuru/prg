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


array<array<int,6>,6> matmul(auto& a, auto& b) {
    array<array<int,6>,6> res{};
    for(int i=0;i<6;i++) {
        for(int j=0;j<6;j++) {
            for(int z=0;z<6;z++) {
                res[i][j]=(res[i][j]+int((1ll*a[i][z]*b[z][j])%MOD))%MOD;
            }
        }
    }
    return res;
}


ll matmodpow(ll n) {
    // first 6 first of series including 0th term in reverse
    array<int,6> fterms{16,8,4,2,1,1};
    // last 6 terms fibonacci recurrence [f_n+6 f_n+5 .. f_n] = mat*[f_n+5 f_n+4 .. f+n-1]
    array<array<int,6>,6> mat = {1,1,1,1,1,1 , 1,0,0,0,0,0 , 0,1,0,0,0,0 , 
                                    0,0,1,0,0,0  ,  0,0,0,1,0,0,  0,0,0,0,1,0};
    array<array<int,6>,6> res{};
    for(int i=0;i<6;i++)
        res[i][i]=1;
    
    while (n>0) {
        if (n&1)
            res = matmul(res,mat);
        mat = matmul(mat,mat);
        n>>=1;
    }

    int ans = 0;
    for(int z=0;z<6;z++)
        ans = (ans+int((1ll*res[5][z]*fterms[z])%MOD))%MOD;
    return ans;

}


void solve() {
	ll n;
    cin >> n;
    cout << matmodpow(n) << "\n";
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
