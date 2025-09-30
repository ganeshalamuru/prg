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
	string s;
    cin >> s;
    int cnt = 0;
    string ans;
    for(int i=0;i<s.size();i++) {
        if (s[i]=='T')
            cnt++;
        else
            ans.push_back(s[i]);
    }
    if (cnt == 0) {
        cout << s << "\n";
    } else {
        cout << string(cnt,'T')<<ans << "\n";
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
