//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int,int> v1,pair<int,int> v2){
        return v1.second < v2.second;
    }
    int maxMeetings(int arr[], int dep[], int n)
    {
        // Your code here
        vector<pair<int,int> > v;
    	for(int i=0;i<n;i++){
    	    v.push_back(make_pair(arr[i],dep[i]));
    	}
    	sort(v.begin(),v.end(),cmp);
    	int ans = 1;
    	int end = v[0].second;
    	for(int i=1;i<n;i++){
    	   // cout<<v[i].first<<" "<<v[i].second<<endl;
    	    if(v[i].first > end){
    	        ans++;
    	        end = v[i].second;
    	    }
    	}
    	return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends