/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty()) return 0;

		std::array<int, 256> CharMap(256, -1);
		int MaxLength = 1;

		for (int index = 0; index < s.length(); ++index)
		{
			if (CharMap[s[index]] == -1)
			{
				CharMap[s[index]] = index;
			}
			else
			{
				MaxLength = std::max(index - CharMap[s[index]], MaxLength);
				CharMap[s[index]] = index;
			}
		}
		return MaxLength;
	}
};