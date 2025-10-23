#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

inline ll calc3segcost(ll a, ll b, ll c) {
    return max(a,max(b,c))-min(a,min(b,c));
}

void solve() {
	int n;
    cin >> n;
    vector<ll> arr(n);
    set<ll> ss;
    for(ll &x:arr)
        cin >> x,ss.insert(x);
    if (ss.size()==1) {
        cout << 0 << "\n";
        return;
    }
    if (n==3) {
        cout << calc3segcost(arr[0],arr[1],arr[2]) << "\n";
        return;
    }
    vector<vector<ll>> dp(3,vector<ll>(n,LLONG_MAX));
    dp[0][1] = abs(arr[1]-arr[0]);
    dp[0][2] = calc3segcost(arr[0],arr[1],arr[2]);
    dp[1][2] = abs(arr[2]-arr[1]);
    for(int i=3;i<n;i++) {
        
        // i,i-1 connected
        dp[0][i]=min(dp[0][i], dp[0][i-2]+abs(arr[i]-arr[i-1]));
        // i,i-1,i-2 
        if (dp[0][i-3]!=LLONG_MAX)
            dp[0][i]=min(dp[0][i], dp[0][i-3]+calc3segcost(arr[i],arr[i-1],arr[i-2]));
        
        // i,i-1 
        if (dp[1][i-2]!=LLONG_MAX)
            dp[1][i] = min(dp[1][i], dp[1][i-2]+abs(arr[i]-arr[i-1]));
        // i,i-1,i-2
        if (i==3) {
            dp[1][i] = calc3segcost(arr[1],arr[2],arr[3]);
        } else if (dp[1][i-3]!=LLONG_MAX){
            dp[1][i]=min(dp[1][i], dp[1][i-3]+calc3segcost(arr[i],arr[i-1],arr[i-2]));
        }

        //i,i-1
        if (i==3) {
            dp[2][i]=abs(arr[3]-arr[2]);
        } else if (dp[2][i-2]!=LLONG_MAX){
            dp[2][i]=min(dp[2][i],dp[2][i-2]+abs(arr[i]-arr[i-1]));
        }
        //i,i-1,i-2
        if (i==4) {
            dp[2][i] = calc3segcost(arr[2],arr[3],arr[4]);
        } else if (i>=5 && dp[2][i-3]!=LLONG_MAX){
            dp[2][i]=min(dp[2][i], dp[2][i-3]+calc3segcost(arr[i],arr[i-1],arr[i-2]));
        }


    }
    ll cost = LLONG_MAX;
    // n-1,n-2
    if (dp[0][n-3]!=LLONG_MAX)
        cost = min(cost, dp[0][n-3]+abs(arr[n-1]-arr[n-2]));
    // 0,n-1
    if (dp[1][n-2]!=LLONG_MAX)
        cost = min(cost, dp[1][n-2]+abs(arr[n-1]-arr[0]));
    
    // n-1,n-2,n-3
    if (dp[0][n-4]!=LLONG_MAX) {
        cost=min(cost,dp[0][n-4]+calc3segcost(arr[n-1],arr[n-2],arr[n-3]));
    }
    // 0,n-1,n-2
    if (dp[1][n-3]!=LLONG_MAX) {
        cost = min(cost,dp[1][n-3]+calc3segcost(arr[0],arr[n-1],arr[n-2]));
    }
    //0,1,n-1
    if (dp[2][n-2]!=LLONG_MAX) {
        cost = min(cost, dp[2][n-2]+calc3segcost(arr[0],arr[1],arr[n-1]));
    }
    cout << cost << "\n";

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
