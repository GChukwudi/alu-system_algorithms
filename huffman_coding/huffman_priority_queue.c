#include "huffman.h"

/**
 * huffman_priority_queue - Creates a priority queue for the Huffman coding
 *
 * @data: An array of characters
 * @freq: An array of the associated frequencies
 * @size: The size of the arrays
 *
 * Return: A pointer to the created priority queue
 */

heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
    heap_t *priority_queue = heap_create(1, NULL);

    if (!priority_queue)
        return (NULL);

    for (size_t i = 0; i < size; i++)
    {
        binary_tree_node_t *node = binary_tree_node(NULL, symbol_create(data[i], freq[i]));

        if (!node)
        {
            heap_delete(priority_queue, NULL);
            return (NULL);
        }

        if (!heap_insert(priority_queue, node))
        {
            heap_delete(priority_queue, NULL);
            return (NULL);
        }
    }

    return (priority_queue);
}
