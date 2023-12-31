//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void solve(vector<vector<int>>& image, int i, int j, int newColor, vector<vector<int>> &vis, int in){
        if(i <= image.size()-1 && j <= image[0].size() && i >= 0 && j >= 0){
            image[i][j] = newColor;
            vis[i][j] = 1;
            if(i+1 <= image.size()-1 && j <= image[0].size() && i+1 >= 0 && j >= 0 && vis[i+1][j] == -1 && image[i+1][j] == in){
                solve(image,i+1,j,newColor,vis,in);
            }
            if(i <= image.size()-1 && j+1 <= image[0].size() && i >= 0 && j+1 >= 0 && vis[i][j+1] == -1 && image[i][j+1] == in){
                solve(image,i,j+1,newColor,vis,in);
            }
            if(i-1 <= image.size()-1 && j <= image[0].size() && i-1 >= 0 && j >= 0 && vis[i-1][j] == -1 && image[i-1][j] == in){
                solve(image,i-1,j,newColor,vis,in);
            }
            if(i <= image.size()-1 && j-1 <= image[0].size() && i >= 0 && j-1 >= 0 && vis[i][j-1] == -1 && image[i][j-1] == in){
                solve(image,i,j-1,newColor,vis,in);
            }
        }else return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int in = image[sr][sc];
        vector<vector<int>> vis(image.size(),vector<int>(image[0].size(),-1));
        solve(image,sr,sc,newColor,vis,in);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends