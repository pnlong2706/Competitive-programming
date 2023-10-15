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

const int BS=10000;

class point {
public:
    ll x, y, z;
    point(int a, int b, int c): x(a), y(b), z(c) {}
};

void solve() {
    ll n, k, ans=0;
    cin >> n >> k;
    vector<point> sp;

    auto keycmp=[] (const point &a, const point &b  ) {
        if(a.x!=b.x) return a.x<b.x;
        else if(a.y!=b.y) return a.y<b.y;
        else return a.z<b.z;
    };

    set<point, decltype(keycmp) > mp(keycmp);

    for_(k) {
        ll a, b, c;
        cin >> a >> b >>c;
        point pt(a,b,c);
        if(mp.find(pt)==mp.end()) {
            sp.pb(pt);
            mp.insert(pt);
        }
    }

    sort(sp.begin(),sp.end(), [] ( const point &a, const point &b) -> bool { return a.x<b.x; } );
    k=sp.size();

    ll n1=0, n2=0, n3=0;

    for(int i=0; i<k; i++) n1+=n;
    for(int i=0; i<k; i++) {
        for(int j=i+1; j<k; j++) {
            if( sp[i].x==sp[j].x && sp[i].x>0 && ( (sp[i].y==0 && sp[j].z==0) ||  (sp[j].y==0 && sp[i].z==0) )  ) {
                n2++;
                point check_point(0, sp[j].y + sp[i].y , sp[j].z + sp[i].z  );
                if( mp.find(check_point)!=mp.end() ) n3++;
            }
            if( sp[i].y==sp[j].y && sp[i].y>0 && ( (sp[i].x==0 && sp[j].z==0) ||  (sp[j].x==0 && sp[i].z==0) ) ) {
                n2++;
                point check_point( sp[j].x + sp[i].x , 0 , sp[j].z + sp[i].z );
                if( mp.find(check_point)!=mp.end() ) n3++;
            }
            if( sp[i].z==sp[j].z && sp[i].z>0 && ( (sp[i].y==0 && sp[j].x==0) ||  (sp[j].y==0 && sp[i].x==0) ) ) {
                n2++;
                point check_point( sp[j].x + sp[i].x , sp[j].y + sp[i].y, 0  );
                if( mp.find(check_point)!=mp.end() ) n3++;
            }
        }
    }
    cout << n1-n2+n3/3 << el; // inclusive - exlusive rule

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
