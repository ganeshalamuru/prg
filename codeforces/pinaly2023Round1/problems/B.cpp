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
    int val;
    Node* next;
    Node(int val, Node* next) {
        this->val = val;
        this->next= next;
    }
};


void solve(){
	int n;
    cin >> n;
    Node* head = nullptr;
    Node* last = nullptr;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        if (i==0) {
            head = new Node(x,nullptr);
            last = head;
        } else {
            Node* newe = new Node(x,nullptr);
            last->next = newe;
            last = newe;
        }
    }
    int moves=0;
    while(head->next != nullptr) {
        if (head->next->next==nullptr) {
            moves++;
            break;
        }
        Node* trav = head;
        Node* prev = nullptr;
        bool mademove = false;
        int prevval = last->val;
        //delete one node
        while(trav!=nullptr) {
            int cur = trav->val;
            int nxt;
            if (trav->next == nullptr) {
                nxt = head->val;
            } else{
                nxt = trav->next->val;
            }
            if (prevval!=nxt) {
                if (!mademove) {
                    moves++;
                    mademove = true;
                }
                if (prev==nullptr) {
                    head = trav->next;
                } else {
                    prev->next=trav->next;
                    if (prev->next==nullptr)
                        last = prev;
                }
                break;
            }
            prev=trav;
            prevval=trav->val;
            trav = trav->next;
        }
        if(!mademove) {
            head = head->next;
            moves++;
        }
        trav = head;
        prev = nullptr;
        while(trav!=nullptr) {
            int cur = trav->val;
            int nxt;
            if (trav->next == nullptr) {
                nxt = head->val;
            } else{
                nxt = trav->next->val;
            }
            if (cur==nxt) {
                if (prev == nullptr) {
                    head = trav->next;
                } else {
                    prev->next=trav->next;
                    if (prev->next==nullptr)
                        last = prev;
                }
            }
            prev=trav;
            trav = trav->next;
        }
    }
    cout << moves+1 << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
