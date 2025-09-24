#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a weighted edge
struct Edge {
    int src, dest, weight;
};

// Disjoint Set Union (DSU) data structure
struct DSU {
    std::vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
        }
    }
};

// Comparison function for sorting edges
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskalMST(int V, std::vector<Edge>& edges) {
    // 1. Sort all edges by weight
    std::sort(edges.begin(), edges.end(), compareEdges);
    
    DSU dsu(V);
    std::vector<Edge> mst;
    int mstWeight = 0;
    
    // 2. Iterate through sorted edges
    for (const auto& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            dsu.unite(edge.src, edge.dest);
            mst.push_back(edge);
            mstWeight += edge.weight;
        }
    }
    
    // 3. Print the MST
    std::cout << "Edges in the MST (Kruskal's):\n";
    for (const auto& edge : mst) {
        std::cout << edge.src << " -- " << edge.dest << " (Weight: " << edge.weight << ")\n";
    }
    std::cout << "Total MST Weight: " << mstWeight << std::endl;
}

int main() {
    int V = 4; // Number of vertices
    std::vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    
    kruskalMST(V, edges);
    return 0;
}