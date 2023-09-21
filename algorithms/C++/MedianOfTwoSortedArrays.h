class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Create a vector to store the merged array.
        vector<int> mergedArr;
        int i = 0, j = 0;

        // Merge the two sorted arrays into a single sorted array.
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                mergedArr.push_back(nums1[i]);
                i += 1;
            }
            else {
                mergedArr.push_back(nums2[j]);
                j += 1;
            }
        }

        // Handle remaining elements from nums1 (if any).
        while (i < nums1.size()) {
            mergedArr.push_back(nums1[i]);
            i += 1;
        }

        // Handle remaining elements from nums2 (if any).
        while (j < nums2.size()) {
            mergedArr.push_back(nums2[j]);
            j += 1;
        }

        // Calculate the middle index of the merged array.
        int mid = mergedArr.size() / 2;

        // Check if the merged array has an even or odd number of elements.
        if (mergedArr.size() % 2 == 0) {
            // If even, return the average of the two middle elements.
            return (mergedArr[mid - 1] + mergedArr[mid]) / 2.0;
        }
        else {
            // If odd, return the middle element.
            return mergedArr[mid];
        }
    }
};
