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
int n, sa, sb;
int ans = 0;
void dfs(int a, int b)
{
    if (a>sa || b>sb) return;
    if (a==sa && b == sb && ((a>=n || b>=n) && abs(a-b)>=2))
    {
        ++ans;
        return;
    }
    if ((a>=n || b>=n) && abs(a-b)>=2)
    {
        return;
    }
    dfs(a+1, b);
    dfs(a, b+1);
}
void solve() {
    cin >> n >> sa >> sb;
    ans = 0;
    dfs(0,0);
    cout << ans << endl;

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
