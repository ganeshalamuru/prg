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
	int n;
    cin >> n;
    vector<int>a(n),b(n);
    ll suma=0,sumb=0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        suma+=a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
        sumb+=b[i];
    }
    if (suma==sumb) {
        sort(all(a)),sort(all(b));
        if (a==b) {
            cout << *max_element(all(a))+1 << "\n"; 
        } else {
            cout << -1 << "\n";
        }
        return;
    }
    int maxa=*max_element(all(a)),maxb=*max_element(all(b));
    if (maxb>=maxa) {
        cout << -1 << "\n";
        return;
    }
    ll diff = suma-sumb;
    vector<int> factors;
    for(ll i=1;i*i<=diff;i++) {
        if (diff%i==0) {
            if (i>maxb && i<=maxa)
                factors.push_back(i);
            if (diff/i>maxb && diff/i <= maxa)
                factors.push_back(diff/i);
        }
    }
    sort(all(b));
    vector<int> modss(n);
    for(int j=0;j<factors.size();j++) {
        int fac =factors[j];
        fill(all(modss),0);
        for(int i=0;i<n;i++)
            modss[i]=a[i]%fac;
        sort(all(modss));
        bool allbmodsame = true;
        for(int i=0;i<n;i++) {
            if (modss[i]!=b[i]) {
                allbmodsame=false;
                break;
            }
        }
        if (allbmodsame) {
            cout << fac << "\n";
            return;
        }
    }
    cout << -1 << "\n";


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
