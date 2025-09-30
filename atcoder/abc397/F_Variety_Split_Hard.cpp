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


struct Node {
    int l;
    int r;
    int maxval;
    int delta;
    Node* left;
    Node* right;
};


Node* build(int l, int r) {
    if (l==r) {
        return new Node{l,r,0,0,nullptr,nullptr};
    }
    Node* node = new Node{l,r,0,0,nullptr,nullptr};
    int mid = l + (r-l)/2;
    node->left = build(l,mid);
    node->right = build(mid+1,r);
    return node;
}

void update(Node* node,int l, int r, int inc) {
    if (node->l==l && node->r==r) {
        node->delta+=inc;
        node->maxval+=inc;
        return;
    }
    int mid = node->l+(node->r-node->l)/2;
    if (r<=mid) {
        update(node->left,l,r,inc);
    } else if (l<=mid) {
        update(node->left,l,mid,inc);
    }
    if (l>mid) {
        update(node->right,l,r,inc);
    } else if(r>mid) {
        update(node->right,mid+1,r,inc);
    }
    node->maxval = max(node->left->maxval,node->right->maxval)+node->delta;
}

void solve(vector<int>&arr) {
    int n = arr.size();
    // cin >> n;
    // vector<int> arr(n);
    map<int,int> freq,freq2;
    for(int i=0;i<n;i++) {
        freq[arr[i]]++;
    }
    Node* seghead = build(0,n-3);
    vector<int> ind(n+1,-1);
    ind[arr[0]]=0;
    ind[arr[1]]=1;
    for(int ii:{0,1}) {
        freq[arr[ii]]--;
        if (freq[arr[ii]]==0) {
            freq.erase(arr[ii]);
        }
    }
    freq2[arr[0]]++;
    freq2[arr[1]]++;
    update(seghead,0,0,2);
    int ans = seghead->maxval+freq.size();
    for(int i=2;i<n-1;i++) {
        freq[arr[i]]--;
        if (freq[arr[i]]==0) {
            freq.erase(arr[i]);
        }
        int valind = ind[arr[i]];
        if (valind == -1) {
            update(seghead,0,i-2,1);
        } else if(valind<=i-2) {
            update(seghead,valind,i-2,1);
        }
        update(seghead, i-1,i-1,freq2.size() + 1);
        ans = max(ans, (int) (seghead->maxval + freq.size()));
        freq2[arr[i]]++;
        ind[arr[i]]=i;
    }
    //cout << "My     ans: " << ans << "\n";
    cout << ans <<"\n";
}

void solve2(vector<int>&arr) {
    int n = arr.size();
    int ans = INT_MIN;
    for(int i=1;i<n-1;i++) {
        for(int j=0;j<i;j++) {
            set<int> s1,s2,s3;
            for(int z=0;z<=j;z++) {
                s1.insert(arr[z]);
            }
            for(int z=j+1;z<=i;z++) {
                s2.insert(arr[z]);
            }
            for(int z=i+1;z<n;z++) {
                s3.insert(arr[z]);
            }
            ans = max(ans, (int) (s1.size() + s2.size()+ s3.size()));
        }
    }
    cout << "Actual ans: " << ans << "\n";
}


// 4 2 1 4 3 1 5 1 6 9
signed main() {
    fast;
    int t = 1;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
    int n = 6;
    cin >> n;
    while(t--){
        vector<int>arr(n);
        for(int i=0;i<n;i++) {
 //           arr[i]= dist6(rng);
 //           cout << arr[i] << " ";
            cin >> arr[i];    
        }
//        cout << "\n";
        //arr = vector<int>{4,2,1,4,3,1,5,1,6,9};
//        arr = vector<int>{4, 1, 4, 1, 1, 4};
    	solve(arr);
        //solve2(arr);
    }
    return 0;
}
