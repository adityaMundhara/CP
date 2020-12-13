#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
vector<ll> countVal;

int main()
{	int N,K;
	cin>>N>>K;
	vector<ll> dp(N,0);
	
	for(int i=0;i<N;i++)
	{	int a;
		cin>>a;
		countVal.push_back(a);
	}
	dp[0]=0;
	dp[1]=abs(countVal[1]-countVal[0]);
	for(ll i=2;i<countVal.size();i++)
	{	ll mi=INT_MAX;
		for(ll j=i-1;j>=i-K && j>=0 ;j--)
		{
			mi=min(mi,dp[j]+abs(countVal[i]-countVal[j]));
		}
		dp[i]=mi;
	}

	cout<<dp[N-1];
	return 0;
}