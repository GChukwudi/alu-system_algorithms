#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * graph_add_vertex - Adds a new vertex to a graph
 *
 * @graph: Pointer to the graph to add the vertex to
 * @str: The string to store in the new vertex
 *
 * Return: Pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex, *current;

	if (!graph || !str)
		return (NULL);

	/* Check if a vertex with the same string already exists */
	current = graph->vertices;
	while (current)
	{
		if (strcmp(current->content, str) == 0)
			return (NULL); /* Vertex already exists */
		current = current->next;
	}

	/* Allocate and initialize the new vertex */
	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
		return (NULL);

	new_vertex->content = strdup(str); /* Duplicate the string */
	if (!new_vertex->content)
	{
		free(new_vertex);
		return (NULL);
	}
	new_vertex->index = graph->nb_vertices;
	new_vertex->next = NULL;
	new_vertex->edges = NULL;

	/* Insert the new vertex at the beginning of the list */
	new_vertex->next = graph->vertices;
	graph->vertices = new_vertex;

	/* Increment the number of vertices in the graph */
	graph->nb_vertices++;

	return (new_vertex);
}
