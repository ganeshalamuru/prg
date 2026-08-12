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


int N = 1e6+1;

vector<int> spf(N);

void fillspf() {
    for(int i=0;i<N;i++)
        spf[i]=i;
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
    multiset<int> ss;
    while (n>1) {
        int pf = spf[n],cnt = 0;
        while (n%pf==0) {
            cnt++;
            n/=pf;
        }
        ss.insert(cnt);
    }
    int ans = accumulate(all(ss),0);
    cout << ans-1+int(ss.size()) << "\n";


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
