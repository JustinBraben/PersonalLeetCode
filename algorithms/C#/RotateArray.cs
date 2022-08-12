public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        int n = nums.Length;

        k = k % n;

        Reverse(nums, 0, n - k - 1);
        Reverse(nums, n - k, n - 1);
        Reverse(nums, 0, n - 1);
    }

    void Reverse(int[] nums, int i, int j)
    {
        while (i < j)
        {
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;
        }
    }
}