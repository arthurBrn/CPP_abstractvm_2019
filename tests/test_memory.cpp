/*
** EPITECH PROJECT, 2020
** test_memory
** File description:
** test method of class Memory
*/

#include <criterion/criterion.h>
#include "Memory.hh"

Test(getStackSize, recover_stack_size)
{
    Memory mem;
    IOperand *obj;

    mem.setStack(obj);
    cr_assert_eq(mem.getStackSize(), mem.getAllStack().size());
}

Test(getStackAtIndexX, verify_return_stack_at_index){

    
}
Test(setStackAtIndexX, verify_set_stack_at_index){}
Test(getAllStack, verify_this_return_all_stack){}
Test(setStack, verify_stack_being_set){}

// returns error if the stack is empty unstack the value at the top
Test(pop, verify_pop_throw_error_on_empty_stack){}
Test(pop, verify_pop_unstack_the_stack){}
// empty the stack
Test(clear, verify_stack_is_emptied){}
// Duplicate stack top value
Test(dup, verify_get_stack_top_value){}
Test(dup, verify_dup_create_copy_of_top_stack){}
Test(dup, verify_dup_stack_back_the_copie){}
Test(dup, verify_two_first_top_value_are_the_same){}
// swap top two values of the stack
Test(swap, verify_top_two_value_are_diff){}
Test(swap, verify_swap_throw_error_on_stack_of_one_stack){}
Test(swap, verify_top_two_value_swaped){}
// dump, display all stack value from newest to oldest, separated w/ linebreak
Test(dump, verify_stack_not_empty){}
Test(dump, verify_stack_dumped){}
// print, make sure top stack is 8bit integer, interpret ascii value
Test(print, verify_print_recvoer_top_stack){}



