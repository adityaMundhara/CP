#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


/*
	1st case  : only one day
		10 20 30 ==> max of them is ans
	2nd case : 2 days
		10 20 30
		20 10 50 ==> Greedy doesn't work
	get max while iterating from 1st dp and get all the max values
	make that as new dp	

*/


int main()
{
	vector<vector<int>> countVal;
	int N;
	cin >> N;
	vector<int> dp(3, 0);
	for (int i = 0; i < N; i++)
	{	
		vector<int> c(3),newDp(3,0);
		for(int i=0;i<3;i++)cin>>c[i];

		for(int i=0;i<3;i++){
			// original dp ==>i
			for(int j=0;j<3;j++){
				if(i!=j){
					newDp[j] = max(newDp[j],dp[i]+c[j]);
				}
			}
		}
		dp=newDp;
	}
	cout << max({dp[0],dp[1],dp[2]});
	return 0;
}