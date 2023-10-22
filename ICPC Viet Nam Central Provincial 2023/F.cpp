
#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define ull         unsigned long long
#define for_(n)     for(ll i=0; i<n; i++)
#define for__(a,b)  for(ll i=a; i<b; i++)
#define _for(i,a,b) for(ll i=a; i<b; i++)
#define mp          make_pair
#define fi          first
#define se          second
#define pb          push_back
#define pii         pair<int, int>
#define pll         pair<long long, long long>
#define el          "\n"
#define debug(x)    cerr << "[debug] " << #x << " : " << x << endl;

const long long MOD=1000000007;

template<class T, class P>
ostream& operator<<(ostream& os, const pair<T,P> &a) { os << "{" << a.first << ";" << a.second << "}"; return os; }
template<class T>
ostream& operator<<(ostream& os, const vector<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const deque<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const set<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const multiset<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }

struct lessSet { bool operator() (const long long &a, const long long &b) { return a>b;} };

ll gcd(ll a, ll b) { return b==0? a : gcd(b,a%b); }
ll lcm(ll a, ll b) { return a/(gcd(a,b))*b; }

ll pow_mod(ll x, ll y, ll mod) { //mod<3.10^9
    ll ans=1;
    while(y>0) {
        if(y%2==1) ans=ans*x%mod;
        y=y>>1;
        x=x*x%mod;
    }
    return ans%mod;
}

int timer=1;

// DFS to initialize all value of array h and par[0];
void process( vector<vector<int>> &edg, vector<vector<int>> &par, vector<int> &h, int node ) {
    for(auto it: edg[node]) {
        if(h[it]<0) {
            h[it]=h[node]+1;
            par[0][it]=node;
            process(edg, par, h, it);
        }
    }
}

// Find k-th ancestor of node
int ancestor( vector<vector<int>> &par, int node, int k) {
    int i=0;
    while(k>0) {
        if(k%2==1) node=par[i][node];
        k=k>>1;
        i++;
    }
    return node;
}

void dfs( vector<vector<int>> &edg, vector<ll>& val, vector<ll> &num, int node, int p) {

    if(edg[node].size()==1 && node!=1) { num[node]=val[node]; return; }
    for(auto it: edg[node]) {
        if(it!=p) {
            dfs(edg,val,num,it,node);
            num[node]+=num[it];
        }
    }

    num[node]+=val[node];
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> edg(n+1), par(21, vector<int> (n+1) );
    vector<ll> val(n+1,0);
    vector<ll> num(n+1,0);
    vector<int> h(n+1,-1);
    unordered_map<ll, ll> c1, c2;

    ll bs=1e6;
    for_(n-1) {
        ll a, b, v1, v2;
        cin >> a >> b >> v1 >> v2;
        edg[a].pb(b);
        edg[b].pb(a);

        c1[ a*bs+b ]=v1;
        c1[ b*bs+a ]=v1;
        c2[ a*bs+b ]=v2;
        c2[ b*bs+a ]=v2;
    }

    h[1]=0; par[0][1]=-1;
    // DFS to initialize all value of array h and par[0];
    process(edg, par, h, 1);
    // Now, par[i][j]=par[i-1][par[i-1][j]] if( h[j]>=2^j )
    int p2=1;
    for__(1,21) {
        p2*=2;
        for(int j=1; j<=n; j++) {
            if(h[j]>=p2) par[i][j]=par[i-1][par[i-1][j]];
            else par[i][j]=-1;
        }
    }

    for(int kk=1; kk<=n-1; kk++) {
        int a=kk, b=kk+1;

        if (h[a]<h[b]) swap(a,b);
        int lo=0, hi=h[a];
        int mid=(lo+hi+1)/2;
        while(lo<hi) {
            int aa=ancestor(par,a,h[a]-mid), ab=ancestor(par,b,h[b]-mid);
            if(aa==ab) lo=mid;
            else hi=mid-1;
            mid=(lo+hi+1)/2;
        }

        int ac=ancestor(par,a,h[a]-lo);
        if(ac==b) {
            val[b]--;
            val[a]++;
        }
        else {
            val[b]++;
            val[a]++;
            val[ac]-=2;
        }
    }

    ll ans=0;
    dfs(edg,val,num,1,1);
    for(int kk=2; kk<=n; kk++) ans+= min(c1[par[0][kk]*bs+kk]*num[kk],c2[par[0][kk]*bs+kk]);

    cout << ans << el;
}


int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //freopen( "OUT.out", "w", stdout );
    int t=1;
    //cin >> t;
    while(t--)
        solve();
    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
