#include "graphs.h"

/**
 * graph_add_vertex - Adds a vertex to an existing graph
 * @graph: A pointer to the graph to add the vertex to
 * @str: The string to store in the new vertex
 *
 * Return: A pointer to the created vertex, or NULL on failure
 */

vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex = malloc(sizeof(vertex_t));
	vertex_t *last = graph->vertices;

	if (!vertex)
		return (NULL);

	vertex->index = graph->nb_vertices;
	vertex->content = strdup(str);
	vertex->nb_edges = 0;
	vertex->edges = NULL;
	vertex->next = NULL;

	if (!last)
	{
		graph->vertices = vertex;
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = vertex;
	}

	graph->nb_vertices++;

	return (vertex);
}
