#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num_boats(vector<int>& people, int limit) {
    // Sort the people array in non-decreasing order
    sort(people.begin(), people.end());

    // Initialize left and right pointers and boats count
    int left = 0, right = people.size() - 1;
    int boats = 0;

    // Iterate through the array
    while (left <= right) {
        // If we can fit the lightest and heaviest person in a boat, increment the left pointer
        if (people[left] + people[right] <= limit) {
            left++;
        }

        // Always decrement the right pointer
        right--;

        // Increment boats count since we need a boat for each pair or single person
        boats++;
    }

    // Return the boats count
    return boats;
}

int main() {
    // Example usage
    vector<int> people = { 3, 2, 2, 1 };
    int limit = 3;

    // Call the num_boats function and print the result
    int boats = num_boats(people, limit);
    cout << "Minimum number of boats: " << boats << endl;

    return 0;
}
