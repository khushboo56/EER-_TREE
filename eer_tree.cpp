// Group 25

// EER Tree - Implementation

// Khushboo Gupta 2021CSB1105
// Nandini Mundhra 2021csb1113
// Niroopma Verma 2021csb1115


#include<bits/stdc++.h>
using namespace std; 

//defining a node with corresponding attributes of an EER Tree , that is actually a directed graph

struct Node{
    int start;
	int end; //it store start and end indexes of current node
    int length;      // store length of substring present in the node
    vector<Node *> labeled; //vector of the labeled edges as nodes
    Node *suffix; //nodes representing suffix edges
    
    //now, we are gonna assign starting values to all attributes of a single node of given EER tree
    Node(){
        start = -1;
		end = -1 ;
		length = -1; //assigning initial count of start , end and length as -1
        suffix = NULL; //assigning suffix edge as nullptr
        labeled.assign(26, NULL); //assigning all 26 labeled edges as null pointer 
    }
};
//Defining the main EER tree as a class now.
//Mainly there will be two roots in this EER tree as root 1 and root 2.
class EerTree{
private:
    Node *root1,*root2,*current;

public:
	//Assigning dynamic space and initial values to these roots.
    EerTree(){
        root1 = new Node(); //root 1 has same amount of (dynamic) space as "Node" data type
        root1->suffix = root1; //It will be its own suffix edge
        root1->length = -1;  //we assigned "-1" as its initial length to deal with "odd-lengthed" palindromes

        root2 = new Node();//root 2 has same amount of (dynamic) space as "Node" data type
        root2->suffix = root1; //suffix edge of root2 will be root1
        root2->length = 0;//we assigned "0" as its initial length to deal with "even-lengthed" palindromes
        current = root2; //we are assigning current as root2 
    }

    int insert(string &s, int pos){
        int letter = s[pos] - 'a';
		Node *cur = current;
        while(true){
            // loop is guranteed to break at root1
            int y=pos - 1 - cur->length;
            if (y >= 0 && s[y] == s[pos]){
            	break;
			}     
            cur = cur->suffix;
        }
        
        Node *temp = new Node();
        temp->end = pos;
        temp->length = cur->length + 2;
        int p=temp->length;
        temp->start = pos - p + 1;
        cur->labeled[letter] = temp;
		int templen=temp->length;
        if (templen == 1){
            // if cur is root1
            temp->suffix = root2;
            current = temp;
            return 0;
        }

        // find the suffix node

        while (1>0) {
            cur = cur->suffix;
            int u=pos - 1 - cur->length;
            if(u >= 0 && s[u] == s[pos]) {
                temp->suffix = cur->labeled[letter];
                break;
            }       
        }
        current = temp;

        return 0;
    }

    void print(string &s, Node *node){
        if(node != root1 || node != root2){
        	int st=node->start;
        	int en=node->end;
            for(int i = st; i <= en; i++){
            	cout << s[i];
			}
            cout << '\n';
        }
        for(int i = 0; i < 26; ++i){
            if(node->labeled[i] == NULL){
                continue;
            }else{
            	print(s, node->labeled[i]);
			}
        }
    }

    void printAll(string &s){
    	if(1>0){
    		print(s, root1);
		}
        print(s, root2);
    }

};

int main() {
    cout<<"Enter string: ";
    string s;
    cin>>s;
    EerTree tree;
    for(int i = 0; i < s.size(); ++i)
        tree.insert(s, i);
    tree.printAll(s);
}
