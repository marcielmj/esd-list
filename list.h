#ifndef LIST_H
#define LIST_H
#include "node.h"

/* Códigos de retorno */
enum {
    SUCCESS = 0,
    PARAM_E = 1,
    MEMORY_E = 2
};

typedef struct {
    Node *head;
} List;

/**
 * Cria uma nova lista.
 *
 * return List* em caso de sucesso ou NULL caso contrário.
 */
List* list_create(void);

/**
 * Destroi uma lista.
 *
 * param [in] l - lista a ser desalocada.
 */
void list_destroy(List* l);

/**
 * Insere um novo elemento em uma lista.
 *
 * param [in, out] l    - lista à qual o dado será inserido.
 * param [in]      pos  - posição da inserção.
 * param [in]      data - valor a ser inserido.
 *
 * return Vide "Códigos de retorno".
 */
int list_insert(List* l, int pos, int data);

/**
 * Remove um elemento de uma lista.
 *
 * param [in, out] l    - lista ao qual o dado será removido.
 * param [in]      pos  - posição da remoção.
 *
 * return Vide "Códigos de retorno".
 */
int list_remove(List* l, int pos);

/**
 * Busca um elemento em uma lista.
 *
 * param [in, out] l    - lista na qual o dado será procurado.
 * param [in]      data - valor a ser encontrado.
 *
 * return nó da primeira instância do elemento na lista ou NULL caso o elemento não exista na lista.
 */
Node* list_find(List* l, int data);

/**
 * Contabiliza a quantidade de um determinado elemento em uma lista.
 *
 * param [in, out] l    - lista na qual o dado será contabilizado.
 * param [in]      data - valor a ser contabilizado.
 *
 * return quantidade do elemento presente na lista.
 */
unsigned int list_count(List* l, int data);

/**
 * Inverte a ordem dos elementos de uma lista.
 *
 * param [in, out] l - lista a ser invertida.
 */
void list_reverse(List* l);

#endif
