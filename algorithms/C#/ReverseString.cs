public class Solution
{
    public void ReverseString(char[] s)
    {
        Reverse(s, 0, s.Length - 1);
    }

    public void Reverse(char[] s, int i, int j)
    {
        while (i < j)
        {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
    }
}