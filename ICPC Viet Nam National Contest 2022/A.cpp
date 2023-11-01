#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define for_(n)     for(int i=0; i<n; i++)
#define for__(a,b)  for(int i=a; i<b; i++)
#define mp          make_pair
#define fi          first
#define se          second
#define pb          push_back
#define pii         pair<int, int>
#define pll         pair<long long, long long>
#define el          "\n"

const long long MOD=998244353;


template<class T, class P>
ostream& operator<<(ostream& os, const pair<T,P> &a) { os << "{" << a.first << ";" << a.second << "}"; return os; }
template<class T>
ostream& operator<<(ostream& os, const vector<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const deque<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
template<class T>
ostream& operator<<(ostream& os, const set<T> &a) { ; for(auto it: a) os << it << " "; ; return os; }
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

int parent(vector<int> &par, int a) {
    if(par[a]==a) return a;
    par[a]=parent(par,par[a]);
    return par[a];
}

void union_( vector<int> &par, vector<int> &sz, int a, int b) {
    a=parent(par,a);
    b=parent(par,b);
    if(sz[a]<sz[b]) swap(a,b);
    par[b]=a;
    sz[a]+=sz[b];
}

struct que {
    int id, snp, u, v;
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> par(n+1), sz(n+1,1);
    for_(n) par[i+1]=i+1;

    vector<char> ans(q,'z');
    vector<que> Q;

    vector<string> qur(q);
    getline(cin,qur[0]);
    for_(q) getline(cin,qur[i]);
    for_(q) {
        stringstream st(qur[i]);
        char tp;
        st >> tp;
        if(tp=='Q') {
            que qq;
            qq.id=i;
            st >> qq.snp >> qq.u >> qq.v;
            Q.pb(qq);
        }
    }

    sort(Q.begin(), Q.end(), [] (que &a, que &b) -> bool { return a.snp!=b.snp? a.snp < b.snp: a.id < b.id; }  );

    int qs=Q.size();
    int j=0, cr=0;
    while( j<qs && Q[j].snp==cr ) {
        int uu=parent(par,Q[j].u);
        int vv=parent(par,Q[j].v);
        if(uu==vv) ans[Q[j].id]='Y';
        else ans[Q[j].id]='N';
        j++;
    }
    cr++;

    for_(q) {
        stringstream st(qur[i]);
        char tp;
        st >> tp;
        if(tp=='A') {
            int u, v;
            st >> u >> v;
            u=parent(par,u);
            v=parent(par,v);
            if(u==v) continue;
            union_(par,sz,u,v);
        }
        else if(tp=='?') {
            int u, v;
            st >> u >> v;
            u=parent(par,u);
            v=parent(par,v);
            if(u==v) ans[i]='Y';
            else ans[i]='N';
        }
        else if(tp=='C') {
            while( j<qs && Q[j].snp==cr ) {
                int uu=parent(par,Q[j].u);
                int vv=parent(par,Q[j].v);
                if(uu==vv) ans[Q[j].id]='Y';
                else ans[Q[j].id]='N';
                j++;
            }
            cr++;
        }
    }

    for_(q) if(ans[i]!='z') cout << ans[i];


}



int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //cin >> t;
    //while(t--)
        solve();
    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
