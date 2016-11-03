//stack
//string to int, stoi(), int to string to_string()
class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> st;
		for (auto t : tokens) {
			if (t == "+" || t == "-" || t == "*" || t == "/") {
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				switch (t[0]) {
				case '+':{
					st.push(a + b);
					break;
				}
				case '-':{
					st.push(b - a);
					break;
				}
				case '*':{
					st.push(a * b);
					break;
				}
				case '/':
					st.push(b / a);
				}
			}
			else {
				st.push(stoi(t));
			}
		}
		return st.top();
	}
};