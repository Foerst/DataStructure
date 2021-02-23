//
//  main.cpp
//  Stack
//
//  Created by edy on 2021/2/23.
//

#include <iostream>

bool isValid(string s) {
    stack<char> stack;
    map<char,char> map;
    map['('] = ')';
    map['['] = ']';
    map['{'] = '}';
    for(auto c : s){
        if (map.find(c)!=map.end()) {
            stack.push(c);
        } else {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            stack.pop();
            if (map[top]!=c) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
