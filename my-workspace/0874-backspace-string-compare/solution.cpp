/*#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {

            while (i >= 0) {
                if (s[i] == '#') { skipS++; i--; }
                else if (skipS > 0) { skipS--; i--; }
                else break;
            }

            while (j >= 0) {
                if (t[j] == '#') { skipT++; j--; }
                else if (skipT > 0) { skipT--; j--; }
                else break;
            }

            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            }
            else if (i >= 0 || j >= 0) return false;

            i--;
            j--;
        }
        return true;
    }
};*/
#include <stack>
using namespace std;

class Solution {
public:
    stack<char> build(string str) {
        stack<char> st;
        for (char c : str) {
            if (c != '#') st.push(c);
            else if (!st.empty()) st.pop();
        }
        return st;
    }

    bool backspaceCompare(string s, string t) {
        stack<char> st1 = build(s);
        stack<char> st2 = build(t);

        if (st1.size() != st2.size()) return false;

        while (!st1.empty()) {
            if (st1.top() != st2.top()) return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};


