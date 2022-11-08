class Solution {
public:
    string decodeString(string s)
    {
        string ans;
        for (size_t i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                int j = i + 1;
                while (isdigit(s[j])) {
                    j++;
                }

                // num times
                string numStr = s.substr(i, j - i);
                int num = stoi(numStr, nullptr);
                i = j;

                // match [
                i++;
                int start = i;
                // find match ]
                int stack = 1;
                int end = start;
                for (int k = start; k < s.length(); k++) {
                    if (s[k] == '[') {
                        stack++;
                    }
                    if (s[k] == ']') {
                        stack--;
                    }
                    if (stack == 0) {
                        end = k;
                        break;
                    }
                }
                string subs = s.substr(start, end - start);
                // j == ']' now

                auto reSubs = decodeString(subs);
                for (int m = 0; m < num; m++) {
                    ans.append(reSubs);
                }
                i = end;

            } else {
                if (isalpha(s[i])) {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
