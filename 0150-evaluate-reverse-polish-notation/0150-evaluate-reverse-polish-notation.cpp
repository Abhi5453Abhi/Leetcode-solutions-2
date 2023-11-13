class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "/" || tokens[i] == "*" ||tokens[i] == "+" ||tokens[i] == "-"){
                    int second = s.top();
                    s.pop();
                    int first = s.top();
                    s.pop();
                    int no=0;
                    char ch = tokens[i][0];
                    cout<<ch<<" ";
                    switch(ch){
                        case '/': 
                        no = first/second;  
                        break; 
                        case '*': 
                        no = first*second;  
                        break; 
                        case '-': 
                        no = first-second;  
                        break; 
                        case '+': 
                        no = first+second;  
                        break; 
                    }
                    s.push(no);
            }else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};