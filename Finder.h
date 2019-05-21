#include <iostream>

struct Node{
    Node * next = nullptr;
    int i = -1;
};

struct Finder {
    static Node * getCycleStart(Node * start) {
        if (!start) {
            return nullptr;
        }
        auto first_ptr = start;
        auto second_ptr = start;
        do {
            if (first_ptr) {
                first_ptr = first_ptr->next;
            } else {
                return nullptr;
            }
            if (second_ptr && second_ptr->next) {
                second_ptr = second_ptr->next->next;
            } else {
                return nullptr;
            }
        } while (first_ptr != second_ptr);
        auto cur_node = first_ptr;
        size_t size_cycle = 0;
        do {
            first_ptr = first_ptr->next;
            size_cycle++;
        } while (first_ptr != cur_node);
        first_ptr = start;
        second_ptr = start;
        for (size_t i = 0; i < size_cycle; i++) {
            first_ptr = first_ptr->next;
        }
        while (first_ptr != second_ptr) {
            first_ptr = first_ptr->next;
            second_ptr = second_ptr->next;
        }
        return first_ptr;
    }
};
