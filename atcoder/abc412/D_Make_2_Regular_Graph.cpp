#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,m;
    cin >> n >> m;
    vector<vector<int>>adjm(n,vector<int>(n,0));
    int ans = 0;
    for(int i=0,a,b;i<m;i++) {
        cin >> a >> b;
        a--,b--;
        if (a==b) {
            ans++;
        } else if (adjm[a][b]==0) {
            adjm[a][b]++;
            adjm[b][a]++;
        } else {
            ans++;
        }
    }
    vector<int> arr(n,0);
    for(int i=0;i<n;i++) {
        arr[i]=i;
    }
    vector<vector<int>> reqedges()
    do {
        for(int csz = 3;csz<=n-3;csz++) {
            
        }
    } while(next_permutation(arr.begin(), arr.end()));
    

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
