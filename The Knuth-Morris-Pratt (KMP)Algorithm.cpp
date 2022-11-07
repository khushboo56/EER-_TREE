// C++ program for implementation of KMP pattern searching  algorithm
#include <bits/stdc++.h>
using namespace std;

class solution {
    public:
    // for Filling  lps[] for given pattern pat[0..M-1]
void computeLPSArray(char *pat, int M, int *lps)
{
    // length of the previous longest prefix suffix
    int a = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[a])
        {
            a++;
            lps[i] = a;
            i++;
        }
        else
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (a != 0)
            {
                a = lps[a - 1];

                // Also, note that we do not increment i here
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char *str, char *s)
{
    int M = strlen(str);
    int N = strlen(s);

    int lps[M]; // create lps[] that will hold the longest prefix suffix  values for pattern

    computeLPSArray(str, M, lps); // Preprocess the pattern (calculate lps[] array)

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j))
    {
        if (str[j] == s[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            cout << "Found pattern at index " << i - j<<endl;
            j = lps[j - 1];
            
        }

        // mismatch after j matches
        else if (i < N && str[j] != s[i])
        {
            // Do not match lps[0..lps[j-1]] characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}

};



// Driver program to test above function
int main()
{
    
    string txt, pat;
    cout<<"Enter the string and pattern : ";
    cin >> txt >> pat;
    
    string str_obj(txt);// convert string to char array Using the address assignment of each other method
   char *v = &str_obj[0];

    char *v1;
    string str_obj1(pat);// convert string to char array Using the address assignment of each other method
    v1 = &str_obj1[0];
    
    solution myobject;
   myobject.KMPSearch(v1, v);
    return 0;
}
