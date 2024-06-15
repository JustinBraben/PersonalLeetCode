class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        queue<int> roomsQ;

        roomsQ.push(0); // Start from room 0

        while (!roomsQ.empty()) {
            int size = roomsQ.size();

            for (int i = 0; i < size; i++) {
                int room = roomsQ.front();
                roomsQ.pop();
                visited[room] = true;
                for (int ele : rooms[room])
                    if (!visited[ele]) roomsQ.push(ele);
            }
        }
        return count(visited.begin(), visited.end(), true) == rooms.size();
    }
};