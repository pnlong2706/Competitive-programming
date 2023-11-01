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

void solve() {
    int d;
    string m;
    cin >> d >> m;
    if ((m == "Mar" && d>=21) || (m== "Apr" && d<=20))
    {
        cout << "Aries" << endl;
        return;
    }
    if ((m == "Apr" && d>=21) || (m== "May" && d<=20))
    {
        cout << "Taurus" << endl;
        return;
    }
    if ((m == "May" && d>=21) || (m== "Jun" && d<=21))
    {
        cout << "Gemini" << endl;
        return;
    }
    if ((m == "Jun" && d>=22) || (m== "Jul" && d<=22))
    {
        cout << "Cancer" << endl;
        return;
    }
    if ((m == "Jul" && d>=23) || (m== "Aug" && d<=22))
    {
        cout << "Leo" << endl;
        return;
    }
    if ((m == "Aug" && d>=23) || (m== "Sep" && d<=21))
    {
        cout << "Virgo" << endl;
        return;
    }
    if ((m == "Sep" && d>=22) || (m== "Oct" && d<=22))
    {
        cout << "Libra" << endl;
        return;
    }
    if ((m == "Oct" && d>=23) || (m== "Nov" && d<=22))
    {
        cout << "Scorpio" << endl;
        return;
    }
    if ((m == "Nov" && d>=23) || (m== "Dec" && d<=21))
    {
        cout << "Sagittarius" << endl;
        return;
    }
    if ((m == "Dec" && d>=22) || (m== "Jan" && d<=20))
    {
        cout << "Capricorn" << endl;
        return;
    }
    if ((m == "Jan" && d>=21) || (m== "Feb" && d<=19))
    {
        cout << "Aquarius" << endl;
        return;
    }
    if ((m == "Feb" && d>=20) || (m== "Mar" && d<=20))
    {
        cout << "Pisces" << endl;
        return;
    }
}


int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //freopen( "OUT.out", "w", stdout );
    int t=1;
    cin >> t;
    while(t--)
        solve();

    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";

    return 0;
}
