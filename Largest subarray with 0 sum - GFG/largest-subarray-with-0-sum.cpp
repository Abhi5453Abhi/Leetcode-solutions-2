//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    //-1 1 -1 1
    //-1 0 -1 0
    int solve(vector<int>&A, int n){
        vector<int> v;
        int ans = 0;
        int temp = 0;
        map<int,int> ma;
        for(int i=0;i<n;i++){
            temp += A[i];
            // cout<<temp<<" ";
            if(temp == 0){
                ans = i+1;
            }
            else if(ma[temp]){
                // cout<<i<<" "<<temp<<" "<<ma[temp]<<endl;
                ans = max(ans,i-ma[temp]+1);
            }else{
                ma[temp] = i+1;
            }
        }
        return ans;
    }
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        return solve(A,n);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends