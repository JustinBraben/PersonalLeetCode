public class Solution
{
    public void MoveZeroes(int[] nums)
    {
        int n = nums.Length;

        // exit if array is 0 or 1 length (nothing to reposition)
        if (n == 0 || n == 1)
        {
            return;
        }

        // Left and right indexes to compare
        int left = 0;
        int right = 0;

        // Keep looping until the right boundary is out of index upper range
        while (right < n)
        {
            // Move upper bound if upper bound 0
            if (nums[right] == 0)
            {
                right++;
            }
            else
            {
                // Swap left and right index if right value
                // does not equal 0
                // will work on long runs of 0
                // only when swapping we increment left and right index

                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                left++;
                right++;
            }
        }
    }
}