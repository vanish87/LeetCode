/*
7. Reverse Integer My Submissions Question
Total Accepted : 126215 Total Submissions : 535359 Difficulty : Easy
Reverse digits of an integer.

Example1 : x = 123, return 321
	Example2 : x = -123, return -321
*/
class Solution {
public:
	int reverse(int x) {
		if (x == 0) return 0;
		int Sign = x > 0 ? 1 : -1;
		x = Sign * x;
		int Ret = 0;
		while (x > 0)
		{
			Ret *= 10;
			Ret += x % 10;
			x /= 10;
		}

		return Ret * Sign;
	}
};