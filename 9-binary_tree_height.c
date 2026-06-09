#include "binary_trees.h"

/**
 * binary_tree_height - Measures height of a binary tree
 * @tree: Pointer to root node
 *
 * Return: height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}
