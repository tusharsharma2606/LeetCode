bool possible(vector<int>& nums,int n,int mid,int k)
{
    int count=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        
        if(sum+nums[i]<=mid)
        {
            sum+=nums[i];
        }
        else
        {
            count++;
            if(count>k || nums[i]>mid)
            {
                return false;
            }
            sum=nums[i];
        }
    }
    return true;
}


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total+=nums[i];
        }
        int s=0,e=total;
        int n=nums.size();
        int ans=-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(possible(nums,n,mid,k))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return ans;        
    }
};