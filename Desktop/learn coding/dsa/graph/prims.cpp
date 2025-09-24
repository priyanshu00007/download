#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();
using Pair = std::pair<int, int>; // pair<weight, vertex>

void primMST(int V, const std::vector<std::vector<Pair>>& adj) {
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    std::vector<int> key(V, INF);
    std::vector<int> parent(V, -1);
    std::vector<bool> inMST(V, false);
    
    int startNode = 0;
    pq.push({0, startNode});
    key[startNode] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        inMST[u] = true;
        
        // Iterate over all neighbors
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    
    // Print the MST
    std::cout << "Edges in the MST (Prim's):\n";
    int mstWeight = 0;
    for (int i = 1; i < V; ++i) {
        std::cout << parent[i] << " -- " << i << " (Weight: " << key[i] << ")\n";
        mstWeight += key[i];
    }
    std::cout << "Total MST Weight: " << mstWeight << std::endl;
}

int main() {
    int V = 9;
    std::vector<std::vector<Pair>> adj(V);
    
    // Add edges to the graph (for Prim's)
    adj[0].push_back({1, 4}); adj[0].push_back({7, 8});
    adj[1].push_back({0, 4}); adj[1].push_back({2, 8}); adj[1].push_back({7, 11});
    adj[2].push_back({1, 8}); adj[2].push_back({3, 7}); adj[2].push_back({8, 2}); adj[2].push_back({5, 4});
    adj[3].push_back({2, 7}); adj[3].push_back({4, 9}); adj[3].push_back({5, 14});
    adj[4].push_back({3, 9}); adj[4].push_back({5, 10});
    adj[5].push_back({2, 4}); adj[5].push_back({3, 14}); adj[5].push_back({4, 10}); adj[5].push_back({6, 2});
    adj[6].push_back({5, 2}); adj[6].push_back({7, 1}); adj[6].push_back({8, 6});
    adj[7].push_back({0, 8}); adj[7].push_back({1, 11}); adj[7].push_back({6, 1}); adj[7].push_back({8, 7});
    adj[8].push_back({2, 2}); adj[8].push_back({6, 6}); adj[8].push_back({7, 7});

    primMST(V, adj);
    return 0;
}