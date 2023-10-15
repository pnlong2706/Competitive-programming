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

const long long MOD=998244353;

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

struct segment {
    ll x, y1, y2;
    bool tp;
    segment(const ll &a,const ll &b,const ll &c, bool x ): x(a), y1(b), y2(c), tp(x) {}
};


ll st[800005];
ll lz[800005];
vector<ll> vy;
vector<segment> vsegment;
unordered_map<ll,ll> ry;

void build(ll l, ll r, ll node) {
    st[node]=lz[node]=0;
    if(l==r) return;
    build(l,(l+r)/2,2*node);
    build((l+r)/2+1,r,2*node+1);
}

void setRange(int node, int l, int r, int ss, int ed, int ad) {
    if(ed<l || r<ss || l>r ) return;

    if( ss<=l && r<=ed ) {
        lz[node]+= ad;
        if(lz[node]>0)st[node]=vy[r]-vy[l-1];
        else st[node]= (l!=r? (st[node*2]+st[node*2+1]): 0);

        return;
    }

    setRange(node*2, l, (l+r)/2, ss, ed, ad);
    setRange(node*2+1, (l+r)/2+1, r, ss, ed, ad);

    if(lz[node]>0) st[node]=vy[r]-vy[l-1];
    else st[node]= (l!=r? (st[node*2]+st[node*2+1]): 0);
}



void solve() {
    ll n, k, cx1=0, cy1=0, cx2, cy2;
    cin >> k >> n;
    cx2=cy2=k;

    for_(n) {

        ll x1, y1, x2, y2, val;
        char tp;
        cin >> tp >> val;
        if(tp=='E') {
            x1=cx1; y1=cy1; x2=cx2+val; y2=cy2;
            cx2+=val;
            cx1+=val;
        }
        else if(tp=='W') {
            x1=cx1-val; y1=cy1; x2=cx2; y2=cy2;
            cx2-=val;
            cx1-=val;
        }
        else if(tp=='S') {
            x1=cx1; y1=cy1-val; x2=cx2; y2=cy2;
            cy1-=val;
            cy2-=val;
        }
        else {
            x1=cx1; y1=cy1; x2=cx2; y2=cy2+val;
            cy1+=val;
            cy2+=val;
        }


        segment np1(x1,y1,y2,true);
        segment np2(x2,y1,y2,false);

        vsegment.pb(np1);
        vsegment.pb(np2);
        vy.pb(y1);
        vy.pb(y2);
    }

    sort(vy.begin(),vy.end());
    auto uit=unique(vy.begin(),vy.end());
    vy.resize(distance(vy.begin(),uit));
    ll M=vy.size();

    for(int i=0; i<M; i++) ry[vy[i]]=i+1;
    build(1,M-1,1);
    sort(vsegment.begin(),vsegment.end(), [] (const segment &a, const segment &b) -> bool { return a.x < b.x; } );

    ll ans=0;
    for(int i=0; i<2*n; i++) {
        if(i!=0) ans+=st[1]*( vsegment[i].x - vsegment[i-1].x );
        if(vsegment[i].tp) setRange(1,1,M-1, ry[ vsegment[i].y1 ],ry[ vsegment[i].y2 ]-1,1);
        else setRange(1,1,M-1, ry[ vsegment[i].y1 ], ry[ vsegment[i].y2 ]-1,-1);
    }
    cout << ans << el;

}


int main() {
    //clock_t begin=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("INP.inp","r",stdin);
    //freopen( "OUT2.out", "w", stdout );
    int t=1;
    //cin >> t;
    while(t--)
        solve();

    //cout << "TIME : " << (double)(clock()-begin)/CLOCKS_PER_SEC << "s.";
    return 0;
}
