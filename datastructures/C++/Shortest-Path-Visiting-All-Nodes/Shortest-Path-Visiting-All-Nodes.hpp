class Solution {
    // Define a struct to represent the state of the traversal
    struct State {
        int mask, node, dist; // mask: current visited nodes, node: current node, dist: distance traveled
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();           // Number of nodes in the graph
        int all_visited = (1 << n) - 1; // A bitmask representing all nodes visited
        queue<State> q;                 // Initialize a queue to perform BFS
        unordered_set<int> visited;     // Keep track of visited states using a hash set

        // Initialize the queue and visited set with starting nodes
        for (int i = 0; i < n; ++i) {
            q.push({ 1 << i, i, 0 });             // Start from each node individually
            visited.insert((1 << i) * 16 + i);  // Use a hash value to uniquely identify the state
        }

        // Keep looping through the queue until it is empty
        while (!q.empty()) {
            State cur = q.front(); q.pop();     // Get the current state from the queue

            // If all nodes are visited, return the distance traveled
            if (cur.mask == all_visited) {
                return cur.dist;
            }

            // Explore neighbors of the current node
            for (int neighbor : graph[cur.node]) {
                int new_mask = cur.mask | (1 << neighbor);      // Update the bitmask with the new neighbor
                int hash_value = new_mask * 16 + neighbor;      // Calculate a unique hash value for the new state

                // If the new state has not been visited before, mark it as visited and enqueue it
                if (visited.find(hash_value) == visited.end()) {
                    visited.insert(hash_value);
                    q.push({ new_mask, neighbor, cur.dist + 1 }); // Enqueue the new state with updated distance
                }
            }
        }

        // If there is no path to visit all nodes, return -1
        return -1;
    }
};
