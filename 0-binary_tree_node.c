#include "binary_trees.h"
#include  <stdlib.h>
/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: Pointer to the parent node
 * @value: the node value
 *
 * Return: newNode
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent != NULL)
	{
		if (value <= parent->n)
		{
			parent->left = new_node;
		}
		else
		{
			parent->right = new_node;
		}
	}
	return (new_node);
}
