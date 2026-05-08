#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26

struct TrieNode {
    struct TrieNode *children[ALPHABET];
    int isEnd;
};

struct TrieNode *newNode() {
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEnd = 0;
    for (int i = 0; i < ALPHABET; i++)
        node->children[i] = NULL;
    return node;
}

void insert(struct TrieNode *root, char *key) {
    struct TrieNode *p = root;
    for (int i = 0; key[i]; i++) {
        int index = key[i] - 'a';
        if (!p->children[index])
            p->children[index] = newNode();
        p = p->children[index];
    }
    p->isEnd = 1;
}

int search(struct TrieNode *root, char *key) {
    struct TrieNode *p = root;
    for (int i = 0; key[i]; i++) {
        int index = key[i] - 'a';
        if (!p->children[index])
            return 0;
        p = p->children[index];
    }
    return p->isEnd;
}

int main() {
    struct TrieNode *root = newNode();

    insert(root, "cat");
    insert(root, "car");

    printf("car var mi? %d\n", search(root, "car"));
    printf("cap var mi? %d\n", search(root, "cap"));

    return 0;
}
