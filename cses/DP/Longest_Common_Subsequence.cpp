#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(2,vector<int>{0});
    for(int i=1,x;i<=n;i++)
        cin >> x,arr[0].push_back(x);
    for(int i=1,x;i<=m;i++)
        cin >> x,arr[1].push_back(x);
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (arr[0][i]==arr[1][j]) {
                dp[i][j]=1+dp[i-1][j-1];
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<int>ans;
    int i=n,j=m;
    while(ans.size()<dp[n][m]) {
        if (arr[0][i]==arr[1][j]) {
            ans.push_back(arr[0][i]);
            i--,j--;
        } else if (dp[i][j]==dp[i-1][j]) {
            i--,j;
        } else {
            i,j--;
        }
    }
    reverse(all(ans));
    cout << ans.size() << "\n";
    for(int &num:ans) {
        cout << num << " ";
    }

}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
