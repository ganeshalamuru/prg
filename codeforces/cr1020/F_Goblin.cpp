#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

/*
110
000
011
*/
void solve(int n, string s) {
    // cout << "my: ";
    if (n==1) {
        if (s[0]=='0') {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
        return;
    }
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    if (s[0]=='0') {
        dp[0][1]=n-1;
    } else {
        dp[0][1]=1;
    }
    for(int i=1;i<n;i++) {
        if (s[i]=='0') {
            if (s[i-1]=='0') {
                dp[i][0]=dp[i-1][0]+i;
                dp[i][1]=dp[i-1][1]+n-1-i;
            } else {
                dp[i][0]=dp[i-1][1]+i;
                dp[i][1]=n-1-i;
            }
        } else {
            if (s[i-1]=='0') {
                dp[i][1]=dp[i-1][1]+1;
            } else {
                dp[i][1]=1;
            }
        }
    }
    ll ans = LLONG_MIN;
    for(int i=0;i<n;i++) {
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }
    cout << ans << "\n";

}

void solve2(int n,string s) {
    cout << "act: ";
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        grid[i]=s;
        grid[i][i]='0' + ((grid[i][i]-'0')^1);
    }
    vector<vector<int>> vis(n,vector<int>(n,0));
    function<void(int,int,int&)> dfs=[&](int x,int y,int &cnt) {
        vis[x][y]=1;
        cnt++;
        for(auto &[dx,dy]:vector<pii>{{-1,0},{0,1},{1,0},{0,-1}}) {
            int nx =  x+dx,ny=y+dy;
            if (nx<0 || nx>=n || ny<0 || ny>=n || vis[nx][ny]==1 || grid[nx][ny]!='0')
                continue;
            dfs(nx,ny,cnt);
        }
    };
    int ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (vis[i][j]!=0 || grid[i][j]!='0')
                continue;
            int cnt = 0;
            dfs(i,j,cnt);
            ans = max(ans,cnt);
        }
    }
    cout << ans << "\n";
}

/*
10010

00010
11010
10110
10000
10011

*/

int main() {
    fast;
    int t = 1;
    cin >> t;
    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1); // distribution in range [1, 6]
    //std::cout << dist6(rng) << std::endl;
    while(t--){
        int n;
        cin >> n;
        string s(n,'0');
        cin >> s;
        // for(int i=0;i<n;i++) {
        //     s[i]='0'+dist6(rng);
        // }
        //s="10010";
        //cout << s << "\n";
    	solve(n,s);
        //solve2(n,s);
    }
    return 0;
}
