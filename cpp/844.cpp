class Solution {
public:
	bool backspaceCompare(string S, string T) {
		vector<char> s, t;
		for (int i = 0; i < S.length(); ++i) {
			if (S[i] != \u0027#\u0027)
				s.push_back(S[i]);
			else
				if(!s.empty())
					s.pop_back();
		}
		for (int j = 0; j < T.length(); ++j) {
			if (T[j] != \u0027#\u0027)
				t.push_back(T[j]);
			else
				if (!t.empty())
					t.pop_back();
		}
		return s == t;
	}
};
