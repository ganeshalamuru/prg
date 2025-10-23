#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
 
int N=2e5+1;
vector<int> spf(N);
vector<int> primes;
void fillspf() {
    spf[0]=spf[1]=-1;
    for(int i=2;i<N;i++) {
        spf[i]=i;
    }
    for(int i=2;i*i<N;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<N;j+=i) {
                if (spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}
void fillprimes() {
    for(int i=2;i<N;i++) {
        if (spf[i]==i)
            primes.push_back(i);
    }
}

vector<int> divcnt(N,0);
vector<array<int,2>> arr(N);
void solve() {
	int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i][0];
    for(int i=0;i<n;i++)
        cin >> arr[i][1];
    fill(all(divcnt), 0);
    bool gcdone = true;
    for(int i=0;i<n && gcdone;i++) {
        int tmp = arr[i][0];
        while (spf[tmp]>1) {
            int pr = spf[tmp];
            divcnt[pr]++;
            if (divcnt[pr]>1) {
                gcdone=false;
                break;
            }
            while(tmp%pr==0) tmp/=pr;
        }
    }
    if (!gcdone) {
        cout << 0 << "\n";
        return;
    }
    ll mincost = LLONG_MAX;
    int min1 = INT_MAX, min2 =  INT_MAX;
    for(int i=0;i<n;i++) {
        if (arr[i][0]&1) {
            if (arr[i][1]<min1) {
                swap(min1,min2);
                min1=arr[i][1];
            } else if (arr[i][1]<min2) {
                min2=arr[i][1];
            }
        }
    }
    if (divcnt[2]>0) {
        mincost=min(mincost,0ll+min1);
    } else if (min2!=INT_MAX) {
        mincost=min(mincost, 0ll+min1+min2);
    }
    for(int i=0;i<n;i++) {
        int tmp = arr[i][0]+1;
        while (spf[tmp]>1) {
            int pr = spf[tmp];
            if (divcnt[pr]>0) {
                mincost= min(1ll*arr[i][1],mincost);
            }
            while(tmp%pr==0) tmp/=pr;
        }
    }

    sort(arr.begin(),arr.begin()+n,[](const auto &a,const auto &b){return a[1]<b[1];});
    for(int i=0;i<1;i++) {
        for(int j=0;j<int(primes.size());j++) {
            if (divcnt[primes[j]]==0)
                continue;
            int rem = (arr[i][0]%primes[j]);
            if (rem==0)
                continue;
            ll cnt = (primes[j]-rem);
            mincost=min(mincost, cnt*arr[i][1]);
        }                                             
    }

    cout << mincost << "\n";
}
 
 
int main() {
    fast;
    int t = 1;
    cin >> t;
    fillspf();
    fillprimes();
    while(t--){
    	solve();
    }
    return 0;
}