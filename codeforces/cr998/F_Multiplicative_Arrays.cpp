#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 998244353, N = 1e5+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


vector<int> spf, invfact;
vector<vector<int>> nCk; 

int msub(ll a, ll b) {
    a%=mod, b%=mod;
    return(a-b+mod)%mod;
}

int madd(ll a, ll b) {
    a%=mod, b%=mod;
    return(a+b)%mod;
}
int mmul(ll a, ll b) {
    a%=mod, b%=mod;
    return(a*b)%mod;
}

void sieve() {
    spf.resize(N);
    spf[0] = 0, spf[1] = 0;
    for(int i=2;i<N;i++)
        spf[i]=i;
    for(int i=2;i*i<N;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<N;j+=i) {
                spf[j]=i;
            }
        }
    }
}

void fillnCk() {
    nCk = vector<vector<int>>(33, vector<int>(33,0));
    for(int i=0;i<33;i++)
        nCk[i][0] = 1;
    for(int i=0;i<33;i++) {
        for(int j=1;j<=i;j++) {
            nCk[i][j] = madd(nCk[i-1][j-1], nCk[i-1][j]);
        }
    }
}

void fillinvfact() {
    invfact = vector<int>(33);
    int prod = 1;
    invfact[0]=1;
    for(int i=1;i<33;i++) {
        prod = mmul(prod, i);
        invfact[i] = powe(prod, mod-2);
    }
}

int calcnCk(int n, int k) {
    int res = 1, times=k;
    while(times--) {
        res=mmul(res,n);
        n--;
    }
    res=mmul(res, invfact[k]);
    return res;
}

void solve() {
	int n,k;
    cin >> k >> n;
    cout << n%mod << " "; 
    for(int x=2;x<=k;x++) {
        map<int,int> factors;
        int temp = x,totfactors = 0;
        while(temp > 1) {
            factors[spf[temp]]++;
            temp/=spf[temp];
            totfactors++;
        }
        int tans = 0;
        for(int j=1;j<=min(n,totfactors);j++) {
            int fans = 0;
            for(int z=0;z<j;z++) {
                int prod = nCk[j][z];
                for(auto &pp:factors)
                    prod = mmul(prod, nCk[pp.second+j-1-z][pp.second]);
                if (z&1)
                    fans = msub(fans, prod);
                else
                    fans = madd(fans, prod);
            }
            tans = madd(tans, mmul(calcnCk(n+1,j+1) ,fans));
        }
        cout << tans << " ";
    }
    cout << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    sieve();
    fillnCk();
    fillinvfact();
    while(t--){
    	solve();
    }
    return 0;
}
