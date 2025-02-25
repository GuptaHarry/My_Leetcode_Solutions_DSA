class Solution {
public:

   void permute_new(vector<vector<int>>&ans , vector<int>&nums , int index){

    // base case 
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i= index ; i<nums.size();i++){
        swap(nums[index],nums[i]);
        permute_new(ans,nums,index+1);
        swap(nums[index],nums[i]);
    }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        

        // direct swap method
        vector<vector<int>>ans;

        permute_new(ans,nums,0);

        return ans;
    }
};