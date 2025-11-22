cmake_minimum_required(VERSION 4.0)
project(data_structure C)

set(CMAKE_C_STANDARD 23)

add_executable(data_structure main.c
        linear/array/sequence_list.c
        linear/array/sequence_list.h
        linear/array/sequence_list_test.c
        linear/array/sequence_list_dynamic.c
        linear/array/sequence_list_dynamic.h
        linear/linked-list/singly_linked_list.c
        linear/linked-list/singly_linked_list.h
        linear/linked-list/doubly_linked_list.c
        linear/linked-list/doubly_linked_list.h
        linear/linked-list/singly_linked_list_test.c
        linear/linked-list/doubly_linked_list_test.c
        linear/queue/seq_queue.c
        linear/queue/seq_queue.h
        linear/queue/linked_queue.c
        linear/queue/linked_queue.h
        linear/stack/seq_stack.c
        linear/stack/seq_stack.h
        linear/stack/linked_stack.c
        linear/stack/linked_stack.h
        linear/stack/seq_stack_test.c
        linear/stack/linked_stack_test.c
        algo/recur.c
        algo/recur.h
)
