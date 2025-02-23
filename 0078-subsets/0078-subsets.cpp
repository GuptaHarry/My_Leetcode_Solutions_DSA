class Solution {
public:


    void subseq( vector<vector<int>>&ans, vector<int>&temp , int index, int n , vector<int>arr){

        // base case 
        if( index == n){
            ans.push_back(temp);
            return ;
        }


        // No 
        subseq(ans,temp,index+1,n,arr);
        // Yes 
        temp.push_back(arr[index]);
        subseq(ans,temp,index+1,n,arr);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>temp;

        subseq( ans,temp,0,nums.size() , nums);
        return ans;
    }
};