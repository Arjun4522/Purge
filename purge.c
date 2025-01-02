#include <stdio.h>
#include <stdlib.h>
#include "purge.h"

// Define the global variables
Node *global_root = NULL;
Node *reachable_list = NULL;
Node *all_objects_list = NULL;
Node *unreachable_list = NULL;
Node *visited_list = NULL;

// Function to add a node to a list
void add_to_list(Node **list, Node *node) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Malloc failed");
        exit(1);
    }
    new_node->data = node->data;
    new_node->next = *list;
    *list = new_node;
}

// Function to check if a node is in a list
bool is_in_list(Node *list, Node *node) {
    Node *current = list;
    while (current != NULL) {
        if (current->data == node->data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Function to check if a node is visited
bool is_visited(Node *node) {
    return is_in_list(visited_list, node);
}

// Function to mark a heap object as reachable (marking step in GC)
void mark(Node *node) {
    if (node == NULL || is_visited(node)) {
        return;
    }
    add_to_list(&visited_list, node); // Mark the node as visited
    add_to_list(&reachable_list, node); // Mark the node as reachable
    mark(node->next); // Recurse on next node
}

// Function to create the unreachable list
void create_unreachable_list() {
    Node *current = all_objects_list;
    while (current != NULL) {
        if (!is_in_list(reachable_list, current)) {
            add_to_list(&unreachable_list, current);
        }
        current = current->next;
    }
}

// Function to free all nodes in the unreachable list
void free_unreachable_objects() {
    Node *current = unreachable_list;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        printf("Freeing node with data: %d\n", temp->data);
        free(temp);
    }
    unreachable_list = NULL; // Clear the unreachable list
}

// Function to simulate garbage collection (using mark and sweep)
void garbage_collect() {
    printf("Starting garbage collection...\n");
    mark(global_root);
    create_unreachable_list();
    free_unreachable_objects();
    printf("Garbage collection complete.\n");
}

// Function to create a new node dynamically (simulate heap allocation)
Node* create_node(int value) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Malloc failed");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    add_to_list(&all_objects_list, new_node);
    free(new_node);
    return new_node;
}

// Function to print a list of nodes
void print_list(Node *list, const char *list_name) {
    Node *current = list;
    printf("\n%s: ", list_name);
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free a list of nodes
void free_list(Node **list) {
    Node *current = *list;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL; // Clear the list after freeing its nodes
}

// Function to free all dynamically allocated memory for the lists
void cleanup() {
    free_list(&reachable_list);
    free_list(&all_objects_list);
    free_list(&unreachable_list);
    free_list(&visited_list);  
    // printf("Cleanup complete: All dynamically allocated memory is freed.\n");
}