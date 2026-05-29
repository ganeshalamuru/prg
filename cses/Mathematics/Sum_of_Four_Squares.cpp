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
 
const int N = 1e7+1;
map<int,int> sqrmp;

void solve() {
	int n;
    cin >> n;
    if (sqrmp.find(n)!=sqrmp.end()) {
        cout << sqrmp[n] << " 0 0 0\n";
        return;
    }
    for(int i=0;i*i<=n;i++) {
        int req = n-i*i;
        if (sqrmp.find(req)!=sqrmp.end()) {
            cout << i << " " << sqrmp[req] << " 0 0\n";
            return;
        }
        for(int j=0;j*j<=req;j++) {
            int secreq = req-j*j;
            if (sqrmp.find(secreq)!=sqrmp.end()) {
                cout << i << " " << j << " " << sqrmp[secreq]<< " 0\n";
                return;
            }
        }
    }
    int pow2 = 0,tmp=n;
    while (tmp%2==0) {
        pow2++;
        tmp/=2;
    }
    int newn=n-(1<<pow2);
    for(int i=0;i*i<=newn;i++) {
        int req = newn-i*i;
        if (sqrmp.find(req)!=sqrmp.end()) {
            cout << i << " " << sqrmp[req] << " "<< (1<<(pow2/2)) << "0\n";
            return;
        }
        for(int j=0;j*j<=req;j++) {
            int secreq = req-j*j;
            if (sqrmp.find(secreq)!=sqrmp.end()) {
                cout << i << " " << j << " " << sqrmp[secreq]<< " " << (1<<(pow2/2)) << "\n";
                return;
            }
        }
    }
    
 
}
 

void solve2(vector<bool>& possible, vector<array<int,2>>& smoftwosqrs) {
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
        if (possible[i] && possible[n-i]) {
            cout << smoftwosqrs[i][0] << " " << smoftwosqrs[i][1] << " ";
            cout << smoftwosqrs[n-i][0] << " " << smoftwosqrs[n-i][1] << "\n";
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    cin >> t;

    vector<bool> possible(N);
    vector<array<int,2>> smoftwosqrs(N);
    for(int i=0;i*i<N;i++) {
        for(int j=0;j*j+i*i<N;j++) {
            smoftwosqrs[i*i+j*j]={i,j};
            possible[i*i+j*j]=true;
        }
    }
    
    while(t--) {
    	// solve();
        solve2(possible, smoftwosqrs);
    }
    
    return 0;
}
