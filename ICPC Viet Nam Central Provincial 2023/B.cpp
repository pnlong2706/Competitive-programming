#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod=2023;
ll dp[105][105][105],a[105],g[105][105];



int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++){
    	for (int j=0;j<n;j++) g[i][j]=__gcd(a[i],a[j]);
    }
    for (int i=0;i<n;i++) dp[i][i][0]=1;
    for (int i=0;i<n;i++){
    	for (int k=1;k<=n;k++){
    		/*
    		ll s=0;
    		for (int j=i;j<n-1;j++){
    			if (__gcd(a[i],a[j])==1){
    				s+=dp[i][j][k-1];
    				s%=mod;
    				dp[i][j+1][k]+=s;
    				dp[i][j+1][k]%=mod;
    			}
    		}
    		*/
    		for (int j=i+1;j<n;j++){
    			for (int l=i;l<j;l++){
    				if (g[l][j]==1){
    					dp[i][j][k]+=dp[i][l][k-1];
    					dp[i][j][k]%=mod;
    				}
    			}
    		}
    	}
    }
    int q;
    cin>>q;
    while (q--){
    	int x,y,z;
    	cin>>x>>y>>z;
    	for (int i=0;i<n;i++){
    		if (a[i]==x) x=i;
    		if (a[i]==y) y=i;
    	}
    	cout<<dp[x][y][z]<<'\n';
    }
}

