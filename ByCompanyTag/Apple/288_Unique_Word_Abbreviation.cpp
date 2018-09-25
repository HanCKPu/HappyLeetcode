

#include "../../commonHeader.h"

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(const auto& word : dictionary) {
        	m[toAbbr(word)].insert(word);
        }
    }
    
    bool isUnique(string word) {
    	string abbr = toAbbr(word);
		return mp[abbr].count(word) == mp[abbr].size(); 
    }

private:
	unordered_map<string, unordered_set<string>> m;

	string toAbbr(string s) {
		int n = s.length();
		if(n <= 2)	return s;

		return s[0] + to_string(s.size() - 2) + s[s.size()-1];
	}
};


int main() {
    //ValidWordAbbr Apple;

	return 0;
}

