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
	int n,j,k;
    cin >> n >> j >> k;
    j--;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    if (k>1) {
        cout << "Yes\n";
    } else if (arr[j]==(*max_element(arr.begin(), arr.end()))) {
        cout << "Yes\n";
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
