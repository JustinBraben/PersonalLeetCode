public class Solution
{
    public int Reverse(int x)
    {
        int result = 0;
        bool negative = x < 0;

        if (negative)
            x *= -1;

        while (x != 0)
        {
            int currentDigit = x % 10;
            int tmp = result * 10;

            if (tmp / 10 != result)
                return 0;
            result = tmp + currentDigit;
            x /= 10;
        }

        if (negative)
            return result * -1;

        return result;
    }
}