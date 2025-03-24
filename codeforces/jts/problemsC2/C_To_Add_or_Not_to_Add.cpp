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


int findnumberwithfreq(vector<int> &arr, vector<ll>&psum, int freq, int k) {
    int n = arr.size();
    int i=0;
    while(i<n) {
        int num = arr[i];
        while(i<n && arr[i]==num)
            i++;
        int l = 0, r = i-1;
        while(l<r) {
            int mid = l + (r-l)/2;
            ll sum = psum[i-1];
            if (mid-1>=0)
                sum -= psum[mid-1];
            if (1ll*num*(i-mid)-sum<=k)
                r=mid;
            else
                l=mid+1;
        }
        if (i-l>=freq)
            return num;
    }
    return INT_MAX;
}

void solve() {
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(auto &num:arr)
        cin >> num;
    sort(arr.begin(), arr.end());
    vector<ll> psum(n);
    psum[0] = arr[0];
    for(int i=1;i<n;i++)
        psum[i] = psum[i-1] + arr[i];
    int l=1,r=n;
    while(l<r) {
        int mid = l + (r-l+1)/2;
        int numwithfreq = findnumberwithfreq(arr, psum, mid, k);
        if (numwithfreq == INT_MAX)
            r = mid - 1;
        else
            l = mid;
    }
    cout << l << " " << findnumberwithfreq(arr, psum, l, k) << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
