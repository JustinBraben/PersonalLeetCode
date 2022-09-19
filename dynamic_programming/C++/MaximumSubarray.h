class DPSolution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;        // Current sum
        int smax = INT_MIN; // running maximum sum

        for (int num : nums) {

            sum += num;
            smax = max(smax, sum);

            if (sum < 0)
                sum = 0;
        }

        return smax;
    }
};

class DivideConquerSolution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int left, int right) {

        if (left > right) return INT_MIN;

        int middle = left + (right - left) / 2;
        int middleL = 0, middleR = 0;
        int lMax = maxSubArray(nums, left, middle - 1);
        int rMax = maxSubArray(nums, middle + 1, right);

        for (int i = middle - 1, sum = 0; i >= left; i--) {
            sum += nums[i];
            middleL = max(sum, middleL);
        }

        for (int i = middle + 1, sum = 0; i <= right; i++) {
            sum += nums[i];
            middleR = max(sum, middleR);
        }

        return max(max(lMax, rMax), middleL + middleR + nums[middle]);
    }
};