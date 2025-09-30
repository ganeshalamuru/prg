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
	int n,k;
    cin >> n >> k;
    vector<int>arr(n,0);
    map<int,int>freq;
    ll sum = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        freq[arr[i]]++;
        sum+=arr[i];
    }
    sort(rall(arr));
    if (arr[0]-arr.back()>k+1) {
        cout << "Jerry\n";
    } else if (arr[0]-arr.back()==k+1) {
        if (freq[arr[0]]>1) {
            cout << "Jerry\n";
        } else if((sum-1)%2==1) {
            cout << "Jerry\n";
        } else {
            cout << "Tom\n";
        }
    } else if (sum%2==1){
        cout << "Tom\n";
    } else {
        cout << "Jerry\n";
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
