//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

/*

10 20 30 40

10 30 60 100

*/

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int solve(int A[], int n, int m, int mid){
    int maxi = 0;
    int temp = 0;
    int ct = 0;
    // cout<<mid<<" ";
    for(int i=0;i<n;i++){
        if(temp + A[i] <= mid){
            temp += A[i];
        }else{
            maxi = max(temp, maxi);
            temp = A[i];
            ct++;
        }
    }
    ct++;
    maxi = max(temp, maxi);
    // cout<<maxi<<" ";
    // cout<<ct<<endl;
    if(ct <= m){
        return maxi;
    }else{
        return -1;
    }
    return maxi;
}
    int findPages(int A[], int N, int M) 
    {
        if(M > N)return -1;
        int end = 0;
    for(int i=0;i<N;i++){
        end += A[i];
    }
    int start = 0;
    int ans = INT_MAX;
    while(start <= end){
        int mid = (start + end)/2;
        int currentPages = solve(A,N,M,mid);
        if(currentPages <= ans && currentPages != -1){
            ans = currentPages;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends