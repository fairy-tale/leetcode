class Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		string tmp = "";
		path += '/';
		for (auto c : path) {
			if (c == '/') {
				if (tmp != "") {
					if (tmp == "..") {
						if (!st.empty()) st.pop();
					}
					else if (tmp != ".") {
						st.push(tmp);
					}
				}
				tmp = "";
			}
			else {
				tmp += c;
			}
		}
		string res = "";
		while (!st.empty()) {
			res = '/' + st.top() + res;
			st.pop();
		}
		if (res == "") res += '/';
		return res;
	}
};