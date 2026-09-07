#include<iostream>
using namespace std;
#include<vector>
 const int d=256;////BAse
    vector<int> computeLPS(string pattern){
        int m = pattern.length();
        vector<int> lps(m,0);
        int len =0;
        int i =1;
        while(i<m){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len= lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
    }
    void KMPSearch(string text,string pattern){
        int n= text.length();
        int m = pattern.length();
        //step 1. compute LPS
        vector<int> lps = computeLPS(pattern);
        int i =0;
        int j= 0;
        //step 2.Linear search
        while(i<n){
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            if( j==m){
                cout << "Pattern found at index "<< (i-j) << endl;
                j=lps[j-1];
            }
            else if (i<n && text[i]!=pattern[j]){
                if(j!= 0) j= lps[j-1];
                else i++;
            }
        }
    }
    //text = ABABABAB
    // p = ABAB
    const int q = 101;// modulus // prime 
    //rabin karp algorithm
    void rabinKarp(string text,string pattern){
        int n = text.length(),m = pattern.length();
        int p =0,t=0,h=1;
        for(int i =0;i<m-1;i++)
            h = (h*d)%q;//h= d^(m-1)%q
        for(int i =0;i<m;i++){
            p=(d*p + pattern[i])%q;
            t = (d*t + text[i])%q;
        }
        for(int i=0;i<=n-m;i++){
            if(p==t){
                int j=0;
                while(j<m && text[i+j]==pattern[j])j++;
                if(j==m) cout << "Found at "<< i<<endl;
            }
            if(i<n-m){
                t= (d*(t-text[i]*h)+text[i+m])%q;//rolling hash
                if(t<0) t+=q;//handle nnegative modulo
            }
        }

    }
int main(){
   rabinKarp("AABAABA","ABA");

    return 0;
}