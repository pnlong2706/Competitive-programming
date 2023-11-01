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
ll nuoc(const vector<ll>& h)
{
    int n = h.size();
    if (n<=1) return 0;
    vector<ll> l(n);
    vector<ll> r(n);
    l[0] = h[0];
    for (int i = 1;i<n; ++i)
    {
        l[i] = max(l[i-1], h[i]);
    }
    r[n-1] = h[n-1];
    for (int i = n-2; i>=0; --i)
    {
        r[i] = max(r[i+1], h[i]);
    }
    ll ans = 0;
    for (int i = 0; i<n; ++i)
    {
        ans += min(l[i], r[i]) - h[i];
    }
    return ans;
}

vector<vector<int>> good;
void gen(vector<int> &num, int ith, int k, int n) {

    if(k==0) {
        good.pb(num);
        return;
    }
    if(ith==n) return;
    for(int i=0; i<=k; i++) {
        int tmp=num[ith];
        num[ith]=i;
        gen(num,ith+1,k-i,n);
        num[ith]=tmp;
    }

}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i<n; ++i) cin >> h[i];
    ll ans = nuoc(h);

    vector<int> tn(n,0);
    gen(tn,0,k,n);

    for(auto vt: good) {
        for(int i=0; i<n; i++) h[i]+=vt[i];
        ans=max(ans,nuoc(h));
        for(int i=0; i<n; i++) h[i]-=vt[i];
    }

    cout << ans << el;

}


int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //freopen( "OUT.out", "w", stdout );
    //cout<<nuoc({3,12});
    solve();

    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";

    return 0;
}
