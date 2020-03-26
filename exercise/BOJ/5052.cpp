#include<bits/stdc++.h>
using namespace std;
const int GO_MAX = 10;
int N;
struct Trie {
	Trie* go[GO_MAX];
	bool output, goExist;

	Trie() {
		fill(go, go + GO_MAX, nullptr);
		output = goExist = false;
	}
	~Trie() {
		for (int i = 0; i < GO_MAX; i++)
			if (go[i]) delete go[i];
	}
	bool insert(const char* key) {
		if (*key == '\0') {
			output = true;
			return !goExist;
		}
		int next = *key - '0';
		if (!go[next]) go[next] = new Trie;
		goExist = true;
		return !output && go[next]->insert(key + 1);
	}
};
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		cin >> N;
		Trie* root = new Trie;
		bool result = true;
		for (int i = 1; i <= N; i++) {
			char tel[11];
			cin >> tel;
			if (result && !root->insert(tel)) result = false;
		}
		puts(result ? "YES" : "NO");
		delete root;
	}
	return 0;
}