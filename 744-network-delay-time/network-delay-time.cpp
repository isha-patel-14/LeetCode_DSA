class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto &edge : times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            graph[u].push_back({w,v});
        }
        vector<int> distance(n+1,INT_MAX);
        distance[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int dist=pq.top().first;
            int u=pq.top().second;
            pq.pop();

            if(dist>distance[u]) continue;
            for(auto edge:graph[u]){
                int w=edge.first;
                int v=edge.second;

                if(distance[v]>distance[u]+w){
                    distance[v]=distance[u]+w;
                    pq.push({distance[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;

            ans=max(ans,distance[i]);
        }
        return ans;
    }
};