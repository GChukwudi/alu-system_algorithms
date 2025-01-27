#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * find_vertex - Finds a vertex in the graph by its content
 * @graph: Pointer to the graph
 * @content: The string content to search for
 *
 * Return: Pointer to the found vertex, or NULL if not found
 */
static vertex_t *find_vertex(graph_t *graph, const char *content)
{
	vertex_t *current = graph->vertices;

	while (current)
	{
		if (strcmp(current->content, content) == 0)
			return (current);
		current = current->next;
	}

	return (NULL);
}

/**
 * add_edge_to_vertex - Adds an edge to a vertex's edge list
 * @vertex: The vertex to add the edge to
 * @dest: The destination vertex
 *
 * Return: 1 on success, 0 on failure
 */
static int add_edge_to_vertex(vertex_t *vertex, vertex_t *dest)
{
	edge_t *new_edge;

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);

	new_edge->dest = dest;
	new_edge->next = vertex->edges;
	vertex->edges = new_edge;

	return (1);
}

/**
 * graph_add_edge - Adds an edge between two vertices in the graph
 * @graph: Pointer to the graph
 * @src: The source vertex content
 * @dest: The destination vertex content
 * @type: The type of edge (UNIDIRECTIONAL or BIDIRECTIONAL)
 *
 * Return: 1 on success, 0 on failure
 */
int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *src_vertex, *dest_vertex;

	if (!graph || !src || !dest)
		return (0);

	/* Find source and destination vertices */
	src_vertex = find_vertex(graph, src);
	dest_vertex = find_vertex(graph, dest);
	if (!src_vertex || !dest_vertex)
		return (0);

	/* Add edge from src to dest */
	if (!add_edge_to_vertex(src_vertex, dest_vertex))
		return (0);

	/* Add edge from dest to src if BIDIRECTIONAL */
	if (type == BIDIRECTIONAL)
	{
		if (!add_edge_to_vertex(dest_vertex, src_vertex))
			return (0);
	}

	return (1);
}
