// Group 25

// Finding longest possible palindrome and number of distinct palindrome in a given input string

// Khushboo Gupta 2021CSB1105
// Nandini Mundhra 2021csb1113
// Niroopma Verma 2021csb1115
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

//defining a node with corresponding attributes of an EER Tree , that is actually a directed graph
struct Node {
	int start;  //it store start  index of current node
		int end;//it store end  index of current node

	int length;// stores length of substring
	int suffix;// stores the Maximum Palindromic Suffix Node for the current node
	int labeled[26]; // stores labeled node for all characters a-z
};



// stores Node information for constant time access
Node eertree[MAX];

// two special dummy Nodes as explained above
Node root1;
Node root2;

// Keeps track the current Node while insertion
int current;
int ptr;
string s;
void insert(int idx)
{
	// STEP 1//

	/* search for Node X such that s[idx] X S[idx]
	is maximum palindrome ending at position*/
	int tmp = current;
	while (1>0) {
		int curLength = eertree[tmp].length;
		int p = idx - curLength;
		char c1 = s[idx];
		char c2 = s[idx - curLength - 1];
		if ( p >= 1 ){
			if(c1==c2){
				break;
			}
		}
		tmp = eertree[tmp].suffix;
	}

	/* Now we have found X
	 and we have to check if s[idx] X s[idx] already exists or not*/
	int k = eertree[tmp].labeled[s[idx] - 'a'];
	if ( k) {
		// s[idx] X s[idx] already exists in the tree
		current = k;
		return;
	}

	// creating new Node
	ptr++;

	// making new Node as child of X with
	// weight as s[idx]
	eertree[tmp].labeled[s[idx] - 'a'] = ptr;

	// calculating length of new Node
	eertree[ptr].length = eertree[tmp].length + 2;

	// updating end point for new Node
	eertree[ptr].end = idx;

	// updating the start for new Node
	eertree[ptr].start = idx - eertree[ptr].length + 1;

	// STEP 2//

	/* Setting the suffix edge for the newly created
	Node tree[ptr]. Finding some String Y such that
	s[idx] + Y + s[idx] is longest possible for newly created nod*/

	tmp = eertree[tmp].suffix;

	// making new Node as current Node
	current= ptr;
	int l = eertree[current].length;
	if (l != 1) {
	}
	else{
		eertree[current].suffix = 2;
		return;
	}
	while (1>0) {
		int curlen = eertree[tmp].length;
		int t = idx - curlen;
		int cs1 = s[idx];
		int cs2 = s[idx - curlen- 1];
		if (t >= 1 &&  cs1 == cs2 ){
			if(cs1 == cs2){
				break;
			}
		}
		tmp = eertree[tmp].suffix;
	}
	eertree[current].suffix
		= eertree[tmp].labeled[s[idx] - 'a'];
}

// driver program
int main()
{
	root1.length = -1;
	root1.suffix = 1;
	root2.length = 0;
	root2.suffix = 1;

	eertree[1] = root1;
	eertree[2] = root2;
	ptr = 2;
	current = 1;
	// given string
	cout<<"Enter a string : ";
	cin>>s;
	int l = s.length();

	for (int i = 0; i < l; i++)
		insert(i);
	cout<<"Number of distinct palindromes = "<<ptr-2<<endl;
	int maxx = 0;
	string result = "";

	for (int i = 3; i <= ptr; i++) {
		string res = "";
		for (int j = eertree[i].start; j <= eertree[i].end; j++)
			res += s[j];
		if (res.size() > maxx) {
			maxx = res.size();
			result = res;
		}
	}
	cout <<"Longest possible palindrome ="<<result;

	return 0;
}

