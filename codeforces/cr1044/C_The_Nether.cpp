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
    int maxlen = INT_MIN;
    string s = to_string(n)+" ";
    for(int i=1;i<=n;i++) {
        for(char &ch:to_string(i))
            s.push_back(ch);
        if (i!=n)
            s.push_back(' ');
    }
    for(int i=1,ml=0;i<=n;i++) {
        cout << "? "<< to_string(i) <<" " << s << "\n" << flush;
        cin >> ml;
        maxlen = max(maxlen, ml);
    }
    cout <<"!" <<maxlen << "\n";

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
