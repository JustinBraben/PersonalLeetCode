public class Solution
{
    public int[] TwoSum(int[] numbers, int target)
    {
        int[] indices = new int[2] { -1, -1 };
        int s = 0;
        int e = numbers.Length - 1;
        while (s < e)
        {
            if ((numbers[s] + numbers[e]) == target)
            {
                indices[0] = s + 1;
                indices[1] = e + 1;
                return indices;
            }
            else if ((numbers[s] + numbers[e]) < target)
            {
                s++;
            }
            else if ((numbers[s] + numbers[e]) > target)
            {
                e--;
            }
        }
        return indices;
    }
}