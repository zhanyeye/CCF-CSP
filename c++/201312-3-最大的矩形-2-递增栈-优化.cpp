#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int heights[10005];
stack<int> st;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    heights[n] = -1; //追加一个小于任何数的 min辅助
    st.push(n); //栈中压入 min辅助 的索引
    int res = 0;
    for (int i = 0; i <= n; i++) {
        while (heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            res = max(res, h * (i - (st.top() != n ? st.top() : -1) - 1));
        }
        st.push(i);
    }
    cout << res << endl;

    return 0;
}