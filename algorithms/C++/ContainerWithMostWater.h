class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {

            // determine area based on right to left index, and the min height at
            // left and right index
            int area = (right - left) * min(height[left], height[right]);

            // adjusts result to the higher value, current area, or previous max
            res = max(res, area);

            // Depending on which height at index is lower
            // reduce scope from that pointer
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return res;
    }
};