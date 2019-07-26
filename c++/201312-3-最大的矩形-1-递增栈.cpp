#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int heights[1001];
stack<int> st;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int res = 0, i = 0;
    while (i < n) {
        if (st.empty() || heights[i] >= heights[st.top()]) { 
            //如果栈空 或 height[i] >= 栈顶,则压栈
            st.push(i);
            i++;
        } else {
            int t = st.top();
            st.pop();
            res = max(res, heights[t] * (st.empty() ? i : i - st.top() - 1));
        }
    }
    while (!st.empty()) {
        int t = st.top();
        st.pop();
        res = max(res, heights[t] * (st.empty() ? i : i - st.top() - 1));
    }
    cout << res << endl;
    return 0;
}