#include <stdlib.h>
#include "graphs.h"

/**
 * graph_delete - Completely deletes a graph
 * @graph: Pointer to the graph to delete
 */
void graph_delete(graph_t *graph)
{
	if (!graph)
		return;

	vertex_t *current_vertex = graph->vertices;
	vertex_t *next_vertex;

	/* Loop through all vertices */
	while (current_vertex)
	{
		edge_t *current_edge = current_vertex->edges;
		edge_t *next_edge;

		/* Delete all edges for the current vertex */
		while (current_edge)
		{
			next_edge = current_edge->next;
			free(current_edge);
			current_edge = next_edge;
		}

		/* Move to the next vertex and free the current vertex */
		next_vertex = current_vertex->next;
		free(current_vertex->content); /* Free the content string */
		free(current_vertex);
		current_vertex = next_vertex;
	}

	/* Free the graph itself */
	free(graph);
}
