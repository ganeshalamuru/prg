#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;



vector<vector<ll>> calcintersection2(ll a, ll b, vector<ll> range, vector<ll> badrange) {
    ll k = (badrange[1]-range[1])/b;
    if (badrange[0]<=range[1]+k*b) {
        if (range[0]+k*a>=badrange[0]) {
            return {{}};
        }
        if (badrange[0]-1+b<=badrange[1]) {
            return {{}};
        }
        if (range[0]+(k+1)*a<=badrange[1]) {
            return {vector<ll>{badrange[1]+1, badrange[0]-1+b}};
        } else {
            return {{range[0]+(k+1)*a,badrange[0]-1+b}};
        }
    } else {
        if (range[0]+(k+1)*a>badrange[1]) {
            return {{range[0]+(k+1)*a, range[1]+(k+1)*b}};
        } else if (range[0]+(k+1)*a>=badrange[0]) {
            return {{badrange[1]+1, range[1]+(k+1)*b}};
        } else if(range[0]+(k+1)*a+a<=range[0]+(k+1)*b) {
            return {{badrange[1]+1, badrange[0]-1+b}};
        } else {
            return {{badrange[1]+1,range[0]+(k+1)*b},{range[0]+(k+2)*a, badrange[0]-1+b}};
        }
    }
}


vector<vector<ll>> calcintersection(ll a, ll b, vector<ll> range, vector<ll> badrange) {
    vector<vector<ll>> ans;
    if (range[1]>badrange[1]) {
        if (range[0]>badrange[1])
            ans.push_back(range);
        else if (range[0]>=badrange[0])
            ans.push_back({badrange[1]+1, range[1]});
        else {
            ans.push_back({badrange[1]+1, range[1]});
            vector<ll> leftt{range[0],badrange[0]-1};
            for(auto &ins:calcintersection2(a,b,leftt,badrange))
                ans.push_back(ins);
        }
        return ans;
    } else if (range[1]>=badrange[0]) {
        if (range[0]<badrange[0]) {
            vector<ll>leftt{range[0],badrange[0]-1};
            for(auto &ins:calcintersection2(a,b,leftt,badrange))
                ans.push_back(ins);
        }
    } else {
        for(auto &ins:calcintersection2(a,b,range,badrange))
            ans.push_back(ins);
    }
    return ans;
}
vector<int> dp;
void solve(ll n, ll m, ll a, ll b, vector<vector<ll>> arr) {
	// ll n,m,a,b;
    // cin >> n >> m >> a >> b;
    // cout << "My    : ";
    vector<vector<ll>> range{{1,1}};
    for(int i=0;i<arr.size();i++) {
        vector<vector<ll>> ins;
        for(int j=0;j<range.size();j++) {
            auto intersectionss = calcintersection(a,b,range[j],arr[i]);
            for(auto &rr:intersectionss) {
                if (!rr.empty())
                    ins.push_back(rr);
            }
        }
        if (ins.empty()) {
            cout << "No\n";
            return;
        }
        sort(ins.begin(), ins.end());
        range=vector<vector<ll>>{ins[0]};
        for(int j=1;j<ins.size();j++) {
            if (range.back()[1]+1>=ins[j][0]) {
                range.back()[1]=max(range.back()[1],ins[j][1]);
            } else {
                range.push_back(ins[j]);
            }
        }
    }
    for(int i=0;i<range.size();i++) {
        if (range[i][0]<=n && n<=range[i][1]) {
            cout << "Yes\n";
            return;
        }
        ll l = (n-range[i][1])/b + (((n-range[i][1])%b)!=0), r = (n-range[i][0])/a;
        if (l<=r) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

}

void solve2(ll n,int m,int a,int b,vector<vector<int>> &arr) {
    cout << "Actual: ";
    dp.resize(n+1,0);
    dp[1]=1;
    for(int i=0;i<arr.size();i++) {
        for(int j=arr[i][0];j<=arr[i][1];j++)
            dp[j]=-1;
    }
    for(int i=a+1;i<=n;i++) {
        if (dp[i]==-1)
            continue;
        for(int j=i-a;j>=i-b && j>=1;j--) {
            if (dp[j]==-1 || dp[j]==0)
                continue;
            dp[i]=1;
            break;
        }
    }
    if (dp[n]==1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}


int main() {
    fast;
    int t = 1;
    // std::random_device dev;
    // std::mt19937 rng(dev());
    // std::uniform_int_distribution<std::mt19937::result_type> dist1(2,99); // distribution in range [1, 6]
    // std::uniform_int_distribution<std::mt19937::result_type> dist2(1,20); // distribution in range [1, 6]
    //std::cout << dist6(rng) << std::endl;
    while(t--) {
        ll n=100,m=4,a=10,b=11;
        cin >> n >> m >> a >> b;
        vector<vector<ll>> arr(m,vector<ll>(2));
        for(int i=0;i<m;i++) {
            // int n1 = dist1(rng);
            // arr[i]={n1,min((int)n-1,n1+(int)dist2(rng))};
            // cout << arr[i][0] << "," << arr[i][1] << "\n";
            cin >> arr[i][0] >> arr[i][1];
        }
        // arr = vector<vector<int>>{{44,49},
        //     {13,30},
        //     {94,97},
        //     {55,73}};
        vector<vector<ll>> merged;
        if (arr.size()>0)
            merged.push_back(arr[0]);
        for(int i=1,l,r;i<m;i++) {
            cin >> l >> r;
            if (merged.back()[1]+1>=arr[i][0])
                merged.back()[1]=max(merged.back()[1], arr[i][1]);
            else
                merged.push_back(arr[i]);
        }
        // solve2(n,m,a,b,merged);
    	solve(n,m,a,b,merged);
    }
    return 0;
}
