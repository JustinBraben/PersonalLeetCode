class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        // Step 1: Create a graph using an unordered map.
        unordered_map<string, vector<string>> graph;

        // Step 2: Populate the graph with source and destination airports.
        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }

        // Step 3: Sort destinations in reverse order for each source airport.
        for (auto& [_, dests] : graph) {
            sort(dests.rbegin(), dests.rend());
        }

        // Step 4: Initialize stack and itinerary vectors.
        std::vector<std::string> stack = { "JFK" };
        std::vector<std::string> itinerary;

        // Step 5: Perform depth-first search on the graph.
        while (!stack.empty()) {
            std::string curr = stack.back();
            if (graph.find(curr) != graph.end() && !graph[curr].empty()) {
                // If there are remaining destinations, push the last one onto the stack.
                stack.push_back(graph[curr].back());
                graph[curr].pop_back();
            }
            else {
                // If there are no more destinations, add the current airport to the itinerary.
                itinerary.push_back(stack.back());
                stack.pop_back();
            }
        }

        // Step 6: Reverse the itinerary to obtain the correct order.
        std::reverse(itinerary.begin(), itinerary.end());

        // Step 7: Return the final itinerary.
        return itinerary;
    }
};