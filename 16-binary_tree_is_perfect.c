#include "binary_trees.h"

/**
 * check_perfect - Checks recursively if a binary tree is perfect
 * @tree: Pointer to the current node
 * @depth: Expected depth of all leaf nodes
 * @level: Current level in the tree
 *
 * Return: 1 if subtree is perfect, 0 otherwise
 */
static int check_perfect(const binary_tree_t *tree, size_t depth,
			 size_t level);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to root node of the tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);

	depth = binary_tree_height(tree);

	return (check_perfect(tree, depth, 0));
}

/**
 * check_perfect - Helper function to validate perfect tree
 * @tree: Pointer to current node being checked
 * @depth: Expected depth of all leaf nodes
 * @level: Current level of traversal
 *
 * Return: 1 if subtree is perfect, 0 otherwise
 */
static int check_perfect(const binary_tree_t *tree, size_t depth,
			 size_t level)
{
	if (tree == NULL)
		return (1);

	if (!tree->left && !tree->right)
		return (depth == level);

	if (!tree->left || !tree->right)
		return (0);

	return (check_perfect(tree->left, depth, level + 1) &&
		check_perfect(tree->right, depth, level + 1));
}
