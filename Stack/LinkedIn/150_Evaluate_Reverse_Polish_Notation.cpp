

#include "../../commonHeader.h"

//Input: ["2", "1", "+", "3", "*"]
//Output: 9
//Explanation: ((2 + 1) * 3) = 9

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())  return 0;

        stack<int> s;
        for(const string& token : tokens) {
            if(s.empty() or isDigit(token)) {
                s.push(stoi(token));
                continue;
            }
            
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            int c = token == "+" ? b + a :              //注意先后顺序
                    token == "-" ? b - a :
                    token == "*" ? b * a : b / a;
            s.push(c);
        }

        return s.top();
    }

private:    
    bool isDigit(const string& that) {
        return that != "+" and that != "-" and that != "*" and that != "/";
    }
};


int main() {
	Solution LinkedIn;

    vector<string> tokens {"4", "13", "5", "/", "+"};
    auto ans = LinkedIn.evalRPN(tokens);
    cout << ans << endl;
	return 0;
}

