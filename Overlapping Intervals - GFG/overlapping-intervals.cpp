//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
	    return v1[0] < v2[0];
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<int> > ans;
        sort(arr.begin(), arr.end(), cmp);
        int first = arr[0][0];
        int second = arr[0][1];
        for(int i=1;i<n;i++){
        	if(arr[i][0] <= second){
        		first = min(arr[i][0],first);
        		second = max(arr[i][1],second);
        	}else{
        		ans.push_back({first,second});
        		first = arr[i][0];
        		second = arr[i][1];
        	}
        }
        ans.push_back({first,second});
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends