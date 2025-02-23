class Solution {
public:


    void generate( vector<string>&ans , string &temp , int left , int right , int n){
            

            // base case 
            if( left+right == 2*n){
                ans.push_back(temp);
                return;
            }


            // left wala
            if(left < n){
                temp.push_back('(');
                generate(ans,temp,left+1,right,n);
                temp.pop_back();

            }

            if(right<left){
                temp.push_back(')');
                generate(ans,temp,left,right+1,n);
                temp.pop_back();
            }
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
         string temp;
       
        generate(ans,temp,0 , 0 , n);
        return ans;
    }

};