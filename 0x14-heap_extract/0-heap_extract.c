#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a max binary heap
 * @root: root node of the heap
 *
 * Return: value in node return 0 if fail
 */
int heap_extract(heap_t **root)
{
	int value, n;
	size_t level = 0;
	heap_t *node, *del;

	if (root == NULL || *root == NULL)
		return (0);
	node = *root, value = node->n;
	if (node->left == NULL && node->right == NULL)
	{
		*root = NULL;
		free(node);
		return (value);
	}
	binary_tree_preorder(node, &del, binary_tree_height(node), level);
	while (node->left || node->right)
	{
		if (node->right == NULL || node->left->n > node->right->n)
		{
			n = node->n, node->n = node->left->n;
			node->left->n = n;
			node = node->left;
		}
		else if (node->left == NULL || node->right->n > node->left->n)
		{
			n = node->n, node->n = node->right->n;
			node->right->n = n;
			node = node->right;
		}
	}
	node->n = del->n;
	if (del->parent->right)
		del->parent->right = NULL;
	else
		del->parent->left = NULL;
	free(del);
	return (value);
}

/**
 * binary_tree_height - determines height of tree
 * @tree: tree to investigate
 *
 * Return: szie of the tree
 */
int binary_tree_height(const heap_t *tree)
{
	int l = 0;
	int r = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	if (tree->left)
		l = binary_tree_height(tree->left);
	if (tree->right)
		r = binary_tree_height(tree->right);

	if (l >= r)
		return (1 + l);
	return (1 + r);
}

/**
 * binary_tree_preorder - preorder traversal through tree
 * @tree: said tree
 * @node: node in the tree
 * @h: height of tree
 * @level: layer in the tree
 * Return: no return
 */
void binary_tree_preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
	if (tree == NULL)
		return;
	if (h == level)
		*node = tree;
	level++;
	if (tree->left)
		binary_tree_preorder(tree->left, node, h, level);
	if (tree->right)
		binary_tree_preorder(tree->right, node, h, level);
}
