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

int M = 1e6+1;

vector<int> spf(M);

void fillspf() {
    spf[0]=spf[1]=0;
    for(int i=2;i<M;i++)
        spf[i]=i;
    for(int i=2;i*i<M;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<M;j+=i) {
                if (spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void solve() {
	int x;
    cin >> x;
    int ans = 1;
    while (x>1) {
        int spfac = spf[x],freq = 0;
        while (x%spfac == 0) {
            freq++;
            x/=spfac;
        }
        ans = ans * (freq+1);
    }
    cout << ans << "\n";


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    fillspf();
    while(t--) {
    	solve();
    }
    
    return 0;
}
