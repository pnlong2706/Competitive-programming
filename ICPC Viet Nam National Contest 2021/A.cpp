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

int mn(char a, char b) {
    if(a<b) swap(a,b);
    return min( a-b, b+26-a );
}

void solve() {
    int n;
    cin >> n;
    int nn=n*n;
    vector<int> a(nn);
    vector<vector<int>> cgr(n+2, vector<int> (n+1,0) );
    vector<set<int>> gr(n+2);
    vector<pii> cl(n+2);
    for_(n+2) cl[i]=mp(i,0);
    for_(nn) { cin >> a[i]; cl[a[i]].se++; }

    sort(cl.begin(),cl.end(), [] (pii &a, pii &b) -> bool { return a.se!=b.se? a.se>b.se: a.fi>b.fi; } );

    int val=cl[0].se, cv=cl[0].fi, j=1;
    for(int i=n; i>=1; i--) {
        if(i<j) break;
        if(val>=n-cl[i].se) {
            val-=(n-cl[i].se);
            cgr[cv][i]=n-cl[i].se;
            cgr[cl[i].fi][i]=cl[i].se;
        }
        else {
            cgr[cv][j]= val ;
            cgr[cl[j].fi][j]=n-val;
            val=cl[j].se+val-n;
            cv=cl[j].fi;
            j++;
            i++;
        }
    }

    for(int i=1; i<=n+1; i++) {
        for(int j=1; j<=n; j++ ) {
            if(cgr[i][j]>0) gr[i].insert(j);
        }
    }

    cout << "YES\n";
    vector<int> ans(nn);
    for_(nn) {
        int v=a[i];
        int ng=*gr[v].begin();
        ans[i]=ng;
        cgr[v][ng]--;
        if(cgr[v][ng]==0) gr[v].erase(gr[v].begin());
    }

    cout << ans << el;


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
