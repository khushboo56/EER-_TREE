// A c++ program to implement Manacher’s Algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
public:
    int min(int a, int b)
    {
        int res = a;
        if (b < a)
            res = b;
        return res;
    }

    string findLongestPalindromicString(string str)
    {
        int n = str.size();
        if (n == 0)
        {
            return "";
        }

        n = 2 * n + 1;         // count the next position
        int longpalindrome[n]; // array to store longest palindrome length

        int ci = 1; //centerPosition
        int ri = 2;//centerRightPosition
        int right = 0;//currentRightPosition
        int left; //currentLeftPosition
        int mpl = 0, mci = 0;
        int start = -1, end = -1, diff = -1;
        longpalindrome[0] = 0;
        longpalindrome[1] = 1;

        for (right = 2; right < n; right++)
        {
            left = 2 * ci - right; // calculate left position using center and right

            longpalindrome[right] = 0;
            diff = ri - right;

            if (diff > 0)//If currentRightPosition i is within centerRightPosition
            {
                longpalindrome[right] = min(longpalindrome[left], diff);
            }
             //Attempt to expand palindrome centered at currentRightPosition i Here for odd positions, we compare characters and if match then increment LPS Length b ONE If even position, we just increment LPS by ONE without any character comparison
            while (((right + longpalindrome[right]) < n && (right - longpalindrome[right]) > 0) && (((right + longpalindrome[right] + 1) % 2 == 0) | (str[(right + longpalindrome[right] + 1) / 2] == str[(right - longpalindrome[right] - 1) / 2])))
            {
                longpalindrome[right]++;
            }

            if (longpalindrome[right] > mpl) // Track maxLPSLength
            { // max palindrome length
                mpl = longpalindrome[right];
                mci = right;
            }
             //If palindrome centered at currentRightPosition i expand beyond centerRightPosition R, adjust centerPosition C based on expanded palindrome.
            if (right + longpalindrome[right] > ri)
            {
                ci = right;
                ri = right + longpalindrome[right];
            }
        }

        start = (mci - mpl) / 2;
        end = start + mpl - 1;
        string palindrome;

        for (int i = start; i <= end; i++)
        {
            palindrome += str[i];
        }

        return palindrome;
    }
};

int main()
{
    string s, palindrome;
    cout << "Enter String of which longest palindrome you wanted to find:";
    cin >> s;
    solution myobject;
    palindrome = myobject.findLongestPalindromicString(s);
    cout << "Here is your Longest palindrome : " << palindrome << endl;
    return 0;
}