#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
vector<ll> countVal;

int main()
{	int N;
	cin>>N;
	vector<ll> dp(N,0);
	
	for(int i=0;i<N;i++)
	{	int a;
		cin>>a;
		countVal.push_back(a);
	}
	dp[0]=0;
	dp[1]=abs(countVal[1]-countVal[0]);
	
	for(ll i=2;i<countVal.size();i++)
	{	
		dp[i]=min(dp[i-1]+abs(countVal[i-1]-countVal[i]),dp[i-2]+abs(countVal[i-2]-countVal[i]));
	}

	cout<<dp[N-1];
	return 0;
}