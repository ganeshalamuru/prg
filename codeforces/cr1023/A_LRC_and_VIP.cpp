#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++) {
        cin >> arr[i][0];
        arr[i][1]=i;
    }
    sort(rall(arr));
    int maxgcd = arr[0][0];
    int gcdd = arr[1][0];
    for(int i=2;i<n;i++) {
        gcdd=__gcd(arr[i][0], gcdd);
    }
    if (maxgcd!=gcdd) {
        cout << "Yes\n";
        vector<int> ans(n,0);
        ans[arr[0][1]]=1;
        for(int i=1;i<n;i++) {
            ans[arr[i][1]]=2;
        }
        for(int i=0;i<n;i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "No\n";
    }

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
