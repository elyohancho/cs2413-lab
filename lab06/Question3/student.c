#include "graph.h"
#include <stddef.h>

// Check whether the graph contains a triangle.
// Returns 1 if there is at least one triangle, 0 otherwise.
int has_triangle(Graph* g) {
    if (g == NULL) return 0;
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = i + 1; j < MAX_NODES; ++j) {
            if (!g->adj[i][j]) continue;
            for (int k = j + 1; k < MAX_NODES; ++k) {
                if (g->adj[i][k] && g->adj[j][k]) return 1;
            }
        }
    }
    return 0;
}
