#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum node in a BST
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with 2 children: replace with inorder successor
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Search in BST
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value)
        return root;

    if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// Find max element in BST
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        // ===== RECONSTRUCTED (not visible in the PDF: page cut off here) =====
        printf("%d ", root->data);
    }
}

// ===== RECONSTRUCTED: the start of main() (menu + cases 1-3) is missing from
// ===== the PDF. Rebuilt from the menu text and prompts in the output screenshots.
int main() {
    struct Node* root = NULL;
    int choice, value, n, i;

    do {
        printf("\n------ Binary Search Tree Menu ------\n");
        printf("1. Insert N integers\n");
        printf("2. Insert one integer\n");
        printf("3. Delete a node\n");
        printf("4. Search a node\n");
        printf("5. Find Minimum\n");
        printf("6. Find Maximum\n");
        printf("7. Inorder Traversal\n");
        printf("8. Preorder Traversal\n");
        printf("9. Postorder Traversal\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of integers: ");
                scanf("%d", &n);
                printf("Enter %d integers: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    root = insert(root, value);
                }
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            // ===== END OF RECONSTRUCTED PART =====

            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    printf("Value %d found in BST.\n", value);
                else
                    printf("Value %d not found.\n", value);
                break;

            case 5:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Minimum value: %d\n", findMin(root)->data);
                break;

            case 6:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Maximum value: %d\n", findMax(root)->data);
                break;

            case 7:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 8:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 9:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 10:
                printf("Exiting...\n");
                // ===== RECONSTRUCTED (end of file is missing from the PDF) =====
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 10);

    return 0;
}
