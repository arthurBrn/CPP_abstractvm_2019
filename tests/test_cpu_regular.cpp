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

Test(push, grostest)
{
    Memory *mem;
    CPU cpu;
    std::string type ="int8";
    std::string val = "2";

    cpu.push(mem, type, val);
    cr_assert_str_eq(mem->getStackAtIndexX(0)->getValue().c_str(), "2");
}