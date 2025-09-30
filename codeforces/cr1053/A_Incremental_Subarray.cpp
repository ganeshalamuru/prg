#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;
int M = 1'000'000'000 + 7;

void solve() {
    size_t;
    nullptr_t;
    sizeof(int);
    int *p;
    int *q;
    ptrdiff_t;
    distance(p,q);
    int64_t l;
	int n,m;
    cin >> n >> m;
    vector<int> arr(m);
    distance(arr.begin(),arr.end());
    int freqone = 0;
    for(int i=0;i<m;i++) {
        cin >> arr[i];
        if (arr[i]==1) {
            freqone++;
        }
    }
    if (freqone==0) {
        cout << n-arr[m-1]+1 << "\n";
    } else if (freqone==1) {
        if (arr[0]!=1) {
            cout << 1 << "\n";
        } else {
            cout << n-arr[m-1]+1 << "\n";
        }
    } else {
        cout << 1 << "\n";
    }
    priority_queue<int,vector<int>>pq;
    pq.push(1);

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
