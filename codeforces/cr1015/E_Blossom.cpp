#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


vector<int> fact(5001,0);
vector<vector<int>> nCr(5001,vector<int>(5001,0));
vector<vector<int>> pnumm(5001,vector<int>(5001,0));
void solve() {
    int n;
    cin >> n;
    vector<int>arr(n);
    int negcnt = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        negcnt+=(arr[i]==-1);
    }
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
        if(arr[i]!=-1) 
            vis[arr[i]]=1;
    
    int missing=0;
    vector<int> missingarr(n+1,0);
    for(int i=1;i<=n;i++) {
        missing+=(vis[i-1]==0);
        missingarr[i]=missing;
        for(int j=0;j<=n;j++) {
            int curval = ((1ll*nCr[j][missing]*fact[missing])%mod);
            curval=(1ll*curval*fact[negcnt-missing])%mod;
            pnumm[j][i]=(curval+pnumm[j][i-1])%mod;
        }
    }
    vector<int> pmin(n,INT_MAX),smin(n,INT_MAX);
    int curmin = INT_MAX;
    for(int i=0;i<n;i++) {
        if(arr[i]!=-1)
            curmin=min(curmin,arr[i]);
        pmin[i]=curmin;
    }
    curmin=INT_MAX;
    for(int i=n-1;i>=0;i--) {
        if (arr[i]!=-1)
            curmin=min(curmin,arr[i]);
        smin[i]=curmin;
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        int snegcnt = 0;
        for(int j=i;j<n;j++) {
            snegcnt+=arr[j]==-1;
            int outsegmin = INT_MAX;
            auto itr = upper_bound(all(missingarr),snegcnt);
            itr--;
            if (i-1>=0)
                outsegmin=min(outsegmin,pmin[i-1]);
            if (j+1<n)
                outsegmin=min(outsegmin,smin[j+1]);
            int maxmex = min(outsegmin, (int)distance(missingarr.begin(), itr));    
            ans = (ans+pnumm[snegcnt][maxmex])%mod;
        }
    }
    cout << ans << "\n";
    
}


int main() {
    fast;
    int t = 1;
    cin >> t;
    fact[0]=1;
    for(int i=1;i<5001;i++) {
        fact[i]=(1ll*fact[i-1]*i)%mod;
    }
    nCr[0][0]=1;
    for(int i=1;i<5001;i++)
        nCr[i][0]=1;
    for(int i=1;i<5001;i++) {
        for(int j=1;j<5001;j++) {
            nCr[i][j]=(nCr[i-1][j]+nCr[i-1][j-1])%mod;
        }
    }
    while(t--){
    	solve();
    }
    return 0;
}
