#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;
vector<int>prime(5e4+1,1);
void initprime() {
    prime[0]=prime[1]=0;
    for(int i=2;1ll*i*i<prime.size();i++) {
        if (prime[i]==1) {
            for(int j=i*i;j<prime.size();j+=i) {
                prime[j]=0;
            }
        }
    }
}
void primeSubarray(vector<int>& nums, int k) {
    
    vector<pair<int,int>> pe;
    for(int i=0;i<nums.size();i++) {
        if (prime[nums[i]]==1)
            pe.push_back({nums[i],i});
    }
    int n = pe.size();
    if (n<2) {
        cout << "My     ans: " << 0 << "\n";
        return;
    }
    vector<int> nlp(n,n), plp(n,-1);
    stack<int> ng;
    vector<int> ns;
    for(int i=n-1;i>=0;i--) {
        while(!ng.empty() && pe[i].first>=pe[ng.top()].first) {
            ng.pop();
        }
        if (!ng.empty()) {
            nlp[i]=ng.top();
        }
        ng.push(i);
        if (!ns.empty()) {
            auto itr = lower_bound(ns.begin(), ns.end(),pe[i].first-k,[&](int a, int b) {return pe[a].first<b;});
            if (itr!=ns.begin()) {
                itr--;
                nlp[i]=min(nlp[i],*itr);
            }
        }
        while(!ns.empty() && pe[ns.back()].first>=pe[i].first) {
            ns.pop_back();
        }
        ns.push_back(i);
    }
    stack<int> pg;
    vector<int> ps;
    for(int i=0;i<n;i++) {
        while(!pg.empty() && pe[i].first>=pe[pg.top()].first) {
            pg.pop();
        }
        if (!pg.empty()) {
            plp[i]=pg.top();
        }
        pg.push(i);
        if (!ps.empty()) {
            auto itr = lower_bound(ps.begin(), ps.end(),pe[i].first-k,[&](int a, int b) {return pe[a].first<b;});
            if (itr!=ps.begin()) {
                itr--;
                plp[i]=max(plp[i],*itr);
            }
        }
        while(!ps.empty() && pe[ps.back()].first>=pe[i].first) {
            ps.pop_back();
        }
        ps.push_back(i);
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        int leftl = plp[i], rightl = nlp[i];
        if (leftl<i-1 || rightl>i+1) {
            int nleftl=leftl,nrightl=rightl;
            if (leftl!=-1)
                nleftl=pe[leftl].second;
            if (rightl!=n)
                nrightl=pe[rightl].second;
            else
                nrightl=nums.size();
            int numleftoneprime = 0;
            if (i==0)
                numleftoneprime = pe[i].second+1;
            else
                numleftoneprime = pe[i].second-pe[i-1].second;
            int numrighttwoprime=0;
            if (i!=n-1)
                numrighttwoprime = nrightl-pe[i+1].second;
            ans += numleftoneprime*numrighttwoprime;
            int numlefttwoprime = 0;
            if (i!=0)
                numlefttwoprime = (pe[i-1].second-nleftl);
            ans+=numlefttwoprime*(nrightl-pe[i].second);
        }
    }
    cout << "My     ans: " << ans << "\n";
}

void solve(vector<int>&arr, int k) {
    int n = arr.size();
    int ans = 0;
    for(int i=0;i<n;i++) {
        multiset<int> primes;
        for(int j=i;j>=0;j--) {
            if (prime[arr[j]]==1) {
                primes.insert(arr[j]);
            }
            if (primes.size()>1) {
                int maxprime = *primes.rbegin();
                int minprime = *primes.begin();
                if (maxprime-minprime<=k)
                    ans++;
            }
        }
    }
    cout << "Actual ans: " << ans << "\n"; 
}
int main() {
    fast;
    int t = 1000;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,100); // distribution in range [1, 6]
    // std::cout << dist6(rng) << std::endl;
    initprime();
    int n = 5,k=100;
    while(t--){
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            arr[i]=dist6(rng);
            cout << arr[i] << " ";
        }
        cout << "\n";
        primeSubarray(arr,k);
        solve(arr,k);
    }
    return 0;
}