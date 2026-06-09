#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as left-child
 * @parent: Pointer to parent node
 * @value: Value to store in new node
 *
 * Description: If parent already has a left child, the new node
 *              takes its place and the old child becomes the left
 *              child of the new node.
 *
 * Return: Pointer to new node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_left;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	/* If parent already has a left child */
	if (parent->left != NULL)
	{
		old_left = parent->left;
		new_node->left = old_left;
		old_left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}