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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int start = arr[0];
    int endd = arr[n-1];
    arr.pop_back();
    arr.erase(arr.begin());
    sort(arr.begin(),arr.end());
    multiset<int,greater<int>> ms;
    int dominos=2;
    int i=0;
    int prevsz = start;
    while(i<arr.size() && endd>2*prevsz) {
        while (i<arr.size() && arr[i]<=2*prevsz) {
            ms.insert(arr[i]),i++;
        }
        if ((*ms.begin()) > prevsz) {
            prevsz=*ms.begin();
            ms.erase(ms.begin());
            dominos++;
        } else {
            cout << -1 << "\n";
            return;
        }
    }
    if (endd>2*prevsz) {
        cout << -1 << "\n";
    } else {
        cout << dominos << "\n";
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
