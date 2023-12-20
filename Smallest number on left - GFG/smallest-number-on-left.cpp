//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// 1 8 7 6
//-1 1 1 1 

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> s;
        vector<int> ans(n,-2);
        
        for(int i=0;i<n;i++){
            if(s.empty()){
                ans[i] = -1;
            }else{
                while(!s.empty() && a[s.top()] >= a[i]){
                    s.pop();
                }
            }
            if(!s.empty()){
                ans[i] = a[s.top()];
            }
            s.push(i);// 0 1
        }
        for(int i=0;i<n;i++){
            if(ans[i] == -2)ans[i] = -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends