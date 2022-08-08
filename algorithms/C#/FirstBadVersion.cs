/* The isBadVersion API is defined in the parent class VersionControl.
      bool IsBadVersion(int version); */

public class Solution : VersionControl
{
    public int FirstBadVersion(int n)
    {
        int start = 0;
        int end = n;
        int mid = 0;
        int target = 0;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (IsBadVersion(mid))
            {
                target = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return target;
    }
}