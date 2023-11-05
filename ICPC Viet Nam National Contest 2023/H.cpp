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

vector<vector<ll>> st;
vector<vector<ll>> f;
vector<ll> a;
int n;

void build(int v, int node, int l, int r) {
    if(l==r) { st[v][node]=f[v][l]*f[v][l]; return; }

    build(v,node*2,l,(l+r)/2);
    build(v,node*2+1,(l+r)/2+1,r);

    st[v][node]=st[v][node*2+1]+st[v][node*2];
}

void update(int v, int node, int l, int r, int id, ll val) {
    if( r<id || id<l ) return;

    if(l==r) {
        st[v][node]=val*val;
        return;
    }

    update(v,node*2,l,(l+r)/2,id,val);
    update(v,node*2+1,(l+r)/2+1,r,id,val);

     st[v][node]=st[v][node*2+1]+st[v][node*2];
}

ll getsum(int v, int node, int l, int r, int ss, int ed) {
    if(ed<l || r<ss ) return 0;

    if( ss<=l && r<=ed ) return st[v][node];

    return getsum(v,node*2,l,(l+r)/2,ss,ed)+getsum(v,node*2+1,(l+r)/2+1,r,ss,ed);
}

int idof( vector<ll> &a, ll val ) {
    int lo=0, hi=a.size()-1;
    int mid=(lo+hi)/2;
    while(lo<hi) {
        if( a[mid] < val ) lo=mid+1;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    return lo;
}

void solve() {
    int q;
    cin >> n >> q;
    a.resize(n+1);
    f.resize(n+1);
    st.resize(n+1);
    for__(1,n+1) {
        cin >> a[i];
        f[a[i]].pb(i);
    }

    for__(1,n+1) {
        if(f[i].size()==0) continue;

        int len=f[i].size();
        st[i].resize(4*len);

        build(i,1,0,len-1);
    }

    ll last=0;
    while(q--) {
        int t, l, r;
        cin >> t;
        if(t==1) {
            cin >> l;
            l=(l+last-1)%(n-1)+1;
            r=l+1;
            int v1=a[l], v2=a[r];
            int idv1=idof(f[v1],l);
            int idv2=idof(f[v2],r);

            if(v1!=v2) {
                update(v1,1,0, (int)f[v1].size()-1, idv1, f[v1][idv1]+1 );
                update(v2,1,0, (int)f[v2].size()-1, idv2, f[v2][idv2]-1 );
                f[v1][idv1]++;
                f[v2][idv2]--;
                swap( a[l], a[r] );
            }
        }
        else if(t==2) {
            ll val;
            cin >> l >> r >> val;

            l=(l+last-1)%n+1;
            r=(r+last-1)%n+1;
            val=(val+last-1)%n+1;
            if(l>r) swap(l,r);


            if(f[val].size()==0) {
                cout << "0\n";
                last=0;
                continue;
            }

            int idl=idof(f[val],l);
            int idr=idof(f[val],r);
            // HAVE TO HANDLE EDGE CASE
            if( f[val][idr]>r ) idr--;

            if(idl>idr) {
                cout << "0\n";
                last=0;
                continue;
            }

            if(f[val][idl]<l || f[val][idr]>r ) {
                cout << "0\n";
                last=0;
                continue;
            }

            last =  getsum(val,1,0, (int)f[val].size()-1,idl,idr );
            cout << last << el;
        }
        else if(t==3) {
            ll val;
            cin >> l >> r >> val;

            l=(l+last-1)%n+1;
            r=(r+last-1)%n+1;
            val=(val+last-1)%n+1;
            if(l>r) swap(l,r);

            if(f[val].size()==0) {
                cout << "0\n";
                last=0;
                continue;
            }

            last= getsum(val,1,0,(int)f[val].size()-1,l-1,r-1);
            cout << last << el;
        }
    }




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
