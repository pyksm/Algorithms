#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n, m, cnt=0;
	string num_s;
	cin >> n >> m >> num_s;
	stack<char> in_stack;
	stack<char> out_stack;
	for (int i = 0; i < num_s.size(); i++) {//스택에 넣는 과정
		while (!in_stack.empty() && cnt < m && num_s[i] > in_stack.top()) {//지우는 과정
			cnt++;
			in_stack.pop();
		}
		in_stack.push(num_s[i]);
	}
	while (cnt < m) {
		cnt++;
		in_stack.pop();
	}
    while (!in_stack.empty()) {
		out_stack.push(in_stack.top());
		in_stack.pop();
    }
	while (!out_stack.empty()) {
		cout << out_stack.top();
		out_stack.pop();
	}
}