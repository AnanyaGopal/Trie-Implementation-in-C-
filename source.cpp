#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>

using namespace std;

// Complexities in M * log N (M is the max string length and N 
//							 is the num of keys in the tree. ) 

class TNode {
private:
	TNode * children[26];
	bool isEnd;
public:
	
	// Construct the Trie structure.
	TNode* getNode() {
	
		TNode* pNode = new TNode();
		pNode->isEnd = false;

		for (int i = 0; i < 26; i++) {
			pNode->children[i] = NULL;
		}
		
		return pNode;
	}

	// Insert method
	void insert(TNode* root, string key) {
		TNode* pCrawl = root;
		for (size_t i = 0; i < key.length(); i++) {
		// Treating only lower case letters 
				int t = tolower(key[i]) - 'a';
				if (!pCrawl->children[t]) {
					pCrawl->children[t] = getNode();
				}
			pCrawl = pCrawl->children[t];
		}
		pCrawl->isEnd = true;
	}
	
	// Search in the Trie
	bool search(TNode* root, string key) {
		TNode *pcrawl = root;

		for (int i = 0; i < key.length(); i++) {
			int t = tolower(key[i]) - 'a';
			if (!pcrawl->children[t]) return false;

			pcrawl = pcrawl->children[t];

		}
		
		return (pcrawl != NULL && pcrawl->isEnd);
	}


};

int main(){

	// Start constructing the trie node.
	TNode* root = new TNode();
	root = root->getNode();

	vector<string> testStrings = {"I", "you", "Hey"};

	for(string s: testStrings) root->insert(root,s);
	if (root->search(root, "hey")) cout << "Found";
	return 0;
}
