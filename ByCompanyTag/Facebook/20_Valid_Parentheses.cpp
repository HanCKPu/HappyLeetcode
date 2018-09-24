

#include "../../commonHeader.h"

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.

class Solution {
public:
    //s1: stack
    bool isValid(string s) {
        if(s.empty())           return true;
        if(s.size() % 2 != 0)   return false;

        stack<char> sk;
        for(char c : s) {
            if(c == '(')        sk.push(')');
            else if(c == '[')   sk.push(']');
            else if(c == '{')   sk.push('}');
            else {
                if(sk.empty() or sk.top() != c)    return false;
                sk.pop();
            }
        }

        return sk.empty();
    }
};


int main() {
    Solution Facebook;

    string s = "()";
    cout << Facebook.isValid(s) << endl;

	return 0;
}

