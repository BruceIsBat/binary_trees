#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is perfect, 0 if not or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = 0;
	int node_count = 0;

	if (tree == NULL)
		return (0);

	while (tree)
	{
		depth++;
		tree = tree->left;
	}

	node_count = (1 << depth) - 1;

	return binary_tree_is_perfect_recursive(tree, depth, &node_count);
}

/**
 * binary_tree_is_perfect_recursive - Recursively checks if a binary tree is perfect.
 * @tree: Pointer to the current node being checked.
 * @depth: The depth of the tree.
 * @node_count: The expected number of nodes for a perfect tree.
 * Return: 1 if the tree is perfect, 0 if not.
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, int depth, int *node_count)
{
	if (tree == NULL)
		return (*node_count == 0);

	if (tree->left == NULL && tree->right == NULL)
		return (*node_count == 1);

	if (*node_count <= 0)
		return (0);

	if (tree->left && tree->right)
	{
		int left_depth = depth - 1;
		int left_nodes = (1 << left_depth) - 1;

		(*node_count) -= (left_nodes + 1);

		return (binary_tree_is_perfect_recursive(tree->left, left_depth, node_count) &&
				binary_tree_is_perfect_recursive(tree->right, left_depth, node_count));
	}

	return (0);
}
