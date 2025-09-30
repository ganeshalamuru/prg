#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m,k;
    cin >> n >> m >> k;
    vector<pii> arr(k+1);
    for(int i=0;i<k+1;i++)
        cin >> arr[i].F >> arr[i].S;
    vector<vector<int>> dp(k+1,vector<int>(2,INT_MIN));
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<k+1;i++) {
        if (arr[i].F == arr[i].F) {
            int numpaths = 0;
            if (dp[i-1][0]!=INT_MIN) {
                numpaths+=dp[i-1][0];
            }
            if (dp[i-1][1]!=INT_MIN) {
                numpaths=(numpaths+dp[i-1][1])%mod;
            }
            if (numpaths!=0)
                dp[i-1][0]=numpaths;
            continue;
        }
        if (arr[i].S == arr[i].S) {
            int numpaths = 0;
            if (dp[i-1][0]!=INT_MIN) {
                numpaths+=dp[i-1][0];
            }
            if (dp[i-1][1]!=INT_MIN) {
                numpaths=(numpaths+dp[i-1][1])%mod;
            }
            if (numpaths!=0)
                dp[i-1][1]=numpaths;
            continue;
        }
        
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
