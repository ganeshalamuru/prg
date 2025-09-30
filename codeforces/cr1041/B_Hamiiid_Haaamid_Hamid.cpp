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
	int n,x;
    cin >> n >> x;
    x--;
    string s;
    cin >> s;
    if (x==0 || x==n-1) {
        cout << 1 << "\n";
        return;
    }
    int nl=-1,i=x,nr=n,j=x;
    while(i>=0 && s[i]=='.')
        i--;
    nl=i;
    while(j<n && s[j]=='.')
        j++;
    nr=j;
    if (nl==-1 && nr==n) {
        cout << 1 << "\n";
    } else if (nl!=-1 && nr==n) {
        cout << min(nl+2, n-x) << "\n";
    } else if (nl==-1 && nr !=n ){
        cout << min(x+1, n-nr+1) << "\n";
    } else {
        if (nl+2<n-nr+1) {
            cout << min(x+1,n-nr+1) << "\n";
        } else {
            cout << min(nl+2, n-x) << "\n";
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
