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

const int MOD = 1e9+7;

array<array<int,2>,2> matmul(auto a, auto b) {
    array<array<int,2>,2> res{};
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            for(int z=0;z<2;z++) {
                res[i][j]= (res[i][j]+int((1ll*a[i][z]*b[z][j])%MOD))%MOD;
            }
        }
    }
    return res;
}

ll matrimodpow(ll n) {
    array<array<int,2>,2> mat{ 1,1 , 1,0 };
    array<array<int,2>,2> res{ 1,0 , 0,1 };
    while (n>0) {
        if (n&1)
            res = matmul(res,mat);
        mat = matmul(mat,mat);
        n>>=1;
    }
    return res[1][0]; 
}

void solve() {
	ll n;
    cin >> n;
    if (n<2) {
        cout << n << "\n";
        return;
    }
    cout << matrimodpow(n) << "\n";

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
