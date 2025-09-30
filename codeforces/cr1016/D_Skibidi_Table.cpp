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
	int n,q;
    cin >> n >> q;
    while(q--) {
        string s;
        cin >> s;
        if (s[0]=='-') {
            int x,y;
            cin >> x >> y;
            x--,y--;
            pii r{0,(1<<n)-1},c{0,(1<<n)-1};
            string num;
            while(r.S-r.F>0 && c.S-c.F>0) {
                int rhlaf = r.F + (r.S-r.F+1)/2;
                int chalf = c.F + (c.S-c.F+1)/2;
                if (x<rhlaf && y<chalf) {
                    num.push_back('0'),num.push_back('0');
                    r = {r.F, rhlaf-1},c={c.F, chalf-1};
                } else if (x>=rhlaf && y>=chalf) {
                    num.push_back('0'),num.push_back('1');
                    r = {rhlaf, r.S},c={chalf, c.S};
                } else if (x>=rhlaf && y<chalf) {
                    num.push_back('1'),num.push_back('0');
                    r={rhlaf, r.S},c={c.F,chalf-1};
                } else {
                    num.push_back('1'),num.push_back('1');
                    r={r.F,rhlaf-1},c={chalf,c.S};
                }
            }
            cout << bitset<61>(num).to_ullong() + 1 << "\n";
        } else {
            ll d;
            cin >> d;
            d--;
            bitset<61> bs(d);
            pii r{0,(1<<n)-1},c{0,(1<<n)-1};
            for(int i=2*n-1;i>=0;i-=2) {
                int rhlaf = r.F + (r.S-r.F+1)/2;
                int chalf = c.F + (c.S-c.F+1)/2;
                if (bs[i]==0 && bs[i-1]==0) {
                    r={r.F,rhlaf-1},c={c.F,chalf-1};
                } else if (bs[i]==0 && bs[i-1]==1) {
                    r={rhlaf,r.S},c={chalf,c.S};
                } else if (bs[i]==1 && bs[i-1]==0) {
                    r={rhlaf,r.S},c={c.F,chalf-1};
                } else {
                    r={r.F,rhlaf-1},c={chalf,c.S};
                }
            }
            cout << r.F+1 << " " << c.F+1 << "\n";
        }
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
