#include "binary_trees.h"

/**
 * heap_insert - inserts a value into a max binary heap
 * @root: root node of heap
 * @value: value to store in node
 * Return: new inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node, *tar;
    int max = 0, temp = 0;

    node = malloc(sizeof(heap_t));
    if (node == NULL)
        return (NULL);
    node->n = value;
    node->left = NULL;
    node->right = NULL;
    if (*root == NULL)
    {
	*root = node;
	return (node);
    }
    max = maxDepth(*root);
    tar = find_node(*root, 0, max - 1);
    if (tar == NULL)
    {
        tar = *root;
        while (tar->left)
	    tar = tar->left;
    }
    node->parent = tar;
    if (tar->left == NULL)
        tar->left = node;
    else
        tar->right = node;
    while(node->parent)
    {
        if (node->n > node->parent->n)
	{
	    temp = node->n;
	    node->n = node->parent->n;
	    node->parent->n = temp;
	    node = node->parent;
	}
        else
	    break;
    }
    return (node);
}

int maxDepth(heap_t *node)
{
    int l, r;
  
    if (node == NULL)
        return (0);
    l = maxDepth(node->left);
    r = maxDepth(node->right);
    if (l > r)
        return (l + 1);
    else
        return (r + 1);
}

heap_t *find_node(heap_t *root, int depth, int max)
{
    heap_t *l, *r;

    if (depth == max)
        return (NULL);
    if (root->left != NULL && root->right == NULL)
        return (root);
    if (root->left == NULL && depth != max)
        return (root);
    
    l = find_node(root->left, depth + 1, max);
    r = find_node(root->right, depth + 1, max);
    if (l != NULL)
        return (l);
    else
        return (r);
}
