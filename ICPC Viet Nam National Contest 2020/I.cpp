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

bool checkTH(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3) {
    vector<pll> p;
    p.pb(mp(x1,y1));
    p.pb(mp(x2,y2));
    p.pb(mp(x3,y3));

    sort(p.begin(),p.end(), [] (pll a, pll b) -> bool { return a.fi < b.fi; } );

    return (p[1].se-p[0].se)*(p[2].fi-p[0].fi)==(p[2].se-p[0].se)*(p[1].fi-p[0].fi);
}


void solve() {
    ll x, y;
    cin >> x >> y;

    vector<ll> lin1(y);
    lin1[0]=1;
    ll crn=x, crk=1;
    for__(1,y) {
        lin1[i]=lin1[i-1]%MOD*crn%MOD*pow_mod(crk,MOD-2,MOD)%MOD;
        crn++;
        crk++;
    }

    vector<ll> lin2(x);
    lin2[0]=1;
    crn=y, crk=1;
    for__(1,x) {
        lin2[i]=lin2[i-1]%MOD*crn%MOD*pow_mod(crk,MOD-2,MOD)%MOD;
        crn++;
        crk++;
    }
  
    vector<ll> f1(y), f2(x);
    f1[0]=1;
    for(int i=1; i<y; i++ ) {
        f1[i]=(f1[i-1]+lin1[i])%MOD;
        f1[i]+= (i>=2? f1[i-2]: 0);
        f1[i]%=MOD;
    }

    f2[0]=1;
    for(int i=1; i<x; i++) {
        f2[i]=(f2[i-1]+lin2[i])%MOD;
        f2[i]+= (i>=2? f2[i-2]: 0);
        f2[i]%=MOD;
    }

    cout << (f1[y-1]+f2[x-1])%MOD << el;

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
