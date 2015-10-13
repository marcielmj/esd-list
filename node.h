#ifndef NODE_H
#define NODE_H

typedef struct n {
    int data;
    struct n *next;
} Node;

/**
 * Cria uma novo nó.
 *
 * return Node* em caso de sucesso ou NULL caso contrário.
 */
Node* node_create(int data);

/**
 * Destroi um nó.
 *
 * param [in] n - nó a ser desalocado.
 */
void node_destroy(Node* n);

/**
 * Destroi um nó, e todos os outros a partir dele.
 *
 * param [in] n - nó a ser desalocado.
 */
void node_destroy_cascaded(Node* n);

#endif
