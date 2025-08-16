#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 10   // letters 'a' to 'j'

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

// create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    node->isEndOfWord = 0;
    return node;
}

// insert word, return 0 if ok, -1 if BAD
int insertWord(TrieNode* root, char* word) {
    TrieNode* curr = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
        int idx = word[i] - 'a';

        if (curr->children[idx] == NULL)
            curr->children[idx] = createNode();

        curr = curr->children[idx];

        // Case 1: Some earlier word is prefix of this word
        if (curr->isEndOfWord && i != len - 1)
            return -1;
    }

    // Case 2: This word is prefix of some earlier word
    if (curr->isEndOfWord) return -1;
    curr->isEndOfWord = 1;

    for (int j = 0; j < ALPHABET_SIZE; j++) {
        if (curr->children[j] != NULL)
            return -1;
    }

    return 0;  // all good
}

int main() {
    int n;
    scanf("%d", &n);

    TrieNode* root = createNode();
    char word[100005];

    for (int i = 0; i < n; i++) {
        scanf("%s", word);

        if (insertWord(root, word) == -1) {
            printf("BAD SET\n%s\n", word);
            return 0;
        }
    }

    printf("GOOD SET\n");
    return 0;
}
