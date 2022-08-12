public class Solution
{
    public int[] SortedSquares(int[] nums)
    {
        int[] sortSquare = new int[nums.Length];
        int i = 0;
        while (i < nums.Length)
        {
            sortSquare[i] = nums[i] * nums[i];
            i++;
        }
        Array.Sort(sortSquare);
        return sortSquare;
    }
}