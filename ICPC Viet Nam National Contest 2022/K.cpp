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



void solve() {

    set<double> oth;

    vector<pii> py;
    for(int i=2; i<=3000; i++) {
        for(int j=2; j<=3000; j++) {
            int h=i*i+j*j;
            if(h==(int)sqrtl(h)*(int)sqrtl(h)) {
                if( oth.find( (double)j/i)==oth.end() ) {
                    py.pb(mp(i,j));
                    oth.insert((double)j/i);
                }
            }
        }
    }

    sort(py.begin(), py.end(),  [] (pii &a, pii &b)-> bool { return (double)a.se/a.fi > (double)b.se/b.fi; } );

    //cout << py.size() << el;

    //for(int i=1; i<py.size(); i++) if((double)py[i].se/py[i].fi==(double)py[i-1].se==py[i-1].fi) cout << "DUPP";

    int n;
    cin >> n;
    if(n<3) cout << "NO\n";
    else {
        cout << "YES\n";
        int x=-1e6, cr=0;
        int y=-1e6;
        cout << x << " " << y << endl;
        n--; n--;
        while(n--) {
            x+=py[cr].fi;
            y+=py[cr].se;
            cout << x << " " << y << endl;
            cr++;
        }
        cout << x << " " << (int)(-1e6) << el;
    }
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
