#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


vector<int> bit;

void initbit(int n) {
    bit.clear();
    bit.resize(2*n+1,0);
}

void update(int i) {
    while (i<bit.size()) {
        bit[i]++;
        i+=i-(i&(i-1));
    }
}

int sum(int i, int j) {
    int sum = 0;
    while (j>0) {
        sum+=bit[j];
        j=j&(j-1);
    }
    i--;
    while(i>0) {
        sum-=bit[i];
        i=i&(i-1);
    }
    return sum;
} 

// max end of open segments
// 1 2 3 4 8 10
// 1st cast
//              mine ------
//    num of           --
// 2n case
//              mine -------
// num of       ---------------
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3));
    set<int> ss;
    for(int i=0;i<n;i++) {
        cin >> arr[i][0] >> arr[i][1];
        ss.insert(arr[i][0]);
        ss.insert(arr[i][1]);
        arr[i][2] = i;
    }
    map<int,int> mp;
    int i=1;
    for(auto &num:ss)
        mp[num]=i,i++;
    for(int i=0;i<n;i++)
        arr[i][0]=mp[arr[i][0]],arr[i][1]=mp[arr[i][1]];
    sort(arr.begin(), arr.end(), [](const vector<int>&a,const vector<int>&b) {
        if (a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    });
    vector<vector<int>> ans(2,vector<int>(n,0));
    initbit(n);
    for(int i=n-1;i>=0;i--) {
        ans[0][arr[i][2]]=sum(arr[i][0],arr[i][1]);
        update(arr[i][1]);
    }
    initbit(n);
    for(int i=0;i<n;i++) {
        ans[1][arr[i][2]]=sum(arr[i][1],2*n);
        update(arr[i][1]);
    }
    for(int j=0;j<2;j++) {
        for(int i=0;i<n;i++)
            cout << ans[j][i] << " ";
        cout << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
