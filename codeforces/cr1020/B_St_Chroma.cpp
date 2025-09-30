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
	int n,x;
    cin >> n >> x;
    vector<int>arr(n);
    int num=0;
    for(int i=0;i<x;i++)
        arr[i]=num,num++;
    for(int j=n-1;j>=x;j--)
        arr[j]=num,num++;
    for(int i=0;i<n;i++) {
        cout << arr[i] << " ";
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
