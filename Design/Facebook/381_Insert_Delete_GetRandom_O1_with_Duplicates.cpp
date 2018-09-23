
#include "../../commonHeader.h"



//hashmap + vector
//每次删除元素的时候，swap当前元素和最后一个元素，然后这样的vector delete操作就是O(1)

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        size = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool isExist = m.count(val) == 0 or m[val].empty();
        m[val].insert(size++);
        vec.push_back(val);
        return isExist;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m.count(val) == 0 or m[val].empty())
            return false;

        //index of val to be deleted
        int targetIndex = *m[val].begin();

        if(targetIndex == size-1 or val == vec.back()) {
            m[val].erase(targetIndex);
            vec.pop_back();
        }
        else {
            m[vec.back()].erase(size-1);
            m[vec.back()].insert(targetIndex);
            m[val].erase(targetIndex);
            swap(vec[size-1], vec[targetIndex]);
            vec.pop_back();
        }
        size--;
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % size;
        return vec[idx];
    }

public:
    unordered_map<int, unordered_set<int>> m;
    vector<int> vec;
    int size;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */


int main() {
    RandomizedCollection Google;

    Google.insert(1);
    Google.insert(1);
    Google.insert(2);
    Google.insert(1);
    Google.insert(2);
    Google.insert(2);

    Google.remove(1);
    Google.remove(2);
    Google.remove(2);
    Google.remove(2);
    cout << Google.vec << endl;
    return 0;
}

