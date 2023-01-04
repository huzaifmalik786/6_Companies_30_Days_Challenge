//Link to soution : https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/870993582/

class Solution {

    long find(int a, int b, char Operator){
        if(Operator == '+') return a + b;
        else if(Operator == '-') return a - b;
        else if(Operator == '*') return a*b;
        return a/b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> Stack;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*" || tokens[i]=="/"){
                long integer2 = Stack.top();
                Stack.pop();
                long integer1 = Stack.top();
                Stack.pop();
                
                string Operator = tokens[i];
                long ans = find(integer1, integer2 , Operator[0]);
                Stack.push(ans);
            }else 
                Stack.push(stol(tokens[i]));
        }
        return Stack.top();
    }
};
