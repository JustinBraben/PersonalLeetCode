int manhattan_distance(vector<int>& p1, vector<int>& p2) {
    // Calculate Manhattan distance between two points
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); // Number of points in the input
        vector<bool> visited(n, false); // Keep track of visited points
        unordered_map<int, int> heap_dict; // Store distances to points
        for (int i = 0; i < n; ++i) {
            heap_dict[i] = INT_MAX; // Initialize all distances to infinity
        }
        heap_dict[0] = 0; // Start node

        // Define a lambda function for comparing pairs (distance, point)
        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);
        min_heap.push({ 0, 0 }); // Initialize the min heap with the start node

        int mst_weight = 0; // Initialize total minimum spanning tree weight

        // Main loop of Prim's algorithm
        while (!min_heap.empty()) {
            auto [w, u] = min_heap.top(); // Extract the minimum distance
            min_heap.pop(); // Remove the top element

            // Skip this node if it has been visited or a shorter distance has been found
            if (visited[u] || heap_dict[u] < w) continue;

            visited[u] = true; // Mark the node as visited
            mst_weight += w; // Add the current edge weight to the total

            // Update distances to neighboring nodes
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int new_distance = manhattan_distance(points[u], points[v]);
                    // If a shorter distance to 'v' is found, update the distance and add it to the heap
                    if (new_distance < heap_dict[v]) {
                        heap_dict[v] = new_distance;
                        min_heap.push({ new_distance, v });
                    }
                }
            }
        }

        return mst_weight; // Return the total minimum spanning tree weight
    }
};
