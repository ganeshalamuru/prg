#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

map<int,char> typeop{{0,'+'},{1,'*'}};
void construct(int n,int t,vector<vector<vector<int>>>&dp2, string &ans) {
    if (t==2) {
        for(auto &ch:to_string(n)) {
            ans.push_back(ch);
        }
        return;
    }
    int j=dp2[n][t][0],jt=dp2[n][t][1],rem=dp2[n][t][2],remt=dp2[n][t][3];
    if (t==0) {
        construct(j,jt,dp2,ans);
        ans.push_back(typeop[t]);
        construct(rem,remt,dp2,ans);
    } else {
        if (jt==2 && remt==2) {
            construct(j,jt,dp2,ans);
            ans.push_back(typeop[t]);
            construct(rem,remt,dp2,ans);
        } else if (jt==2) {
            construct(j,jt,dp2,ans);
            ans.push_back(typeop[t]);
            if (remt==0) {
                ans.push_back('(');
                construct(rem,remt,dp2,ans);
                ans.push_back(')');
            } else {
                construct(rem,remt,dp2,ans);
            }
        } else if (remt==2) {
            construct(rem,remt,dp2,ans);
            ans.push_back(typeop[t]);
            if (jt==0) {
                ans.push_back('(');
                construct(j,jt,dp2,ans);
                ans.push_back(')');
            } else {
                construct(j,jt,dp2,ans);
            }
        } else {
            if (jt==0) {
                ans.push_back('(');
                construct(j,jt,dp2,ans);
                ans.push_back(')');
            } else {
                construct(j,jt,dp2,ans);
            }
            ans.push_back(typeop[t]);
            if (remt==0) {
                ans.push_back('(');
                construct(rem,remt,dp2,ans);
                ans.push_back(')');
            } else {
                construct(rem,remt,dp2,ans);
            }
        }
    }

}

void solve() {
	int n;
    cin >> n;
    vector<vector<int>>dp(2001,vector<int>(3,INT_MAX));
    vector<vector<vector<int>>>dp2(2001,vector<vector<int>>(3,vector<int>(4)));
    vector<int>numbers{1,11,111,1111};
    for(int i=1;i<=n;i++) {
        if (auto itr = find(all(numbers),i);itr!=numbers.end()) {
            dp[i][2]=distance(numbers.begin(), itr)+1;
            continue;
        }
        // main operator is +
        for(int j=1;j<i;j++) {
            int jt=1,remt=1;
            int rem = i-j;
            int minjops = INT_MAX,minremops = INT_MAX;
            for(int z=0;z<3;z++) {
                if (dp[j][z]<minjops) {
                    jt=z;
                    minjops=dp[j][z];
                }
                if (dp[rem][z]<minremops) {
                    remt=z;
                    minremops=dp[rem][z];
                }
            }
            if (minjops+minremops+1<dp[i][0]) {
                dp[i][0]=min(dp[i][0], minjops+minremops+1);
                dp2[i][0]={j,jt,i-j,remt};
            }
        }
        //main operator is *
        dp[i][1]=4+dp[i][0];
        dp2[i][1]={1,1,i,0};
        for(int j=2;j<i;j++) {
            if (i%j!=0)
                continue;
            int rem = i/j;
            if (dp[j][2]!=INT_MAX && dp[rem][2]!=INT_MAX) {
                if (dp[j][2]+dp[rem][2]+1<dp[i][1]) {
                    dp[i][1]=1+dp[j][2]+dp[rem][2];
                    dp2[i][1]={j,2,rem,2};
                }
            } else if (dp[j][2]!=INT_MAX) {
                if (dp[j][2]+min(dp[rem][1]+1,dp[rem][0]+3) < dp[i][1]) {
                    dp[i][1]=dp[j][2]+min(dp[rem][1]+1,dp[rem][0]+3);
                    if (dp[rem][1]+1<=dp[rem][0]+3) {
                        dp2[i][1]={j,2,rem,1};
                    } else {
                        dp2[i][1]={j,2,rem,0};
                    }
                }
            } else if (dp[rem][2]!=INT_MAX) {
                if (dp[rem][2]+min(dp[j][1]+1,dp[j][0]+3)<dp[i][1]) {
                    dp[i][1]=dp[rem][2]+min(dp[j][1]+1,dp[j][0]+3);
                    if (dp[j][1]+1<=dp[j][0]+3) {
                        dp2[i][1]={j,1,rem,2};
                    } else {
                        dp2[i][1]={j,0,rem,2};
                    }
                }
            } else {
                if (dp[j][1]+min(dp[rem][1]+1,dp[rem][0]+3) < dp[i][1]) {
                    dp[i][1]=dp[j][1]+min(dp[rem][1]+1,dp[rem][0]+3);
                    if (dp[rem][1]+1<=dp[rem][0]+3) {
                        dp2[i][1]={j,1,rem,1};
                    } else {
                        dp2[i][1]={j,1,rem,0};
                    }
                }
                if (dp[j][0]+min(dp[rem][1]+3,dp[rem][0]+5) < dp[i][1]) {
                    dp[i][1]=dp[j][0]+min(dp[rem][1]+3,dp[rem][0]+5);
                    if (dp[rem][1]+3<=dp[rem][0]+5) {
                        dp2[i][1]={j,0,rem,1};
                    } else {
                        dp2[i][1]={j,0,rem,0};
                    }
                }
            }
        }
    }
    string ans = "";
    if (dp[n][2]!=INT_MAX) {
        construct(n,2,dp2,ans);
    } else if (dp[n][0]<=dp[n][1]) {
        construct(n,0,dp2,ans);
    } else {
        construct(n,1,dp2,ans);
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
