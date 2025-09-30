#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;
 
// Bin packing problem https://en.wikipedia.org/wiki/Bin_packing_problem
// https://codeforces.com/blog/entry/70018
void solve() {
	int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<pii> dp(1<<n);
    dp[0]={0,x};
    for(int j=1;j<(1<<n);j++) {
        pii minn={INT_MAX,INT_MAX};
        for(int z=0;z<n;z++) {
            if (((j>>z)&1)!=1)
                continue;
            pii pp = dp[j^(1<<z)];
            if (pp.S+arr[z]<=x) {
                if (pp.F<minn.F)
                    minn={pp.F,pp.S+arr[z]};
                else if (pp.F==minn.F)
                    minn={pp.F,min(minn.S,pp.S+arr[z])};
            } else if(pp.F+1<=minn.F) {
                if (pp.F+1<minn.F)
                    minn={pp.F+1,arr[z]};
                else
                    minn={pp.F+1,min(minn.S,arr[z])};
            }
        }
        dp[j]=minn;
    }
    cout << dp[(1<<n)-1].F << "\n";
}
 
 
int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}