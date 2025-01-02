#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    // Create a stack of nodes using malloc
    Node *stack_root = (Node *)malloc(sizeof(Node));
    stack_root->data = 1;
    stack_root->next = (Node *)malloc(sizeof(Node));
    stack_root->next->data = 2;
    stack_root->next->next = (Node *)malloc(sizeof(Node));
    stack_root->next->next->data = 3;
    
    // Global root pointing to the stack
    Node *global_root = (Node *)malloc(sizeof(Node));
    global_root->data = 10;
    global_root->next = stack_root;

    // Create heap nodes and connect them
    Node *heap_node1 = (Node *)malloc(sizeof(Node));
    heap_node1->data = 100;
    Node *heap_node2 = (Node *)malloc(sizeof(Node));
    heap_node2->data = 200;
    heap_node1->next = heap_node2;

    // Create nodes connected to the stack chain but not used
    stack_root->next->next->next = heap_node1;

    // Create additional nodes that are unreachable and not connected
    Node *unreachable_node1 = (Node *)malloc(sizeof(Node));
    unreachable_node1->data = 300;
    Node *unreachable_node2 = (Node *)malloc(sizeof(Node));
    unreachable_node2->data = 400;
    Node *unreachable_node3 = (Node *)malloc(sizeof(Node));
    unreachable_node3->data = 500;

    // Some nodes are allocated but never referenced
    Node *isolated_node1 = (Node *)malloc(sizeof(Node));
    isolated_node1->data = 600;
    Node *isolated_node2 = (Node *)malloc(sizeof(Node));
    isolated_node2->data = 700;
    Node *isolated_node3 = (Node *)malloc(sizeof(Node));
    isolated_node3->data = 800;

    // Even more nodes that become inaccessible after being linked to a temporary chain
    Node *temp_node1 = (Node *)malloc(sizeof(Node));
    temp_node1->data = 900;
    Node *temp_node2 = (Node *)malloc(sizeof(Node));
    temp_node2->data = 1000;
    Node *temp_node3 = (Node *)malloc(sizeof(Node));
    temp_node3->data = 1100;

    temp_node1->next = temp_node2;
    temp_node2->next = temp_node3;

    // After this, temp_node1, temp_node2, and temp_node3 are unreachable
    // and no longer part of the main list

    // Some memory that is allocated and later discarded
    Node *discarded_node1 = (Node *)malloc(sizeof(Node));
    discarded_node1->data = 1200;
    Node *discarded_node2 = (Node *)malloc(sizeof(Node));
    discarded_node2->data = 1300;

    // These nodes will be lost and never freed
    discarded_node1 = (Node *)malloc(sizeof(Node));
    discarded_node1->data = 1400;
    discarded_node2 = (Node *)malloc(sizeof(Node));
    discarded_node2->data = 1500;


    return 0;
}
