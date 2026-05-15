#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;

const ll MOD = 1e9+7;

int M = 2e5 + 1;
vector<int> spf(M);

void fillspf() {
    spf[0]=spf[1]=0;
    for(int i=2;i<M;i++)
        spf[i]=i;
    for(int i=2;i*i<M;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<M;j+=i) {
                if (spf[j]==j) {
                    spf[j]=i;
                }
            }
        }
    }
}

ll modpow(ll x, ll n) {
    if (n==0)
        return 1;
    ll res = 1;
    while (n>0) {
        if (n&1)
            res = (res*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return res;
}

void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) 
        cin >> arr[i];
    if (n==1) {
        cout << 1 << "\n";
        return;
    }
    vector<int> cycszs;
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++) {
        if (vis[i]!=0)
            continue;
        int trav=i,cnt = 0;
        while (vis[trav]==0) {
            vis[trav]=1;
            cnt++;
            trav = arr[trav];
        }
        cycszs.push_back(cnt);
    }
    if (cycszs.size() == 1) {
        cout << cycszs[0] << "\n";
        return;
    }
    map<int,int>maxprimfreq;
    for(int i=0;i<int(cycszs.size());i++) {
        int tmp = cycszs[i];
        while (tmp > 1) {
            int pf = spf[tmp], cnt = 0;
            while (tmp%pf == 0) {
                cnt++;
                tmp/=pf;
            }
            maxprimfreq[pf]=max(maxprimfreq[pf],cnt);
        }
    }
    ll lcm = 1;
    for(auto &[prime,freq]:maxprimfreq) {
        lcm = (lcm*modpow(prime,freq))%MOD;
    }
    cout << lcm << "\n"; 

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    fillspf();
    while(t--) {
    	solve();
    }
    
    return 0;
}
