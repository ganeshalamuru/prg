#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    vector<int> q(n-1);
    for(int i=0;i<n-1;i++)
        q[i]=i+1;
    int lsb = 0,num=0;
    while((1<<lsb)<=n) {
        vector<vector<int>> arr(2);
        for(int andval;int &ind:q) {
            cout << "? " << ind << " " << (1<<lsb) << "\n" << flush;
            cin >> andval;
            arr[andval].push_back(ind);
        }
        int expectedevncnt = 0;
        for(int j=1;j<=n;j++) {
            if (j%(1<<(lsb+1))==num)
                expectedevncnt++;
        }
        if (int(arr[0].size())<expectedevncnt) {
            q.swap(arr[0]);
        } else {
            q.swap(arr[1]);
            num|=(1<<lsb);
        }
        lsb++;
    }
    cout << "! " << num << "\n" << flush;
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
