#include <iostream>
#include <queue>

using namespace std;

// 处理操作符优先级应该用栈，但是如果我们将乘除的结果先算出来，那么就可以用队列来完成

queue<int> num_q; // 存加减法的操作数和乘除法的结果
queue<char> op_q; // 存加减法操作符

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        s.push_back('+'); // 因为每次都是将 +，- 操作数入队列，所以在表达式后追加一个 + ，来让其之前的操作数入队
        
        for (int i = 1; i < s.size(); i += 2) { // 遍历表达式中的每一个操作符
            int num = s[i-1] - '0'; // 初始化表达式前的操作数
            while (i < s.size() && (s[i] == 'x' || s[i] == '/')) { // 如果操作符是 *, /  ,就求出连续乘除的结果
                s[i] == 'x' ? num *= (s[i+1] - '0') : num /= (s[i+1] - '0');
                i += 2;
            }
            num_q.push(num);
            op_q.push(s[i]);
        }
        num_q.push(0);    // 因为追加了一个 + 所以在 num_q 队列尾部追加一个 0 和 + 配对
        
        int ans = num_q.front();
        num_q.pop();
        while (!op_q.empty()) {
            char op = op_q.front();
            op_q.pop();
            op == '+' ? ans += num_q.front() : ans -= num_q.front();
            num_q.pop();
        }
        cout << (ans == 24 ? "Yes" : "No") << endl;
    }
    return 0;
}