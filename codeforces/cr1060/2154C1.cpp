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



void solve() {
	int n;
    cin >> n;
    vector<int> arr(n),arrb(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    for(int i=0;i<n;i++)
        cin >> arrb[i];
    
    vector<int> divcnt(N,0);
    for(int i=0;i<n;i++) {
        int tmp = arr[i];
        while (spf[tmp]>1) {
            int pr = spf[tmp];
            divcnt[pr]++;
            while(spf[tmp]==pr) tmp/=pr;
        }
    }
    for(int i=2;i<N;i++) {
        if (divcnt[i]>1) {
            cout << 0 << "\n";
            return;
        }
    }
    for(int i=0;i<n;i++) {
        int tmp = arr[i];
        while (spf[tmp]>1) {
            int pr = spf[tmp];
            divcnt[pr]--;
            while(spf[tmp]==pr) tmp/=pr;
        }

        tmp = arr[i]+1;
        while (spf[tmp]>1) {
            int pr = spf[tmp];
            if (divcnt[pr]>0) {
                cout << 1 << "\n";
                return;
            }
            while(spf[tmp]==pr) tmp/=pr;
        }

        tmp=arr[i];
        while (spf[tmp]>1) {
            int pr = spf[tmp];
            divcnt[pr]++;
            while(spf[tmp]==pr) tmp/=pr;
        }
    }
    cout << 2 << "\n";
}


int main() {
    fast;
    int t = 1;
    cin >> t;
    fillspf();
    while(t--){
    	solve();
    }
    return 0;
}
