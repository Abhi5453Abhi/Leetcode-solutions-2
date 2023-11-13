class Solution {
public:

    /*

    ["2","1","/","3","*"]

    9

    */
    int evalRPN(vector<string>& tokens) {
       stack<int> s;
       for(int i=0;i<tokens.size();i++){
           if(tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "+"){
               int first = s.top();
               s.pop();
               int second = s.top();
               s.pop();
               int newNumber;
               if(tokens[i] == "/"){
                   newNumber = second/first;
               }
               if(tokens[i] == "+"){
                   newNumber = second+first;
               }
               if(tokens[i] == "-"){
                   newNumber = second-first;
               }
               if(tokens[i] == "*"){
                   newNumber = second*first;
               }
               s.push(newNumber);
           }else{
               s.push(stoi(tokens[i]));   
           }
       }
       return s.top();
    }
};