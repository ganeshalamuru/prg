#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    int gcdd = 1;
    // iterate over smallest element in opt sol
    for(int i=0;i<=k;i++) {
        // check if arr[i],arr[i]/2,arr[i]/3 can be gcd
        for(int z=1;z<=3;z++) {
            if (arr[i]%z!=0)
                continue;
            int removenum = 0,posgcd=arr[i]/z;
            for(int j=0;j<=3;j++) {
                auto itrju = upper_bound(all(arr),j*posgcd);
                auto itrj1l = lower_bound(all(arr),(j+1)*posgcd);
                removenum+=int(distance(itrju,itrj1l));        
            }
            if (removenum <= k) {
                gcdd=max(posgcd,gcdd);
                break;
            }
        }
        gcdd=max(gcdd,arr[i]/4);
    }
    
    cout << gcdd << "\n";

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
