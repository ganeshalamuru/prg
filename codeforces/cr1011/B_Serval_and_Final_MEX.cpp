#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}




void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<pii> ops;
    while(arr.size()>4) {
        pii op = {-1,arr.size()};
        int num1 = arr.back();
        arr.pop_back();
        op.F = arr.size();
        int num2 = arr.back();
        arr.pop_back();
        ops.push_back(op);
        if (num1>num2)
            swap(num1,num2);
        int mexx=0;
        if (num1==0) {
            mexx++;
            if (num2==1)
                mexx++;
        }
        arr.push_back(mexx);
    }
    if (arr[0]==arr[1] && arr[1]==arr[2] && arr[2]==arr[3] && arr[0]==0) {
        ops.push_back({1,2});
        ops.push_back({2,3});
        ops.push_back({1,2});
    } else {
        while(true) {
            bool combind = false;
            vector<int> tmp;
            for(int i=0;i<(int)arr.size()-1;i++) {
                if (arr[i]==arr[i+1] && arr[i]==0) {
                    combind=true;
                    tmp.push_back(1);
                    ops.push_back({i+1,i+2});
                    i=i+2;
                    while(i<arr.size())
                        tmp.push_back(arr[i]),i++;
                } else {
                    tmp.push_back(arr[i]);
                }
            }
            if (combind==false)
                break;
            arr=tmp;
        }
        while(!all_of(arr.begin(), arr.end(), [](int ele){return ele>0;})) {
            vector<int> tmp;
            int i=0,sz = arr.size();
            for(;i<sz;i++) {
                if (arr[i]==0) {
                    if (i!=sz-1) {
                        ops.push_back({i+1,i+2});
                        int mexx=0,num1=arr[i],num2=arr[i+1];
                        if (num1>num2)
                            swap(num1,num2);
                        if (num1==0) {
                            mexx++;
                            if (num2==1)
                                mexx++;
                        }
                        tmp.push_back(mexx);
                        i=i+2;
                        while(i<arr.size())
                            tmp.push_back(arr[i]),i++;
                    } else {
                        int mexx=0,num1=arr[i],num2=arr[i-1];
                        if (num1>num2)
                            swap(num1,num2);
                        if (num1==0) {
                            mexx++;
                            if (num2==1)
                                mexx++;
                        }
                        tmp.pop_back();
                        tmp.push_back(mexx);
                        ops.push_back({i,i+1});
                    }

                } else {
                    tmp.push_back(arr[i]);
                }
            }
            arr=tmp;
        }
        if (arr.size()!=1) {
            ops.push_back({1,arr.size()});
        }
    }
    cout << ops.size() << "\n";
    for(int i=0;i<ops.size();i++) {
        cout << ops[i].F << " " << ops[i].S << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
