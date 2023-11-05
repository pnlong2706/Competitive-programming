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


const long long MOD = 1000000007;
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

void solve() {
    int n;
    string s;
    cin >> s;
    n=s.length();
    vector<int> prsR(n+1,0), prsP(n+1,0), prsS(n+1,0);

    for_(n) {
        prsR[i+1]=prsR[i]+(s[i]=='R');
        prsP[i+1]=prsP[i]+(s[i]=='P');
        prsS[i+1]=prsS[i]+(s[i]=='S');
    }

    int ans=0, mk=2;
    for(int k=2; k<=n; k++) {
        int tt=0;
        for(int i=0; i<n; i+=k) {
            int np=prsP[(i+k<n? i+k: n)]-prsP[i];
            int nr=prsR[(i+k<n? i+k: n)]-prsR[i];
            int ns=prsS[(i+k<n? i+k: n)]-prsS[i];
            int mx=max({np,nr,ns});
            tt+=mx;
        }
        if(ans<=tt) {
            ans=tt;
            mk=k;
        }
    }

    cout << mk << el;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while (t--){
        solve();
    }


    return 0;
}
