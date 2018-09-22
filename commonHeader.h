#ifndef __COMMONHEADER_H__
#define __COMMONHEADER_H__


#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <ctype.h>
#include <stdio.h>
#include <climits>
#include <cmath>        // std::abs
//#include <map>

using namespace std;


template<typename T>
ostream& operator<<(ostream& os, const vector<T>& that) {
    os << "[";
    for(int i=0; i<that.size(); ++i) {
        if(i==that.size()-1)    os << that[i];
        else                    os << that[i] << ", ";
    }
    os << "]";

    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& that) {
    for(auto& ele : that) {
        os << ele << endl;
    }
    return os;    
}

template<typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& that) {
    os << "[";
    for(int i=0; i<that.size(); ++i) {
        if(i==that.size()-1)    os << that[i];
        else                    os << that[i] << ", ";
    }
    os << "]";

    return os;
}

template<typename T>
ostream& operator<<(ostream& os, const set<T>& that) {
    os << "[";
    for(auto itor = that.begin(); itor != that.end(); ++itor) {
        os << (*itor) << ", ";
    }
    os << "]";

    return os;
}


//template<typename T>
//ostream& operator<<(ostrearm& os, const pair<T,T>& that) {
//    os << "(" << that.first << ", " << that.second << ")" << endl;
//
//    return os;
//}




template<typename T>
void print_vec(const vector<T>& vec) {
    for(const auto ele : vec) {
        cout << ele << " ";
    }
    cout << endl;
}

template<typename T>
void print_vecvec(const vector<vector<T>>& grid) {
    for(const auto ele : grid) {
        print_vec(ele);
    }

}



//f(x,y) = x+y   f(1,2)
int add(int a, int b) {
    return a+b;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};




struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
};



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ostream& operator<<(ostream& os, ListNode* head) {
    ListNode* temp = head;

    while(temp->next != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }

    cout << temp->val << endl;
    return os;
}


ListNode* convert_from_vec(const vector<int>& nums) {
    if(nums.empty())    return NULL;

    ListNode* head = new ListNode(nums[0]);
    ListNode* curr = head;

    for(int i=1; i<nums.size(); ++i) {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }

    return head;
}









void print() {
	std::cout << 123 << std::endl;
}

#endif
