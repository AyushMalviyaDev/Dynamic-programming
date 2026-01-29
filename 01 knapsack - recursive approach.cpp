// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;


int knap(int wt[], int val[], int n, int W){
    if(n==0 || W==0){
        return 0 ; 
    }
    if(wt[n-1]<= W){
        return max(val[n-1]+knap(wt,val,n-1,W-wt[n-1]), knap(wt, val, n-1, W));  
    }
    else if (wt[n-1]>W){
        return knap(wt, val, n-1, W);

    }
}

int main() {
	int wt[] = {1, 3, 4, 5};
	int val[] = {1, 4, 5, 7}; 
    int n = 4; 
    int W = 7; 

    int ans = knap(wt, val, n, W); 
  cout<<ans; 


    return 0; 
}
