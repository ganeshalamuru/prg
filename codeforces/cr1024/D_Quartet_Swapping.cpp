#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


// 3 2 1 4 -> 1 4 3 2
// 3 2 1 4 5 -> 1 4 3 2 5 -> 1 2 5 4 3
void solve() {
	int n;
    cin >> n;
    vector<pii> even,odd;
    for(int i=1,x;i<=n;i++) {
        cin >> x;
        if (i%2==1)
            odd.push_back({x,i});
        else
            even.push_back({x,i});
    }
    sort(all(odd));
    sort(all(even));
    int i=0,j=0;
    vector<int> ans{-1};
    int oddturn = 1;
    while(i<odd.size() && j<even.size() && odd.size()-i+even.size()-j>=4) {
        if (oddturn==1) {
            ans.push_back(odd[i].F);
            i++;
        } else {
            ans.push_back(even[j].F);
            j++;
        }
        oddturn^=1;
    }
    
    for(int z=1;z<=n;z++) {
        cout << ans[z] << " ";
    }
    cout << "\n";

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
