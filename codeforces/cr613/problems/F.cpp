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



vector<int> spf(1e5 + 1);
set<int> arrset;
vector<int> divisors;
void calculateSPF(int n) {
    spf[1] = 1;

    for (int i = 2 ; i < n + 1; i++)
        spf[i] = i;

    for (int i = 2; i * i < n + 1; i++) 
        if (spf[i] == i) 
            for (int j = i * i; i < n + 1; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}
vector<pii> getFactorization(int x) {
    map<int, int> mp;
    while(x != 1) {
        mp[spf[x]]++;
        x = x / spf[x];
    }
    vector<pii> pfcount;
    for(auto &kv : mp)
        pfcount.push_back(kv);
    return pfcount;
}

void recAllDivisors(int curNum, int curIndex, vector<pii>& pfc) {
    if (curIndex >= pfc.size()) {
        divisors.push_back(curNum);
    } else {
        for (int i = 0; i < pfc[curIndex].second + 1 ; i ++) {
            recAllDivisors((curNum*i)*pfc[curIndex].first, curIndex + 1, pfc);
        }
    }
}

int closesMultiple

int calcMaxLcm(int a, vector<int>& arr) {
    vector<pair<int, int>> pfc = getFactorization(a);
    divisors.clear(); 
    recAllDivisors(1, 0, pfc);
    int maxLcm = INT_MIN;
    int maxval = *arrset.rbegin();
    for (int i = 0; i < divisors.size(); i ++) {
        int divisor = divisors[i];
        int quo = maxval / divisor;
        if (quo * divisor < maxVal)
            quo++;
        for(int i = quo; i>=1; i--) {
            if (arrset.find(quo*divisor) != arrset.end()) {
                maxLcm = max(maxLcm, (quo*divisor) / )
                break;
            }
        }
            arrset.contains(quo*divisors)
    }
    return 0;
}



void solve(){
    int n,maxVal = INT_MIN;
    cin >> n;
    vector<int> arr(n);
    for (int &j:arr) {
        cin >> j; 
        arrset.insert(j);
    }
	calculateSPF(*arrset.rbegin());
    int maxlcm = arr[0];
    for (int i : arr)
        maxlcm = max(maxlcm, calcMaxLcm(i, arr));
    cout << maxlcm << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
