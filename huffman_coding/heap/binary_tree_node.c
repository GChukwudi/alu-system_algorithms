#include <stdlib.h>
#include "heap.h"

/**
 * heap_create - Creates a Heap data structure
 * @data_cmp: Pointer to a comparison function
 *
 * Return: Pointer to the created heap_t structure, or NULL if it fails
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
    heap_t *heap;

    if (!data_cmp)
        return (NULL);

    heap = malloc(sizeof(heap_t));
    if (!heap)
        return (NULL);

    heap->size = 0;
    heap->data_cmp = data_cmp;
    heap->root = NULL;

    return (heap);
}

/**
 * binary_tree_node - Creates a generic Binary Tree node
 * @parent: Pointer to the parent node
 * @data: Data to store in the node
 *
 * Return: Pointer to the created node or NULL if it fails
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
    binary_tree_node_t *node = malloc(sizeof(binary_tree_node_t));
    if (!node)
        return (NULL);

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = parent;

    return (node);
}
