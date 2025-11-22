class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n = nums.size();
        int cnt = 0; // total operations required

        for(int i = 0; i < n; i++)
        {
            int num = nums[i];

            // ---- Calculate cost to reach NEXT multiple of 3 ----
            // next = ceil(num / 3)
            int next = (num + 2) / 3;

            // nval = how much we must ADD to reach next*3
            int nval = (next * 3) - num;

            // ---- Calculate cost to reach PREVIOUS multiple of 3 ----
            // prev = floor(num / 3)
            int prev = num / 3;

            // pval = how much we must SUBTRACT to reach prev*3
            int pval = num - (prev * 3);

            // Pick the minimum operations needed for this number
            cnt += min(pval, nval);
        }

        return cnt;
    }
};