class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dynamics(nums.size());
        int suffix=1,prefix=1;
        for(int i=0;i<nums.size();i++){
            dynamics[i]=prefix;
            prefix*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            dynamics[i]*=suffix;;
            suffix*=nums[i];
        }
        return dynamics;
    }
};