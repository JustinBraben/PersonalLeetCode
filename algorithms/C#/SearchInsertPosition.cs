public class Solution
{
    public int SearchInsert(int[] nums, int target)
    {
        int start = 0;
        int end = nums.Length;
        int index = -1;

        // Loop through the upper and lower boundaries of the int array
        // and update the boundaries depending on what value the current 
        // index is in relation to the target value
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            // out of bounds of the array
            // exit loop
            if (mid >= nums.Length)
                break;

            // target value is less than value at nums[mid]
            // set index to mid point
            // set upper bound to 1 less than the mid point
            if (target < nums[mid])
            {
                index = mid;    // Could be the ceiling
                end = mid - 1;

                // if target is higher than the value at nums[mid]
                // set lower bound to 1 more than the mid point
            }
            else if (target > nums[mid])
            {
                start = mid + 1;

                // if target is == to value at nums[mid] you found the target in the array
            }
            else
            {
                return mid;
            }
        }
        // if index does not equal -1 return index (some number greater than or equal to 0)
        // if index is != -1 return start (lowest boundary)
        return index != -1 ? index : start;
    }
}