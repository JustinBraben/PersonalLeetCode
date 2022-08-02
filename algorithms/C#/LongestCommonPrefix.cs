public class Solution
{
    public string LongestCommonPrefix(string[] strs)
    {
        int size = strs.Length;

        // Return empty string if empty array
        if (size == 0)
            return "";

        // Return first character of first string if only one string in the array
        if (size == 1)
            return strs[0];

        // Sorts the array based on length on string
        Array.Sort(strs);

        // find the minimum length from first
        // and last string
        int end = Math.Min(strs[0].Length, strs[size - 1].Length);

        // find the common prefix between the
        // first and last string 
        int i = 0;
        while (i < end && strs[0][i] == strs[size - 1][i])
            i++;

        string pre = strs[0].Substring(0, i);
        return pre;
    }
}