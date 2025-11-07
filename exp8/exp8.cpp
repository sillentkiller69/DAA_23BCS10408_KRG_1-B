class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Create adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // if undirected graph
        }

        // Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Min-heap: (distance, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue; // Skip outdated entry

            for (auto [v, w] : adj[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};
