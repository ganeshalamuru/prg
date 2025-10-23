#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    vector<int>pow2m1(n+1,0);
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++) {
        int j=31;
        while((arr[i]>>j)==0) j--;
        if (arr[i]==(1<<j)) {
            ans[i]=ans[i-1] + j;
            pow2m1[i]=pow2m1[i-1];
        } else {
            ans[i]=ans[i-1]+j+1;
            pow2m1[i]=pow2m1[i-1];
            if (((arr[i]-1)&(arr[i]-2))==0)
                pow2m1[i]++;
        }
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        int numpw2m1 = pow2m1[r]-pow2m1[l-1];
        cout << ans[r]-ans[l-1] - ((numpw2m1+1)/2) << "\n";
        
    }
    
}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}