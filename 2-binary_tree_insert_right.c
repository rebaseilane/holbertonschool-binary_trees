#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as right-child
 * @parent: Pointer to parent node
 * @value: Value to store
 *
 * Description: If parent already has a right child, it becomes
 *              the right child of the new node.
 *
 * Return: Pointer to new node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *old_right;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent->right != NULL)
	{
		old_right = parent->right;
		new_node->right = old_right;
		old_right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
