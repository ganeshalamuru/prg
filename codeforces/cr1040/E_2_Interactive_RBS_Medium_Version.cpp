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
    int initscore = 0,score=0;
    cout << "? " << n << " ";
    for(int i=1;i<=n;i++) {
        cout << i << " \n"[i==n];
    }
    cout << flush;
    cin >> initscore;
    if (initscore==0) {
        int l=1,r=n-1;
        while(l<r) {
            int mid = l+(r-l+1)/2;
            cout << "? "<< 2 << " " << n << " " << mid << "\n" << flush;
            cin >> score;
            if (score==1) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        cout << "! ";
        for(int i=1;i<=l;i++) {
            cout << ")";
        }
        for(int i=l+1;i<=n;i++) {
            cout << "(";
        }
        cout << "\n" << flush;
    } else {
        int l=1,r=n;
        while(l<r) {
            int mid = l + (r-l)/2;
            cout << "? " << mid << " ";
            for(int i=1;i<=mid;i++) {
                cout << i << " \n"[i==mid];
            }
            cout << flush;
            cin >> score;
            if (score == 0) {
                l=mid+1;
            } else {
                r=mid;
            }
        }
        int closebind=l;
        string ans="";
        for(int i=1;i<=n;i+=6) {
            int diff = min(5,n-i);
            cout << "? " << 3*((1<<(diff+1))-1) << " ";
            for(int j=i,freq=1<<diff;j<=i+diff;j++,freq>>=1) {
                for(int z=0;z<freq;z++) {
                    cout << j << " " << closebind << " " << closebind << " \n"[(z==freq-1)&&(j==i+diff)];
                }
            }
            cout << flush;
            cin >> score;
            for(int j=diff;j>=0;j--) {
                if ((score>>j)&1) {
                    ans.push_back('(');
                } else {
                    ans.push_back(')');
                }
            }
        }
        cout << "! " << ans << "\n" << flush;
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
