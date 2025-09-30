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
    vector<int>arr(n),freq(n+1,0);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }
    int i=0,mex=0;
    while(i<=n && freq[i]>0) {
        i++,mex++;
    }
    vector<int> ans(n+1,0);
    int prevfreq = 0,allremfreq = n;
    for(int i=0;i<=mex;i++) {
        ans[freq[i]]++;
        if (n-i+1<=n)
            ans[n-i+1]--;
        prevfreq+=freq[i];
    }
    int summ=0;
    for(int i=0;i<=n;i++) {
        summ+=ans[i];
        cout << summ << " ";
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
