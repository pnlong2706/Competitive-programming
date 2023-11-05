#include <bits/stdc++.h>
using namespace std;

#define ll      long long
#define ull     unsigned long long
#define for_(n) for(ll i=0; i<n; i++)
#define for__(a,n) for(ll i=a; i<n; i++)
#define mp      make_pair
#define fi      first
#define se      second
#define pb      push_back
#define pii     pair<int,int>
#define pll     pair<long long, long long>
#define el      "\n"
#define debug(x) cerr << "[debug] " << #x << " : " << x << endl;


const long long MOD = 998244353;
template<class T, class F>
ostream& operator<<(ostream &os, const pair<T, F> &a) { os << "(" << a.first << ","  << a.second << ")"; return os;}
template<class T>
ostream& operator<<(ostream &os, const vector<T> &a) { for (auto it: a) os << it << " "; return os;}
template<class T>
ostream& operator<<(ostream &os, const set<T> &a) { for (auto it: a) os << it << " "; return os;}

ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

ll pow_mod(ll x,ll y,ll mod)
{
    ll ans=1;
    while (y>0){
        if (y%2==1) ans=ans*x%mod;
        y=y>>1;
        x=x*x%mod;
    }
    return ans%mod;
}

vector<int> a;
vector<vector<int>> rg[17];
vector<vector<int>> f(17);
vector<int> trg;
int n;

void genrg(int ith, int l, int r) {
    if(l>r) {
        rg[ith].pb(trg);
        return;
    }

    for(int i=l; i<=r; i++) {
        trg.pb(i-l+1);
        genrg(ith,i+1,r);
        trg.pop_back();
    }
}

void gen( int nn, int &val, vector<int> &rg, int i ) {
    if(i==rg.size()) {
        int ta=nn-rg.size()-1+val;
        f[nn].pb(ta);
    }
    else {
        for(auto it: f[rg[i]] ) {
            val+=it;
            gen(nn,val,rg,i+1);
            val-=it;
        }
    }
}


void solve() {
    cin >> n;
    a.resize(n+1);
    for__(1,n+1) cin >> a[i];

    for(int i=1; i<=16; i++) genrg(i,1,i);

    f[1]={0};
    f[2]={0};
    f[3]={0,1};

    int val=0;
    for(int i=4; i<=n; i++) for(auto vt: rg[i-1]) gen(i,val,vt,0);
    
    ll ans=0;
    for(auto it: f[n]) {
        ans+=pow_mod(2,it,MOD);
        ans%=MOD;
    }

    cout << ans << el;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    while (t--){
        solve();
    }


    return 0;
}
