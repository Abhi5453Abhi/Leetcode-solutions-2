class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
    for(int i=0;i<n;i++){
        bool flag = false;
        string temp = "";
        if((i+1) % 3 == 0){
            temp += "Fizz";
            flag = true;
        }
        if((i+1) % 5 == 0){
            temp += "Buzz";
            flag = true;
        }
        if(!flag){
            temp += to_string(i+1);
        }
        ans.push_back(temp);
    }
    return ans;
    }
};