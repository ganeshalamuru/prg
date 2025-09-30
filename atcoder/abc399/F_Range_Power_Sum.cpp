#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 998244353;

int madd(int a, int b){
    return (a+b)%mod;
}
int mmul(int a, int b){
    return (1ll*a*b)%mod;
}

vector<vector<int>> nCk(11,vector<int>(11,0));
void initnCk() {
    nCk[0][0]=1;
    for(int n=1;n<11;n++) {
        nCk[n][0]=1;
        for(int k=1;k<=n;k++) {
            nCk[n][k]=madd(nCk[n-1][k],nCk[n-1][k-1]);
        }
    }
}

int mpow(int x,int n) {
    if (x==0) {
        if (n==0)
            return 1;
        return 0;
    }
    int ans = 1;
    int base = x;
    while(n>0) {
        if (n&1) {
            ans = mmul(ans,base);
        }
        base = mmul(base,base);
        n>>=1;
    }
    return ans;
}

void solve() {
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    initnCk();
    vector<int> parr(n);
    parr[0]=arr[0];
    for(int i=1;i<n;i++) {
        parr[i]=madd(parr[i-1],arr[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = madd(ans,mpow(parr[i],k));
    }
    for(int i=0;i<=k;i++) {
        int pplsum = 0;
        for(int j=1;j<n;j++) {
            pplsum=madd(pplsum, mpow(mmul(mod-1,parr[j-1]), i));
            int tmp = mmul(nCk[k][i],mpow(parr[j], k-i));
            if (i==0) {
                ans = madd(ans, mmul(j,tmp));
            } else {
                ans = madd(ans,mmul(tmp,pplsum));
            }
        }
        
    }
    cout << ans << "\n";
}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
