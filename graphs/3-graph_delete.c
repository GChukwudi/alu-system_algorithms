#include "graphs.h"
#include <stdlib.h>
#include <string.h>

/**
 * delete_edge_from_vertex - Deletes an edge from a vertex's edge list
 * @vertex: The vertex to delete the edge from
 * @dest: The destination vertex of the edge to delete
 */
static void delete_edge_from_vertex(vertex_t *vertex, vertex_t *dest)
{
	edge_t *current, *prev = NULL;

	current = vertex->edges;
	while (current)
	{
		if (current->dest == dest)
		{
			if (prev)
				prev->next = current->next;
			else
				vertex->edges = current->next;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
}