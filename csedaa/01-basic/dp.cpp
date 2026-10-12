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
    


int knapsackTable(vector<int> wt,vector<int> val,
    int W,int n){
        vector<vector<int>> memo(n+1,vector<int>(W+1,0));
        //wt[] ={1,1,1} w=2 val[]={10,20,30}
        for(int i=1;i<=n;i++){
            for( int j =0;j<=W;j++){
                if( wt[i-1] <= j){
                    memo[i][j] = max(val[i-1]+memo[i-1][j-wt[i-1]],
                    memo[i-1][j]);
                }
                else{
                    memo[i][j]= memo[i-1][j];
                }
            }
        }
        // if(n==0 || w == 0) return 0;
        // if(memo[n][w] != -1) 
        //     return memo[n][w];
        // int pick =0;
        // if(wt[n-1] <= w){
        //     pick = val[n-1] + knapsack(wt,val,
        //         w-wt[n-1],n-1);
        //     int notPick = knapsack(wt,val,w,n-1);

        //     return memo[n][w]= max(pick,notPick);
        // }

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

    //Binomial coefficient
    // number of ways to choose k objects from n objects
    // n = 4 k =2  A B C D
    // AB AC AD BC BD CD
    // n!/k! * (n-k)!
    int binomial(int n,int k){
        //base case
        //m,emoisation
        if(k==0 || k==n) return 1;
        return binomial(n-1,k-1)+ binomial(n-1,k);
    }

    // recursion code for lcs
    int LCS(string X,string Y,int i,int j){
        if(i==0 || j==0) return 0;
        //match
        if(X[i-1]==Y[j-1]) 
            return 1 + LCS(X,Y,i-1,j-1);
        return max(
            LCS(X,Y,i-1,j),
            LCS(X,Y,i,j-1)
        );

    }
      // recursion code with memoisation for lcs O{nxm}+ recursion stack
    int LCS(string X,string Y,int i,int j,vector<vector<int>>& dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        //match
        if(X[i-1]==Y[j-1]) 
            return dp[i][j]= 1 + LCS(X,Y,i-1,j-1);

        return dp[i][j]= max(
            LCS(X,Y,i-1,j),
            LCS(X,Y,i,j-1)
        );

    }
    //tabulation = O(mxn) bottom up 
    // fill our first row and column with 0
    //LCS("",anything) = 0
    //LCS(anything,"") = 0
    //tabulation formula
    // if(X[i-1] == Y[j-1])
        // dp[i][j] = 1 + dp[i-1][j-1]; 
    // else
    //  dp[i][j] = max(
    //  dp[i-1][j],dp[i][j-1]
    // );
    int LCS(string X,string Y){
        int m= X.size();
        int n = Y.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i =1;i<=m;i++){
            for(int j =1;j<=n;j++){
                //match
                if(X[i-1]==Y[j-1]) 
                    return dp[i][j]= 1 +  dp[i-1][j-1];
                else
                 dp[i][j]= max(
                    dp[i-1][j],dp[i][j-1]
                );
            }
        }
        return dp[m][n];

    }

    // Matrix chain multiplication
    // A = 10 x 20
    // B = 20 x 30
    // c = 30 x 40
     // a = 4 x 2
     // b = 2 x 4
     // c = 4 x 4
        //  (axb)c
     // 4 x 2 x 4 = 16 multiplications 
    // ab = 4x4 
    // 4 x 4 x4 =64
    //16+64=80 multipication
    //a(bxc)
        // bxc = 2 x 4 x 4 = 32
        //bxc = (2x4)
            //  = 4 x 2 x 4 =32
        //32 + 32 = 64
        //thats why here order of multipication matters
 // find the paranthesization that requires the minimum number of scalar multiplication
 // p = [10,20,30,40]
 // a1 = p[0]x p[1]
 // a2 = p[1]x p[2]
 // a3 = p[2]x p[3]

//  a1 a2 a3 
// a1 | a2 a3
// a1 a2 | a3
// if i==j return 0



//BST - node based binary tree structure used to maintain sorted data efficiently
//1. all values in its left subtree must be strictly less than the node value
//2. all values in its right subtree must be strictly greater than the node value

// OBST - known as a weight balanced tree 
// keys -      10 20 30
// frequency - 5   2   1
// tree 1
// 10 20 30
// 1  2  3 

// 5*1 + 2*2 + 1*3 = 12
// tree 2
// 20 10 30 
// 1   2  2

// 2*1 + 5*2 + 1*2 = 14

// cost = freq * depth
// total cost = sum(freq*depth)

//k1,k2,k3
// k1,k2,k3

// k2 as root node

// left k1
    // left problem - OBST(i,r-1)
// right k3
    // left problem - OBST(r+1,i)
// root
    // freq[i]+freq[i+1]....+freq[j]
    //sum(i,j)
// cost = left + right + sum of frequencies
//OBST(i,j) = min over r{
    //     OBST(i,r-1)+
    //     OBST(r+1,j)+
    //     sum(i,j)
    // }

// what if there is no keys?
// obst(i,j) = 0 when i>j;
// if(i>j)return 0;
// if(i==j) return freq[i];

int obst(vector<int>& freq,int i, int j){
    if(i> j) return 0;
    if(i==j) return freq[i];
    int sum =0;
    for(int k =i;k<=j;k++)
        sum+=freq[k];
    int ans = INT_MAX;
    for(int r=i;r<=j;r++){
        int left = obst(freq,i,r-1);
        int right = obst(freq,r+1,j);
        int cost = left + right + sum;
        ans = min(ans,cost);
    }
    return ans;
}

int obst(vector<int>& freq,int i, int j,vector<vector<int>>& dp){
    if(i> j) return 0;
    if(i==j) return freq[i];
   
    if(dp[i][j]!=-1) return dp[i][j];

    int sum =0;
    for(int k =i;k<=j;k++)
        sum+=freq[k];
    int ans = INT_MAX;
    for(int r=i;r<=j;r++){
        int left = obst(freq,i,r-1,dp);
        int right = obst(freq,r+1,j,dp);
        int cost = left + right + sum;
        ans = min(ans,cost);
    }
    return dp[i][j] = ans;
}
