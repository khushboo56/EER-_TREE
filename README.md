# EER-_TREE

## Team Members

Khushboo Gupta - 2021CSB1105
Nandini Mundhra - 2021CSB1113
Niroopma Verma - 2021CSB1115


## Teaching Assistant
Vinay Kumar

## CS201 Project : EERTREE implementation and Applications

## Time Complexities:

EERTREE implementation: O(n), n is the length of the string
Longest Palindromic Substring: O(n)
Manacher's Algorithm: O(n)
KMP Algorithm: O(n)
Rich String: O(n)

## How to run the program:
	The program can be compiled and run directly in the terminal using gcc compliler.

## Expected inputs and outputs of different codes:

(1) EER_TREE.cpp
INPUT: The string to be stored in the eertree.
OUTPUT: It stores the string in the eertree and displays the palindromic substrings present in the input string.
Example:(Input) abcbdbcb
        (Output)	 a
			 b
			 c
			 bcb
			 d
			 bdb
			 cbdbc
			 bcbdbcb

(2)Longest possible palindrome.cpp
INPUT: String
OUTPUT: To find the longest palindromic substring present and the number of distinct palindromes present in the given string using EERTREE.
Example: (Input) xyzzyxzzx
         (Output) Number of distinct palindromes = 7
			  Longest possible palindrome = xyzzyx

(3) Manachers Algorithm
INPUT: String
OUTPUT: To find the longest palindromic substring present int the given string.
Example: (Input) abcdedcbfe
	    (Output) Longest palindrome : bcdedcb 

(4) The Knuth-Morris-Pratt (KMP)Algorithm
INPUT: String and pattern (or substring) (to be searched)
OUTPUT: It returns the index at which the given pattern(or substring) is present in the string.
Example: (Input) xyxzyxxyz
			 xyz
	    (Output) Found pattern at index 6
