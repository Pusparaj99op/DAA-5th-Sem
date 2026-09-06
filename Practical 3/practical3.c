// Aim: implement Huffman Coding
#include <stdio.h>
#include <stdlib.h>

struct Node { char ch; int freq; struct Node *left, *right; };

struct Node* newNode(char ch, int freq) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->ch = ch; temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

void printCodes(struct Node *root, int code[], int top) {
    if (root->left) { code[top] = 0; printCodes(root->left, code, top + 1); }
    if (root->right) { code[top] = 1; printCodes(root->right, code, top + 1); }
    if (!root->left && !root->right) {
        printf("%c : ", root->ch);
        for (int i = 0; i < top; i++) printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    char ch[] = {'A', 'B', 'C', 'D', 'E'};
    int freq[] = {5, 9, 12, 13, 16};
    int n = sizeof(ch) / sizeof(ch[0]);
    int code[10];

    struct Node *nodes[10], *left, *right, *newnode, *root;
    for (int i = 0; i < n; i++) nodes[i] = newNode(ch[i], freq[i]);

    for (int i = n; i > 1; i--) {
        int min1 = 0;
        for (int j = 1; j < i; j++)
            if (nodes[j]->freq < nodes[min1]->freq) min1 = j;
        left = nodes[min1];
        nodes[min1] = nodes[i - 1];

        int min2 = 0;
        for (int j = 1; j < i - 1; j++)
            if (nodes[j]->freq < nodes[min2]->freq) min2 = j;
        right = nodes[min2];

        newnode = newNode('$', left->freq + right->freq);
        newnode->left = left; newnode->right = right;
        nodes[min2] = newnode;
    }
    root = nodes[0];

    printf("Characters and frequencies: A=5 B=9 C=12 D=13 E=16\n\n");
    printf("Huffman Codes:\n");
    printCodes(root, code, 0);

    return 0;
}
