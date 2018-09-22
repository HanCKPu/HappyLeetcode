

#include "../../commonHeader.h"

//Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
//Note: The input string may contain letters other than the parentheses ( and ).
//Input: "()())()"
//Output: ["()()()", "(())()"]
//Example 2:
//
//Input: "(a)())()"
//Output: ["(a)()()", "(a())()"]
//Example 3:
//
//Input: ")("
//Output: [""]
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
       	if(s.empty())	return vector<string>{""}; 				//empty string is a valid case

       	int l = 0, r = 0;
       	for(char c : s) {
       		if(c == '(')	l++;
       		else if(c == ')'){
       			if(l == 0)	r++;
       			else 		l--;
       		}
       	}

       	vector<string> ans;
       	dfs(ans, l, r, 0, s);

       	return ans;
    }

    void dfs(vector<string>& ans, int l, int r, int index, const string& s) {
    	if(l == 0 and r == 0) {
    		if(isValid(s)) 	ans.push_back(s);
    		return;
    	}

    	for(int i = index; i < s.size(); ++i) {
    		if(i != index and s[i] == s[i-1])	continue;
    		if(s[i] != '(' and s[i] != ')')		continue;

    		//if(s[i] == '(' or s[i] == ')') {
    			string next = s;
    			next.erase(i, 1);
    			if(l > 0 and s[i] == '(')		dfs(ans, l-1, r, i, next); 	//it's i not i+1
    			else if(r > 0 and s[i] == ')')	dfs(ans, l, r-1, i, next); 	//it's i not i+1
    		//}
    	}
    }


   	bool isValid(const string& that) {
   		int count = 0;
   		for(char c : that) {
   			if(c == '(')	count++;
   			if(c == ')')	count--;
   			if(count < 0)	return false;
   		}
   		return true;
   	}
};


int main() {
	Solution facebook;

	string s = "";
	auto ans = facebook.removeInvalidParentheses(s);
	cout << ans.size() << endl;

	return 0;
}

