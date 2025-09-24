#include <iostream>
#include <vector>
#include <queue>
#include <limits> // For numeric_limits

const int INF = std::numeric_limits<int>::max();

// Define a pair for (weight, vertex) to use in the priority queue
using Pair = std::pair<int, int>;

// Function to run Dijkstra's algorithm
void dijkstra(int startNode, int V, const std::vector<std::vector<Pair>>& adj) {
    // 1. Create a vector to store distances and initialize with infinity
    std::vector<int> distance(V, INF);
    distance[startNode] = 0;

    // 2. Create a priority queue to store vertices to visit
    // The pair stores (distance, vertex), and the queue is a min-heap
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Iterate over all neighbors of the current vertex
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // If a shorter path is found to neighbor v
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the final distances
    std::cout << "Shortest distances from source node " << startNode << ":\n";
    for (int i = 0; i < V; ++i) {
        std::cout << "To node " << i << ": ";
        if (distance[i] == INF) {
            std::cout << "Path not reachable\n";
        } else {
            std::cout << distance[i] << "\n";
        }
    }
}

int main() {
    int V = 6; // Number of vertices
    // Adjacency list: adj[u] = { (v, weight), ... }
    std::vector<std::vector<Pair>> adj(V);

    // Build the graph
    // (u) -> (v) with weight
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});
    adj[4].push_back({5, 2});

    int startNode = 0;
    dijkstra(startNode, V, adj);

    return 0;
}