#include <stdlib.h>
#include "node.h"

Node* node_create(int data) {
    Node* n = (Node *) malloc(sizeof(Node));

    if (n != NULL) {
        n->data = data;
        n->next = NULL;
    }

    return n;
}

void node_destroy(Node* n) {
    free(n);
}

void node_destroy_cascaded(Node* n) {
    if (n->next != NULL) {
        node_destroy_cascaded(n->next);
    }

    node_destroy(n);
}
