#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


vector<vector<int>> dp(30,vector<int>((30*29)/2 + 1,0));
void solve() {
	int n,k;
    cin >> n >> k;
    if (dp[n-1][k]==0) {
        cout << 0 << "\n";
        return;
    }
    vector<int> indices;
    int val=k,sz=n-1;
    while(val>0) {
        int oldval = val;
        val-=dp[sz][oldval]*(sz+1-dp[sz][oldval]);
        indices.push_back(dp[sz][oldval]-1);
        sz=dp[sz][oldval]-1;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++)
        ans[i]=i+1;
    int i=0,indsz=int(indices.size());
    reverse(all(indices));
    while(i<indsz) {
        int aind = indices[i],j=i;
        while(j<indsz && indices[j]==aind)
            aind++,j++;
        reverse(ans.begin()+indices[i], ans.begin()+aind+1);
        i=j;
    }
    for(int &num:ans)
        cout << num << " ";
    cout << "\n";
}


int main() {
    fast;
    int t = 1;
    cin >> t;
    dp[0][0]=1;
    for(int i=1;i<30;i++) {
        dp[i][0]=1;
        for(int j=1;j<=i;j++) {
            for(int z=0;z<=((j)*(j-1))/2;z++) {
                if (dp[j-1][z]!=0)
                    dp[i][z+j*(i+1-j)]=j;
            }
        }
    }
    while(t--){
    	solve();
    }
    return 0;
}
