#include <bits/stdc++.h>
using namespace std;

#define ll          long long
#define ull         unsigned long long
#define for_(n)     for(int i=0; i<n; i++)
#define for__(a,b)  for(int i=a; i<b; i++)
#define FOR(i,a,b)  for(int i=a; i<=b; i++)
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

void dfs(vector<vector<int>> &edg, vector<vector<int>> &adj, vector<int> &par, vector<int> &h, vector<bool> &vis, vector<int> &cpn, int node ) {
    vis[node]=true;
    cpn.pb(node);
    for(auto it: edg[node]) {
        if(!vis[it]) {
            par[it]=node;
            adj[node][it]++;
            adj[it][node]++;
            h[it]=h[node]+1;
            dfs(edg,adj,par,h,vis,cpn,it);
        }
    }
}

int pr(vector<int> &par, vector<int> &h, int a, int b ) {
    if(h[a]>h[b]) swap(a,b);
    while(h[a]<h[b]) b=par[b];
    while(a!=b) {
        a=par[a];
        b=par[b];
    }
    return a;
}

void printAns(vector<pii> &add, vector<vector<int>> &acl, vector<vector<int>> &cl, int k) {
    cout << "YES\n";
    int ta=k-(int)cl.size();
    cout << max(ta,0) << el;
    for_(ta) cout << add[i].fi << " " << add[i].se << el;
    for_(ta) cout << acl[i].size() << " " << acl[i] << el;
    for_(min((int)cl.size(),k)) cout << cl[i].size() << " " << cl[i] << el;
    return;
}

void printAnstt(vector<pii> &add, vector<vector<int>> &acl, vector<vector<int>> &cl) {
    cout << "YES\n";
    cout << add.size() << el;
    for_((int)add.size()) cout << add[i].fi << " " << add[i].se << el;
    for_((int)acl.size()) cout << acl[i].size() << " " << acl[i] << el;
    for_( (int)cl.size() ) cout << cl[i].size() << " " << cl[i] << el;
    return;
}


void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edg(n+1), acl, cl, cpn, adj(n+1, vector<int> (n+1,0) );
    vector<int> par(n+1), h(n+1,0);
    vector<bool> vis(n+1,false);
    vector<pii> add;
    for_(m) {
        int a, b;
        cin >>a >> b;
        edg[a].pb(b);
        edg[b].pb(a);
        adj[a][b]=1;
        adj[b][a]=1;
    }

    if( k > n*(n-1)/2-(n-1) ) { cout  << "NO\n"; return; }

    for__(1,n+1) par[i]=i;

    for__(1,n+1) {
        if(!vis[i]){
            cpn.pb({});
            dfs(edg,adj,par,h,vis,cpn[cpn.size()-1],i);
        }
    }

    sort(cpn.begin(),cpn.end(), [&] (vector<int> &a, vector<int> &b) -> bool { return a.size()>b.size(); } );

    //cout << "---\n";
    //for(auto it: cpn) cout << it << el;
    //cout << "---\n";

    int cpn_size=cpn.size();
    for(int i=0; i<cpn_size; i++) {
        if(cpn[i].size()<=1) break;

        int cz=cpn[i].size();
        for(int j=0; j<cz; j++) {
            for(int k=j+1; k<cz; k++) {
                int a=cpn[i][j], b=cpn[i][k];
                if(adj[a][b]==2) continue;
                else if(adj[a][b]==0) {
                    add.pb(mp(a,b));
                    int ck=pr(par,h,a,b);
                    vector<int> tp;
                    while(a!=ck) { tp.pb(a); a=par[a]; }
                    reverse(tp.begin(),tp.end());
                    while(b!=ck) { tp.pb(b); b=par[b]; }
                    tp.pb(ck);
                    acl.pb(tp);
                }
                else {
                    int ck=pr(par,h,a,b);
                    vector<int> tp;
                    while(a!=ck) { tp.pb(a); a=par[a]; }
                    reverse(tp.begin(),tp.end());
                    while(b!=ck) { tp.pb(b); b=par[b]; }
                    tp.pb(ck);
                    cl.pb(tp);
                }
            }
        }
    }

    //cout << "TZ : " << (int)cl.size()+(int)acl.size() << el;

    if((int)cl.size()+(int)acl.size()>=k) printAns(add,acl,cl,k);
    else {
        int cr=cl.size()+acl.size();
        for(int j=1; j<cpn_size; j++) {
            for(int i=0; i<j; i++) {

                //cout << "** " << cpn[i][0] << " " << cpn[j][0] << el;
                if(i==0) {
                    add.pb(mp(cpn[i][0],cpn[j][0]));
                    adj[ cpn[i][0] ][ cpn[j][0] ]=2;
                    adj[ cpn[j][0] ][ cpn[i][0] ]=2;
                    par[ cpn[j][0] ]=cpn[i][0];
                }

                FOR(p,0,(int)cpn[i].size()-1) {
                    FOR(q,0,(int)cpn[j].size()-1) {
                        int a=cpn[i][p], b=cpn[j][q];
                        if(adj[a][b]==2) continue;
                        //cout << "**** " << a << " " << b <<el;
                        add.pb(mp(a,b));
                        int ck=pr(par,h,a,b);
                        vector<int> tp;
                        while(a!=ck) { tp.pb(a); a=par[a]; }
                        reverse(tp.begin(),tp.end());
                        while(b!=ck) { tp.pb(b); b=par[b]; }
                        tp.pb(ck);
                        acl.pb(tp);
                        cr++;
                        if(cr==k) printAnstt(add,acl,cl);
                    }
                }
            }
        }
    }
    //cout << par << el;
    //printAnstt(add,acl,cl);
}

int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //int t;
    //cin >> t;
    //while(t--)
        solve();

    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
