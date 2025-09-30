#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


vector<int> spf(1e6+1,0);

void sieve() {
    spf[0]=spf[1]=-1;
    for(int i=2;i<1e6+1;i++) {
        spf[i]=i;
    }
    for(int i=2;i*i<1e6+1;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<1e6+1;j+=i) {
                if (spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void solve() {
	int q;
    cin >> q;
    sieve();
    vector<ll> nums;
    for(int i=2;i<1e6+1;i++) {
        int disprimes = 0;
        int tt = i;
        while (tt>1 &&tt%spf[tt]==0){
            int cnt = 0;
            int pp = spf[tt];
            while(tt%pp==0) {
                cnt++;
                tt/=pp;
            }
            disprimes++;
        }
        if (disprimes==2)
            nums.push_back(1ll*i*i);
    }
    while(q--) {
        ll A;
        cin >> A;
        auto itr = lower_bound(all(nums),A+1);
        itr--;
        cout << *itr << "\n";
    }


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
