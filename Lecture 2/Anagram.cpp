class Solution {
public:
    bool isAnagram(string s, string t) {
        int free[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        for (int i =; i < t.length(); i++) {
            freq[t[i]]--;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
/*
Time.C == = O(n + n + 26);
O(2 * n);
*/



/*s = "abc";

i = 0;
s[i] = b - a = 98 - 97 = 1;

freq[1]++;
*/