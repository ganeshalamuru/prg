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


int numsplits(vector<int>&indarr, int num) {
    int spilts=0;
    if (num>1 && indarr[num-1]<indarr[num])
        spilts++;
    if (num+1<indarr.size() && indarr[num]<indarr[num+1])
        spilts++;
    return spilts;
}

int numcombines(vector<int> &indarr, int num) {
    int numcombines = 0;
    if (num>1 && indarr[num-1]<indarr[num])
        numcombines++;
    if (num+1<indarr.size() && indarr[num]<indarr[num+1])
        numcombines++;
    return numcombines;
}

void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> arr(n+1), indarr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i],indarr[arr[i]]=i;
    int ans =0,i=1;
    while(i<=n) {
        int pind = indarr[i];
        while(i<=n && pind<=indarr[i])
            pind=indarr[i],i++;
        ans++;
    }
    while(m--) {
        int a,b;
        cin >> a >> b;
        if (a==b) {
            cout << ans << "\n";
            continue;
        } else if (arr[a]>arr[b]) {
            swap(a,b);
        }
        int numa = arr[a],numb=arr[b];
        ans+= numsplits(indarr, numa)+numsplits(indarr, numb);
        if (numb==numa+1 && indarr[numa]<indarr[numb])
            ans--;
        swap(indarr[numa], indarr[numb]);
        ans-= numcombines(indarr,numa)+numcombines(indarr, numb);
        if (numb==numa+1 && indarr[numa]<indarr[numb])
            ans++;
        swap(arr[a], arr[b]);
        cout << ans << "\n";
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
