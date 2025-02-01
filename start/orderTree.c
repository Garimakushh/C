#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int data) {
  if (!root) {
    return createNode(data);
  }
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

void inOrder(Node *root) {
  if (root) {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

void preOrder(Node *root) {
  if (root) {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(Node *root) {
  if (root) {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  int n;
  printf("Number of elements :");
  scanf("%d", &n);


  int keys[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &keys[i]);
  }

  Node *root = NULL;
  for (int i = 0; i < n; i++) {
    root = insert(root, keys[i]);
  }

  printf("Inorder: ");
  inOrder(root);

  printf("\nPreorder: ");
  preOrder(root);

  printf("\nPostorder: ");
  postOrder(root);
}