//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        queue<pair<int,int> > q;
        vector<int> vis(V+1,-1);
        for(int k=0;k<V;k++){
            if(vis[k] == -1){
                q.push(make_pair(k,-1));
                while(!q.empty()){
                    int first = q.front().first;
                    int second = q.front().second;
                    q.pop();
                    vis[first] = 1;
                    for(int i=0;i<adj[first].size();i++){
                        if(adj[first][i] != second){
                            if(vis[adj[first][i]] == 1)return true;
                            else{
                                vis[adj[first][i]] = 1;
                                q.push(make_pair(adj[first][i],first));
                            }
                        }
                    }
                }
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends