#include<bits/stdc++.h>

using namespace std;
#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i) // 1 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i) // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i) // reverse 1 based
#define int long long

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(_typeof_((c)).begin() i = (c).begin(); i != (c).end(); i++)

// find if a given value is present in a container. Container version. Runs in log(n) for set and map
#define present(c,x) ((c).find(x) != (c).end())

//find version works for all containers. This is present in std namespace.
#define cpresent(c,x) (find(all(c),x) != (c).end())

// Avoiding wrap around of size()-1 where size is a unsigned int.
#define sz(a) int((a).size())
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

using namespace std;


signed main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n,0);
        for0(i,n){
            cin>>v[i];
        }
        int ans=0;
        vector<int>pref;
        pref.push_back(v[0]);
        for(int i=1;i<n;i++){
            pref.push_back(v[i]+pref[i-1]);
        }
        for(int i=1;i<n;i++){
            if(n%i==0){
                int k=i;
                int i=k-1;
                int j=-1;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                //cout<<k<<endl;
                while(i<n){
                    //cout<<i<<" "<<j<<endl;
                    if(j<0){
                    mini = min(abs(pref[i]),mini);
                    maxi = max(abs(pref[i]),maxi);
                    }
                    else{
                    mini = min(abs(pref[i]-pref[j]),mini);
                    maxi = max(abs(pref[i]-pref[j]),maxi);
                    }
                    j=i;
                    i+=k;
                }
                //cout<<maxi<<" "<<mini<<endl;
                ans = max(maxi-mini,ans);
            }
        }
        cout<<ans<<endl;
    }
    
    
    

}