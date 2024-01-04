#include<bits/stdc++.h>
using namespace std;

class Trie
{
public:
	///Number of the Possible Character in String
	const static int N = 26;
	const static char baseChar = 'a';
	struct trieNode
	{
		int freq;
		bool isEnd;
		int next[N];
		trieNode() {
			freq = 0;
			isEnd = false;
			for (int i = 0; i < N; i++) {
				next[i] = -1;
			}
		}
	};

	///the implementation is using vector instead of pointer

	vector<trieNode>tree;

	///Base  Constructor
	Trie() {
		tree.push_back(trieNode());
	}

	///insert operation

	void insert(string &s) {
		///start from root
		int par = 0;
		tree[par].freq++;
		for (char ch : s) {
			if (tree[par].next[ch - baseChar] == -1) {
				tree.push_back(trieNode());
				tree[par].next[ch - baseChar] = tree.size() - 1;
			}
			par = tree[par].next[ch - baseChar];
			tree[par].freq++;
		}
		tree[par].isEnd = true;
	}

	///check no of appearance as prefix
	int checkPrefix(string &s) {
		int par = 0;
		for (char ch : s) {
			if (tree[par].next[ch - baseChar] == -1)
				return false;
			par = tree[par].next[ch - baseChar];
		}
		return tree[par].freq;
	}

	///check string existance
	bool checkString(string &s) {
		int par = 0;
		for (char ch : s) {
			if (tree[par].next[ch - baseChar] == -1)
				return false;
			par = tree[par].next[ch - baseChar];
		}
		return tree[par].isEnd;
	}
};

int main()
{
	Trie trie = Trie();
	int T; cin >> T;
	while (T--) {
		///1 for insert 2 for check prefix 3 for check string
		int x; cin >> x;
		if (x == 1) {
			cout << "insert a string\n";
			string inp; cin >> inp;
			trie.insert(inp);
		}
		if (x == 2) {
			cout << "input a string to check existance as prefix:\n";
			string inp; cin >> inp;
			cout << trie.checkPrefix(inp) << endl;
		}
		if (x == 3) {
			cout << "input a string to check existance as string:\n";
			string inp; cin >> inp;
			cout << trie.checkString(inp) << endl;
		}
	}
	return 0;
}