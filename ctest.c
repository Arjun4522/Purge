#include <stdio.h>
#include "purge.h"

int main() {
    // Create a stack of nodes
    Node *stack_root = create_node(1);
    stack_root->next = create_node(2);
    stack_root->next->next = create_node(3);

    // Global root pointing to the stack
    global_root = create_node(10);
    global_root->next = stack_root;

    // Create heap nodes and connect them
    Node *heap_node1 = create_node(100);
    Node *heap_node2 = create_node(200);
    heap_node1->next = heap_node2;

    // Create nodes connected to the stack chain but not used
    stack_root->next->next->next = heap_node1;

    // Create additional nodes that are unreachable and not connected
    Node *unreachable_node1 = create_node(300);
    Node *unreachable_node2 = create_node(400);
    Node *unreachable_node3 = create_node(500);

    // Some nodes are allocated but never referenced
    Node *isolated_node1 = create_node(600);
    Node *isolated_node2 = create_node(700);
    Node *isolated_node3 = create_node(800);

    // Even more nodes that become inaccessible after being linked to a temporary chain
    Node *temp_node1 = create_node(900);
    Node *temp_node2 = create_node(1000);
    Node *temp_node3 = create_node(1100);

    temp_node1->next = temp_node2;
    temp_node2->next = temp_node3;

    // After this, temp_node1, temp_node2, and temp_node3 are unreachable
    // and no longer part of the main list

    // Some memory that is allocated and later discarded
    Node *discarded_node1 = create_node(1200);
    Node *discarded_node2 = create_node(1300);

    // These nodes will be lost and never freed
    discarded_node1 = create_node(1400);
    discarded_node2 = create_node(1500);

    // Call garbage collection
    garbage_collect();

    // Cleanup remaining memory
    cleanup();

    return 0;
}
