#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// Define a structure for the expression tree node
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new expression tree node
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct an expression tree from a postfix expression
struct TreeNode* constructExpressionTree(char postfix[]) {
    int stackSize = strlen(postfix);
    struct TreeNode* stack[stackSize];
    int top = -1;

    for (int i = 0; i < stackSize; i++) {
        char symbol = postfix[i];
        struct TreeNode* newNode = createNode(symbol);

        if (!isOperator(symbol)) {
            stack[++top] = newNode;
        } else {
            // Pop two operands from the stack
            struct TreeNode* operand2 = stack[top--];
            struct TreeNode* operand1 = stack[top--];

            // Make the two operands the left and right children of the operator
            newNode->right = operand2;
            newNode->left = operand1;

            // Push the new subtree onto the stack
            stack[++top] = newNode;
        }
    }

    // The final tree will be at the top of the stack
    return stack[top];
}

// Function to print the expression tree in infix form (in-order traversal)
void printInfix(struct TreeNode* root) {
    if (root) {
        printInfix(root->left);
        printf("%c ", root->data);
        printInfix(root->right);
    }
}

int main() {
    char postfix[] = "23*5+";
    struct TreeNode* root = constructExpressionTree(postfix);
    
    printf("Infix expression: ");
    printInfix(root);
    
    return 0;
}