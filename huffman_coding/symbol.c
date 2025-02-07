#include "huffman.h"

/**
 * symbol_create - Creates a new symbol_t
 *
 * @data: The character
 * @freq: The associated frequency
 *
 * Return: A pointer to the new symbol_t
 */

symbol_t *symbol_create(char data, size_t freq)
{
    symbol_t *new_symbol = malloc(sizeof(symbol_t));

    if (!new_symbol)
        return (NULL);

    new_symbol->data = data;
    new_symbol->freq = freq;

    return (new_symbol);
}
