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
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");

    std::cout << std::boolalpha;
    std::cout << "Search(\"app\"): " << trie.search("app") << std::endl; // true
    std::cout << "Search(\"bat\"): " << trie.search("bat") << std::endl; // false
    std::cout << "StartsWith(\"ap\"): " << trie.startsWith("ap") << std::endl; // true
    std::cout << "StartsWith(\"bat\"): " << trie.startsWith("bat") << std::endl; // false

    return 0;
}