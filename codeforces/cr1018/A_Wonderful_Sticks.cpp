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
    string s;
    cin >> s;
    vector<int> arr(n);
    int num = n;
    for(int i=n-2;i>=0;i--) {
        if (s[i]=='>')
            arr[i+1]=num,num--;
    }
    int num2=1;
    for(int i=n-2;i>=0;i--) {
        if (s[i]=='<')
            arr[i+1]=num2,num2++;
    }
    arr[0]=num2;
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
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
