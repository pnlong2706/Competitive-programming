#include <bits/stdc++.h>

using namespace std;

#define ll          long long
#define ull         unsigned long long


const long long MOD=1000000007;

ll pow_mod(ll x, ll y, ll mod) { //mod<3.10^9
    ll ans=1;
    while(y>0) {
        if(y%2==1) ans=ans*x%mod;
        y=y>>1;
        x=x*x%mod;
    }
    return ans%mod;
}

vector<int> find_all_divisors(int n)
{
    vector<int> x;
    int s = sqrt(n);
    for(int i = 1;i*i <= n;i++)
    {
        if (n%i==0)
        {
            if (n/i == i) // check if divisors are equal
                x.push_back(i);
            else
            {
                x.push_back(i);
                x.push_back(n/i);
            }
        }
    }
    
    return x;
}


void solve() {
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if (c%a){
		cout<<-1;
		return;
	}	
	vector<int> v=find_all_divisors(c/a);
	//for (int k:v) cout<<k<<'\n';
	sort(v.begin(),v.end());
	for (int k:v){
		if ((k*a)%b&&d%(k*a)){
			cout<<k*a;
			return;
		}
	}
	cout<<-1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}


