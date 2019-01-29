class Solution {
public:
	string pushDominoes(string dominoes) {
		int length = dominoes.length();
		string ret;
		int start = 0;
		for (int i = 0; i <= length; ++i) {	//".L.R."
			if (dominoes[i] == \u0027L\u0027) {
				for (int j = start; j <= i; ++j)
					ret.push_back(\u0027L\u0027);
				start = i + 1;
			}
			else if (dominoes[i] == \u0027R\u0027) {
				ret.append(i - start, \u0027.\u0027);
				int j = i + 1;
				while (j <= length) {
					if (j == length) {
						ret.append(j - i, \u0027R\u0027);
						i = j + 1;
						break;
					}
					else if (dominoes[j] == \u0027L\u0027) {
						int l = j - i;
						if (l % 2 == 0) {
							ret.append(l / 2, \u0027R\u0027);
							ret.push_back(\u0027.\u0027);
							ret.append(l / 2, \u0027L\u0027);
						}
						else {
							ret.append(l / 2 + 1, \u0027R\u0027);
							ret.append(l / 2 + 1, \u0027L\u0027);
						}
						i = j;
						start = j + 1;
						break;
					}
					else if (dominoes[j] == \u0027R\u0027)
					{
						ret.append(j - i, \u0027R\u0027);
						i = j - 1;
						start = j;
						break;
					}
					++j;
				}
			}
			if (i == length)
				ret.append(i - start, \u0027.\u0027);
		}
		return ret;
	}
};
