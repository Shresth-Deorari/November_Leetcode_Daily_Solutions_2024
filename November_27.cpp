class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        vector<int>distances(n,0);
        for(int i =0;i<n-1;i++){
            adj[i].push_back(i+1);
            distances[i] = i;
        }
        distances[n-1] = n-1;
        vector<int>ans;
        for(auto i : queries){
            int u = i[0];
            int v = i[1];
            distances[v] = min(distances[v],distances[u]+1);
            adj[u].push_back(v);
            queue<pair<int,int>>q;
            q.push({v,distances[u]+1});
            while(!q.empty()){
                int curr = q.front().first;
                int dist = q.front().second;
                q.pop();
                for(auto it : adj[curr]){
                    if(dist+1 < distances[it]){
                        distances[it] = dist +1;
                        q.push({it,distances[it]});
                    }
                }
            }
            ans.push_back(distances[n-1]);
        }
        return ans;
    }
};