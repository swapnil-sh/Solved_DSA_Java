// Variation of Unbounded Knapsack problem

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int maxCutSegments(int a[],int l,int n)
{
    int dp[l+1][n+1];
    int i,j;
    
    memset(dp,0,sizeof(dp));
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<n+1;j++)
        {
            if(i==0)
                dp[i][j] = INT_MIN;
         
        }
    }
    
    for(i=1;i<l+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            if(a[i-1]>j)
                dp[i][j] = dp[i-1][j];
            if(a[i-1]<=j)
                dp[i][j] = max(1+dp[i][j-a[i-1]],dp[i-1][j]);
        }
    }
    
    return dp[l][n];
}


int main() 
{

      int t;
      cin>>t;
    
      while(t--)
      {
    
      int n;
      cin>>n;
    
      int a[3],l = 0;
      set<int> s;
    
      for(int i=0;i<3;i++)
      {
        int x;
        cin>>x;
        s.insert(x);
      }
    
      for(auto i = s.begin();i != s.end();i++)
      { 
          //inserting only unique numbers
        a[l] = *i;
        l++;
      }
    
      cout<<maxCutSegments(a,l,n)<<"\n";
    	    
    }
	return 0;
}
