public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {

        var charSet = new HashSet<object>();
        var l = 0;
        var res = 0;
        foreach (var r in Enumerable.Range(0, s.Length))
        {
            while (charSet.Contains(s[r]))
            {
                charSet.Remove(s[l]);
                l += 1;
            }
            charSet.Add(s[r]);
            res = Math.Max(res, r - l + 1);
        }
        return res;
    }
}