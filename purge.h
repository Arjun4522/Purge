#ifndef GC_H
#define GC_H

#include <stdbool.h>

// Define a structure representing a linked list node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global variables (part of the root set)
extern Node *global_root;
extern Node *reachable_list;
extern Node *all_objects_list;
extern Node *unreachable_list;
extern Node *visited_list; // New visited list

// Declare functions for the garbage collection process
void add_to_list(Node **list, Node *node);
bool is_in_list(Node *list, Node *node);
bool is_visited(Node *node);
void mark(Node *node);
void create_unreachable_list();
void free_unreachable_objects();
void garbage_collect();
Node* create_node(int value);
void print_list(Node *list, const char *list_name);

// Declare cleanup function to free all lists
void cleanup();
void free_list(Node **list);

#endif // GC_H
