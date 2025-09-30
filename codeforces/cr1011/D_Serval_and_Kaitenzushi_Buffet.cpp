#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int k,n;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    int i=n-k,maxpicks=1;
    multiset<int> ss;
    while(i>=1) {
        multiset<int> tss;
        for(int j=1;i>=1&&j<=k+1;j++,i--) {
            tss.insert(arr[i]);
            if (tss.size()>maxpicks)
                tss.erase(tss.begin());
        }
        for(auto &val:tss) {
            ss.insert(val);
            if (ss.size()>maxpicks)
                ss.erase(ss.begin());
        }
        maxpicks++;
    }
    cout << accumulate(all(ss),0ll) << "\n";


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
