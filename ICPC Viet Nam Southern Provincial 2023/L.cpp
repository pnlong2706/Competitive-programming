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

const long long MOD=123456789;

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

// Calculate the number of cells in the rectangle that have distance with (x,y) less or equal than d
// Divide the rectangle into 4 division ( bottom - left, top - left, top - right, bottom - right ) to make it easier to evaluate
ll conquer(ll m, ll n, ll x, ll y, ll d) {
    ll res=0;
    //bottom - left
    int ml=(x-1)+(y-1)+1;
    if(ml>=d) res+=(ml-d)*(ml+1-d)/2;
    res-= d<y? (y-d)*(y-d+1)/2 : 0;
    res-= d<x? (x-d)*(x-d+1)/2 : 0;

    //top - left
    ml=(x-1)+(n-y)+1;
    if(ml>=d) res+=(ml-d)*(ml+1-d)/2;
    res-= d<x? (x-d)*(x-d+1)/2 : 0;
    res-= d<(n-y+1)? (n-y+1-d)*(n-y+1-d+1)/2 : 0;

    //top-right
    ml=(m-x)+(n-y)+1;
    if(ml>=d) res+=(ml-d)*(ml+1-d)/2;
    res-= d<(m-x+1)? (m-x+1-d)*(m-x+1-d+1)/2 : 0;
    res-= d<(n-y+1)? (n-y+1-d)*(n-y+1-d+1)/2 : 0;

    //bottom - right
    ml=(m-x)+(y-1)+1;
    if(ml>=d) res+=(ml-d)*(ml+1-d)/2;
    res-= d<(m-x+1)? (m-x+1-d)*(m-x+1-d+1)/2 : 0;
    res-= d<y? (y-d)*(y-d+1)/2 : 0;

    res+=max((ll)0,y-d) + max((ll)0,x-d) + max((ll)0,n-y+1-d) + max((ll)0,m-x+1-d);

    return res;

}


void solve() {
    ll n,m,x,y,k;
    cin >> m >> n >> x >> y >> k;
    ll lo=1, hi=m+n-1;
    ll mid=(lo+hi+1)/2;

    while(lo<hi) {
        ll nc=conquer(m,n,x,y,mid);
        if(nc<k) hi=mid-1;
        else lo=mid;
        mid=(lo+hi+1)/2;
    }

    cout << lo << el;

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
