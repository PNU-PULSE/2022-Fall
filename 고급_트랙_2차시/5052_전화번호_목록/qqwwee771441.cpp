#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TrieNode {
    TrieNode * children[10];
    bool end_of_word;
    char letter;
    TrieNode() {
        end_of_word = false;
        for (int i = 0; i < 10; i++) {
            children[i] = NULL;
        }
        letter = '\0';
    }
};

struct Trie {
    TrieNode root;
    void Insert (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
        	current->end_of_word = false;
            if (current->children[str.at(i)-'0'] == NULL) {
                current->children[str.at(i)-'0'] = new TrieNode;
                current->children[str.at(i)-'0']->letter = str.at(i);
            }
            current = current->children[str.at(i)-'0'];
        }
        current->end_of_word = true;
    }
    
    TrieNode * Search (string str) {
        TrieNode * current = &root;
        for (size_t i = 0; i < str.size(); i++) {
            if (current->children[str.at(i)-'0']) {
                current = current->children[str.at(i)-'0'];
             } else {
                current = NULL;
                break;
             }
        }
        return current;
    }
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin>>T;
	while(T--) {
		int N;
		cin>>N;
		
		vector<string> str(N);
		for(int i=0; i<N; i++) cin>>str[i];
		sort(str.begin(), str.end());
		
		Trie trie;
		for(int i=0; i<N; i++) trie.Insert(str[i]);
		
		bool consistent = true;
		for(int i=0; i<N; i++)
			if(!trie.Search(str[i])->end_of_word) consistent = false;
		
		if(consistent) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
