#include <stdlib.h>
#include "list.h"

List* list_create(void) {
    List *l = (List *) malloc(sizeof(List));

    if (l != NULL) {
        l->head = NULL;
    }

    return l;
}

void list_destroy(List* l) {
    if (l->head) {
        node_destroy_cascaded(l->head);
    }

    free(l);
}

static Node* _insert(Node* head, int pos, Node* n) {
    if (head == NULL) {
        return n;
    }

    if (pos == 0) {
        n->next = head;
        return n;
    }

    head->next = _insert(head->next, --pos, n);
    return head;
}

int list_insert(List* l, int pos, int data) {
    Node* n = node_create(data);

    if (n != NULL) {
        l->head = _insert(l->head, pos, n);
        return SUCCESS;
    }

    return MEMORY_E;
}

static Node* _remove(Node* head, int pos){
    if (head == NULL) {
        return NULL;
    }

    if (pos == 0) {
        Node* n = head->next;
        node_destroy(head);
        return n;
    }

    head->next = _remove(head->next, --pos);
    return head;
}

int list_remove(List* l, int pos) {
    if (l->head == NULL || pos < 0 ) {
        return PARAM_E;
    }

    l->head = _remove(l->head, pos);
    return SUCCESS;
}

Node* list_find(List* l, int data) {
    Node* n;

    for (n = l->head; n; n = n->next) {
        if (n->data == data) {
            return n;
        }
    }

    return NULL;
}

unsigned int list_count(List* l, int data) {
    int count = 0;
    Node* n;

    for (n = l->head; n; n = n->next) {
        if (n->data == data) {
            count++;
        }
    }

    return count;
}

void list_reverse(List* l) {
    List* new_list = list_create();
    Node* n;

    for (n = l->head; n; n = n->next) {
        list_insert(new_list, 0, n->data);
    }

    l->head = new_list->head;
    free(new_list);
}
