#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

struct treeNode {
	struct treeNode *leftPtr;
	char data[SIZE];
	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

TreeNodePtr rootPtr = NULL;

void insertNode(TreeNodePtr *, char[]);
void inOrder(TreeNodePtr);
void preOrder(TreeNodePtr);
void postOrder(TreeNodePtr);
TreeNodePtr search(TreeNodePtr, char[]);
void exitScreen();

int main() {
	int reset = 1, i;
	char input[SIZE];
	TreeNodePtr found;

	system("cls");

	/* Input 10 strings */
	printf("Input 10 strings\n");
	for(i = 0; i < 10; i++) {
		printf("String no-%d: ", i + 1);
		scanf("\n%[^\n]s", &input);
		insertNode(&rootPtr, input);
	}

	/* Traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrder(rootPtr);

	/* Traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrder(rootPtr);

	/* Traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrder(rootPtr);

	do {
		/* Search the tree */
		printf("\n\nSearch: ");
		scanf("\n%[^\n]s", &input);
		found = search(rootPtr, input);
		if(found != NULL) printf("Found: %s", found->data);
		else printf("Not found.");

		printf("\nSearch again? [0:NO, 1:YES] ");
		scanf("%d", &reset);
	} while(reset);

	exitScreen();

	return 0;
}

void insertNode(TreeNodePtr *treePtr, char value[]) {
	 if(*treePtr == NULL) {
		 *treePtr = malloc(sizeof(TreeNode));

		 if(*treePtr != NULL) {
			 strcpy((*treePtr)->data, value);
			 (*treePtr)->leftPtr = NULL;
			 (*treePtr)->rightPtr = NULL;
		 } else {
			 printf("%d not inserted. No memory available.\n", value);
		 }

	 } else {

		 if(strcmpi((*treePtr)->data, value) > 0) { // Descend
			 insertNode(&((*treePtr)->leftPtr), value);
		 } else if(strcmpi((*treePtr)->data, value) < 0) { // Ascend
			 insertNode(&((*treePtr)->rightPtr), value);
		 } else {
			 printf(" (dup)");
		 }

	 }
}

void inOrder(TreeNodePtr treePtr) {
	if(treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%s ", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TreeNodePtr treePtr) {
	if(treePtr != NULL) {
		printf("%s ", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TreeNodePtr  treePtr) {
	if(treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%s ", treePtr->data);
	}
}

TreeNodePtr search(TreeNodePtr treePtr, char value[]) {
    if(treePtr == NULL || strcmpi(treePtr->data, value) == 0) // If root->data is x then the element is found
        return treePtr;
    else if(strcmpi(treePtr->data, value) < 0) // Value is greater, so we will search the right subtree
        return search(treePtr->rightPtr, value);
    else // Value is smaller than the data, so we will search the left subtree
        return search(treePtr->leftPtr, value);
}

void exitScreen() {
    system("cls");
    printf("Thank you!\n");
    printf("-Irfan and Andhika");

    printf("\n\n\n\nPress any key to exit program . . . ");
    getch();
}