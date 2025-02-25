// class Solution {
// public:

//     void combine( vector<vector<int>>&ans, vector<int>&temp , vector<int>&arr,int index , int t ){
//         if( t ==0){
//             for(int i=0 ; i<ans.length;i++){
//                 for(int j=0 ; j < ans[i];j++){

//                 }
//             }
//             ans.push_back(temp);
//             return;

//         }

//         if( index == arr.size() || t <0){
//             return;
//         }


//         //No 
//         combine(ans,temp,arr,index+1,t);
//         // Yes
//         temp.push_back(arr[index]);
//         combine(ans,temp,arr,index+1,t-arr[index]);
//         temp.pop_back();
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
//         vector<vector<int>>ans;
//         vector<int>temp;
        
//         combine(ans,temp,candidates,0,target);
//         return ans;

//     }
// };  



class Solution {
public:
    void combine(vector<vector<int>>& ans, vector<int>& temp, vector<int>& arr, int index, int t) {
        if (t == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            // Skip duplicate numbers at the same level
            if (i > index && arr[i] == arr[i - 1]) continue;

            // If the number exceeds target, stop further recursion
            if (arr[i] > t) break;

            // Include the number in the combination
            temp.push_back(arr[i]);

            // Recur for the next elements (without reusing the same index)
            combine(ans, temp, arr, i + 1, t - arr[i]);

            // Backtrack: Remove the last number
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        // Sort to handle duplicates easily
        sort(candidates.begin(), candidates.end());

        combine(ans, temp, candidates, 0, target);
        return ans;
    }
};
