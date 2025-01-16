#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    int countWords(TrieNode* node) {
        if (node == nullptr) return 0;

        int count = node->isEndOfWord ? 1 : 0;
        for (auto& child : node->children) {
            count += countWords(child.second);
        }
        return count;
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return true;
    }

    int countWordsStartingWith(const std::string& prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            if (node->children.find(ch) == node->children.end()) {
                return 0;
            }
            node = node->children[ch];
        }
        return countWords(node);
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("bat");

    std::cout << "CountWordsStartingWith(\"ap\"): " << trie.countWordsStartingWith("ap") << std::endl; 

    return 0;
}