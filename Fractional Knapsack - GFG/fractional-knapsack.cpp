//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,pair<int,int> >> v;
        for(int i=0;i<n;i++){
            double temp = (double)(arr[i].value)/arr[i].weight;
            v.push_back(make_pair(temp,make_pair(arr[i].value,arr[i].weight)));
        }
        
        sort(v.begin(),v.end());
        // for(int i=0;i<n;i++){
        //     cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        // }
        int end = n-1;
        double ans = 0;
        while(end >= 0 && W >= 0){
            if(v[end].second.second <= W){
                ans += v[end].second.first;
                W -= v[end].second.second;
                end--;
            }else{
                ans = ans + double(v[end].second.first)/v[end].second.second*W;
                W -= v[end].second.second;
                // break;
            }
        }
        // cout<<end<<" "<<W<<" ";
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends