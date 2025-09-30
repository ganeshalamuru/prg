#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


vector<int> fwt;

void update(int i) {
    while(i<fwt.size()) {
        fwt[i]++;
        i+=(i-((i-1)&i));
    }
}

int sum(int i) {
    int ans = 0;
    //cout << "incoming i" << i << "\n";
    while(i>0) {
        ans+=fwt[i];
        i-=(i-((i-1)&i));
    }
    //cout << "sum " << i << " " << ans << "\n";
    return ans;
}


void solve() {
    int n;
    cin >> n;
    fwt.resize(n+1);
    fill(all(fwt),0);
    vector<int> arr(n+1);
    vector<int> mp(n+1,0);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        mp[arr[i]]=i;
    }
    ll cnt = 0;
    for(int i=1;i<=n;i++) {
        int numgreater = mp[i]-1-sum(mp[i]);
        //cout << ":: "<< mp[i] << ":: " << ":: " << sum(mp[i]) << " " <<numgreater << "\n";
        cnt+=min(numgreater,n-i-numgreater);
        update(mp[i]);
    }
    cout << cnt << "\n";
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
