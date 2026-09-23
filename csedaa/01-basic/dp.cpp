// recursion 
#include<iostream>
#include<vector>
using namespace std;


int fib(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> dp(n+1, -1); // Initialize a vector for memoization
    int prev1 = 0;
    int prev2 =1;
    for(int i =2;i<=n;i++){
        int curr = prev1+prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    cout << "Fibonacci number at position " << n << " is: " << fib(n,dp) << endl;
    return 0;
}   


int knapsackMemo(vector<int> wt,vector<int> val,
    int w,int n,vector<vector<int>> &memo){
        //wt[] ={1,1,1} w=2 val[]={10,20,30}
        if(n==0 || w == 0) return 0;
        if(memo[n][w] != -1) 
            return memo[n][w];
        int pick =0;
        if(wt[n-1] <= w){
            pick = val[n-1] + knapsack(wt,val,
                w-wt[n-1],n-1);
            int notPick = knapsack(wt,val,w,n-1);

            return memo[n][w]= max(pick,notPick);
        }

    }

int knapsack(vector<int> wt,vector<int> val,
    int w,int n){
        //wt[] ={1,1,1} w=2 val[]={10,20,30}
        if(n==0 || w == 0) return 0;
        int pick =0;
        if(wt[n-1] <= w){
            pick = val[n-1] + knapsack(wt,val,
                w-wt[n-1],n-1);
            int notPick = knapsack(wt,val,w,n-1);

            return max(pick,notPick);
        }

    }