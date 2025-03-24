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



vector<ll> bit;

void update(int i, ll val) {
    while(i<bit.size()) {
        bit[i]+=val;
        i+=i-(i&(i-1));
    }
}

ll sum(int i) {
    ll s=0;
    while(i>0) {
        s+=bit[i];
        i=(i&(i-1));
    }
    return s;
}

void solve(vector<int>&arr, int n) {
    vector<queue<int>> nums(n+2);
    for(int i=0;i<n;i++)
        nums[arr[i]].push(i);
    vector<int>prefixans(n,0);
    set<int> ss;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if (ss.find(arr[i]) != ss.end()) {
            prefixans[i]=ans;
            continue;
        }
        auto mitr = ss.find(arr[i]-1), pitr = ss.find(arr[i]+1);
        if (mitr == ss.end() && pitr ==ss.end())
            ans++;
        else if (mitr !=ss.end() && pitr!=ss.end())
            ans--;
        prefixans[i]=ans;
        ss.insert(arr[i]);
    }
    bit=vector<ll>(n+1,0);
    ll progsum = 0;
    for(int i=0;i<n;i++)
        progsum+=prefixans[i];
    ll finalsum = progsum;
    for(int i=0;i<n-1;i++) {
        progsum-=(prefixans[i]+sum(i+1));
        int num = arr[i];
        nums[num].pop();
        vector<int> inds;
        for(int d:{-1,0,1})
            if (!nums[num+d].empty())
                inds.push_back(nums[num+d].front());
        update(i+2,-1);
        progsum+=(-1*(n-(i+2)+1));
        sort(inds.begin(), inds.end());
        if (!inds.empty()) {
            update(inds[0]+1,1);
            progsum+=(1*(n-(inds[0]+1)+1));
            if (nums[num].empty() && inds.size()==2) {
                update(inds[1]+1,1);
                progsum+=(1*(n-(inds[1]+1)+1));
            }
            if (inds.size()>2 && inds[2]==nums[num].front()) {
                update(inds[1]+1,1);
                update(inds[2]+1,-1);
                progsum+=(1*(inds[2]-inds[1]));
            }
        }
        finalsum+=progsum;
    }
    cout <<finalsum << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin >> arr[i];
    	solve(arr, n);
    }
    return 0;
}
