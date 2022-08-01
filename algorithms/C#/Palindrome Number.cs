public class Solution
{
    public int Reverse(int x)
    {
        int result = 0;
        bool negative = false;

        if (x < 0)
        {
            negative = true;
            x = -x;
        }

        while (x != 0)
        {
            int currentDigit = x % 10;
            result = result * 10 + currentDigit;
            x /= 10;
        }

        return result;
    }
    public bool IsPalindrome(int x)
    {
        if (x < 0)
            return false;

        return ((Reverse(x) == x));
    }
}