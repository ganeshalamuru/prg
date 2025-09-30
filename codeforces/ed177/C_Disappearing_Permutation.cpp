#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int> arr(n+1);
    vector<int> ind(n+1),cycle(n+1,-1);
    for(int i=1;i<=n;i++)
        cin >> arr[i],ind[arr[i]]=i;
    vector<int> queries(n);
    for(int i=0;i<n;i++) {
        cin >> queries[i];
    }
    vector<int>cyclecnt(n+1,0);
    int cycnum=1;
    for(int i=1;i<=n;i++) {
        if (cycle[i]!=-1)
            continue;
        int j=arr[i],cnt = 1;
        cycle[i]=cycnum;
        while(cycle[j]==-1) {
            cycle[j]=cycnum;
            cnt++;
            j=arr[j];
        }
        cyclecnt[cycnum]=cnt;
        cycnum++;
    }
    int numops=0;
    set<int> ss;
    for(int i=0;i<n;i++) {
        int cnum = cycle[queries[i]];
        if (ss.find(cnum) == ss.end()) {
            numops+=cyclecnt[cnum];
            ss.insert(cnum);
        }
        cout << numops << " ";
    }
    cout << "\n";

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
