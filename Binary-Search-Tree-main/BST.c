#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int number;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

node *createNode(int number)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->number = number;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node *addNode(node *root, int number)
{
    if(root == NULL)
    {
        root = createNode(number);
        return root;
    }
    if(root->number < number)
    {
    	root->right = addNode(root->right, number);
    	return root;
	}
    root->left = addNode(root->left, number);
    return root;
}

node *deleteNode(node *root, int number)
{
	if(root == NULL)
		return NULL;
	if(root->number == number)
	{
		if(root->right == NULL && root->left == NULL)
			return NULL;
		if(root->right != NULL)
		{
			root->number = min(root->right);
			root->right = deleteNode(root->right, min(root->right));
			return root;
		}
		root->number = max(root->left);
		root->left = deleteNode(root->left, max(root->left));
		return root;
	}
	if(root->number < number)
	{
		root->right = deleteNode(root->right, number);
		return root;	
	}
	root->left = deleteNode(root->left, number);
	return root;
}

//Left Node Right
void writeTree_infix(node *root)
{
    node *iter = root;
    if (iter == NULL)
        return;
    writeTree_infix(iter->left);
    printf("%d ", iter->number);
    writeTree_infix(iter->right);    
}

//Node Left Right
void writeTree_prefix(node *root)
{
    node *iter = root;
    if (iter == NULL)
        return;
    printf("%d ", iter->number);
    writeTree_prefix(iter->left);
    writeTree_prefix(iter->right);    
}

//Left Right Node
void writeTree_postfix(node *root)
{
    node *iter = root;
    if (iter == NULL)
        return;
    writeTree_postfix(iter->left);
    writeTree_postfix(iter->right);    
    printf("%d ", iter->number);
}

void writeTree(node *root)
{
	printf("\ninfix(LNR): ");
    writeTree_infix(root);
    printf("\nprefix(NLR): ");
    writeTree_prefix(root);
    printf("\npostfix(LRN): ");
    writeTree_postfix(root);
    printf("\n");
}

int searchNumber(node *root, int number)
{
	node *iter = root;
	if (iter == NULL)
        return -1;
    if(iter->number == number)
		return 1;
	if(searchNumber(iter->left, number) == 1)
		return 1;
	if(searchNumber(iter->right, number) == 1)
		return 1;
	return -1;
}

int max(node *root)
{
	while(root->right != NULL)
		root = root->right;
	return root->number;
}

int min(node *root)
{
	while(root->left!=NULL)
		root = root->left;
	return root->number;
}

int main()
{
    node *root = NULL;
    root = addNode(root, 20);
    root = addNode(root, 30);
    root = addNode(root, 10);
    root = addNode(root, 5);
    root = addNode(root, 15);
    root = addNode(root, 40);
    root = addNode(root, 25);
    /*---------------------------------------------------------------------*/
    writeTree(root);
    /*---------------------------------------------------------------------*/
    printf("\nSearched Value: 40 ");
    searchNumber(root, 40) == 1 ? printf("Available"): printf("Not Available");
    /*---------------------------------------------------------------------*/
    printf("\nMax: %d", max(root));
    printf("\nMin: %d", min(root));
    /*---------------------------------------------------------------------*/
    printf("\nDeleted Value: 5\n");
    root = deleteNode(root, 5);
    /*---------------------------------------------------------------------*/
    writeTree(root);
	
    return 0;
}
