#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

static char **create_array(int height, int width);
static void free_array(char **s, int height);
static void _print(binary_tree_t *tree, int level, int offset, char **s);

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to root node
 */
void binary_tree_print(const binary_tree_t *tree)
{
	int height = 10;
	char **s;
	int i;

	if (!tree)
		return;

	s = create_array(height, 255);
	_print((binary_tree_t *)tree, 0, 0, s);

	for (i = 0; i < height; i++)
		printf("%s\n", s[i]);

	free_array(s, height);
}

/**
 * _print - Internal recursive print
 */
static void _print(binary_tree_t *tree, int level, int offset, char **s)
{
	char b[6];
	int i;

	if (tree == NULL)
		return;

	sprintf(b, "(%03d)", tree->n);

	for (i = 0; b[i]; i++)
		s[level][offset + i] = b[i];

	if (tree->left)
		_print(tree->left, level + 1, offset - 6, s);
	if (tree->right)
		_print(tree->right, level + 1, offset + 6, s);
}

/**
 * create_array - Creates a 2D array for printing
 */
static char **create_array(int height, int width)
{
	int i;
	char **a;

	a = malloc(sizeof(char *) * height);
	if (!a)
		return (NULL);

	for (i = 0; i < height; i++)
{
	int j;

	a[i] = malloc(width);
	if (!a[i])
		return (NULL);

	for (j = 0; j < width; j++)
		a[i][j] = ' ';
	a[i][width - 1] = '\0';
}

	return (a);
}

/**
 * free_array - Frees 2D array
 */
static void free_array(char **s, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(s[i]);
	free(s);
}