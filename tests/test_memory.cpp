/*
** EPITECH PROJECT, 2020
** test_memory
** File description:
** test method of class Memory
*/

#include <criterion/criterion.h>
#include "Memory.hh"
#include "AbstractVmException.hh"
#include "Output.hh"
#include "Factory.hh"
#include "IOperand.hh"
#include "Operand.hh"

Test(setStack, verify_stack_being_set_one_element)
{
    Memory me;
    IOperand *obj = Factory::createOperand(eOperandType::INT16, "14");

    me.setStack(obj);
    cr_assert_eq(me.getStackSize(), 1);
    cr_assert_eq(me.getStackAtIndexX(0)->getValue(), obj->getValue());
    cr_assert_eq(me.getStackAtIndexX(0)->getType(), obj->getType());
}

Test(setStack, verify_stack_being_set_multiple_element)
{
    Memory me;
    IOperand *obj3 = Factory::createOperand(eOperandType::INT16, "14");
    IOperand *obj2 = Factory::createOperand(eOperandType::INT16, "13");
    IOperand *obj1 = Factory::createOperand(eOperandType::INT16, "12");

    me.setStack(obj3);
    me.setStack(obj2);
    me.setStack(obj1);

    cr_assert_eq(me.getStackSize(), 3);
    cr_assert_eq(me.getStackAtIndexX(0)->getValue(), obj1->getValue());
    cr_assert_eq(me.getStackAtIndexX(0)->getType(), obj1->getType());
    cr_assert_eq(me.getStackAtIndexX(1)->getValue(), obj2->getValue());
    cr_assert_eq(me.getStackAtIndexX(1)->getType(), obj2->getType());
    cr_assert_eq(me.getStackAtIndexX(2)->getValue(), obj3->getValue());
    cr_assert_eq(me.getStackAtIndexX(2)->getType(), obj3->getType());
}

Test(getStackSize, recover_stack_size)
{
    Memory mem;
    IOperand *obj;
    IOperand *sndObj;

    mem.setStack(obj);
    mem.setStack(sndObj);
    cr_assert_eq(mem.getStackSize(), 2);
}

Test(getStackSize, recover_stack_size_zero)
{
    Memory mem;

    cr_assert_eq(mem.getStackSize(), 0);
}

Test(getStackAtIndexX, verify_return_stack_at_index)
{
    Memory memoire;
    IOperand* obj = Factory::createOperand(eOperandType::INT8, "2");
    IOperand* obj2 = Factory::createOperand(eOperandType::INT8, "3");

    memoire.setStack(obj);
    memoire.setStack(obj2);

    cr_assert_eq(memoire.getStackAtIndexX(0), obj2);
    cr_assert_eq(memoire.getStackAtIndexX(1), obj);
}

Test(setStackAtIndexX, verify_set_stack_at_index)
{
    Memory memoire;
    IOperand *obj1 = Factory::createOperand(eOperandType::INT8, "1");
    IOperand *obj2 = Factory::createOperand(eOperandType::INT8, "2");

    memoire.setStack(obj1);
    memoire.setStack(obj2);
    cr_assert_eq(memoire.getStackAtIndexX(0), obj2);
    cr_assert_eq(memoire.getStackAtIndexX(1), obj1);
    memoire.setStackAtIndexX(0, obj1);
    memoire.setStackAtIndexX(1, obj2);
    cr_assert_eq(memoire.getStackAtIndexX(0), obj1);
    cr_assert_eq(memoire.getStackAtIndexX(1), obj2);
}
Test(pop, verify_pop_throw_error_on_empty_stack) 
{
    Memory memoire;
    IOperand *obj = Factory::createOperand(eOperandType::INT8, "12");

    memoire.setStack(obj);
    cr_assert_eq(memoire.getStackSize(), 1);
    memoire.pop();
    cr_assert_eq(memoire.getStackSize(), 0);
}
Test(clear, verify_stack_is_emptied) 
{
    Memory mem;
    IOperand *obj = Factory::createOperand(eOperandType::INT8, "2");
    mem.setStack(obj);
    cr_assert_eq(mem.getStackSize(), 1);
    mem.clear();
    cr_assert_eq(mem.getStackSize(), 0);
}
Test(dup, verify_dup_create_copy_of_top_stack) 
{
    Memory mem;
    IOperand *obj = Factory::createOperand(eOperandType::INT8, "2");
    mem.setStack(obj);
    cr_assert_eq(mem.getStackSize(), 1);
    mem.dup();
    cr_assert_eq(mem.getStackSize(), 2);
    cr_assert_eq(mem.getStackAtIndexX(0)->getValue(), obj->getValue());
    cr_assert_eq(mem.getStackAtIndexX(0)->getType(), obj->getType());
    cr_assert_eq(mem.getStackAtIndexX(1)->getValue(), obj->getValue());
    cr_assert_eq(mem.getStackAtIndexX(1)->getType(), obj->getType());
}

Test(swap, verify_top_two_value_are_diff) 
{
    Memory mem;
    IOperand *obj1 = Factory::createOperand(eOperandType::INT8, "1");
    IOperand *obj2 = Factory::createOperand(eOperandType::INT16, "2");

    mem.setStack(obj1);
    mem.setStack(obj2);
    cr_assert_eq(mem.getStackAtIndexX(0)->getValue(), obj2->getValue());
    cr_assert_eq(mem.getStackAtIndexX(1)->getValue(), obj1->getValue());
    mem.swap();
    cr_assert_eq(mem.getStackAtIndexX(0)->getValue(), obj1->getValue());
    cr_assert_eq(mem.getStackAtIndexX(1)->getValue(), obj2->getValue());
}