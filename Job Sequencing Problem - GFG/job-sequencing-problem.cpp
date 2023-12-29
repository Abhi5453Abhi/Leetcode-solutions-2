//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(pair<int,int> p1,pair<int,int> p2){
        return p1.first > p2.first;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> vis(n+1,-1);
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++){
            v.push_back(make_pair(arr[i].profit,arr[i].dead));
        }
        sort(v.begin(),v.end(),cmp);
        int ans = 0;
        int ct = 0;
        for(int i=0;i<n;i++){
            bool flag = false;
            int dead = v[i].second;
            // cout<<v[i].first<<" "<<v[i].second<<endl;
            while(dead != 0){
                if(vis[dead] == -1){
                    ans += v[i].first;
                    ct++;
                    vis[dead] = 1;
                    break;
                }else{
                    dead--;
                }
            }
        }
        vector<int> res({ct,ans});
        return res;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends