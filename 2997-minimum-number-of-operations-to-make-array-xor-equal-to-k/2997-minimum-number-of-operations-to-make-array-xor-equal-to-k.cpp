class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a=0;
        for(int i=0;i<nums.size();i++)
        {
            a^=nums[i];
        }
        int b=a^k;
        int count=0;
        while(b>0)
        {
            if(b&1)
            {
                count++;
            }
            b=b>>1;
        }
        return count;
    }
};