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

Test(createInt8, create_int_height)
{
    const std::string &value = "8";

    IOperand *obj = Factory::createOperand(eOperandType::INT8, value);
    cr_assert_eq(obj->getValue(), value);
    cr_assert_eq(obj->getType(), eOperandType::INT8);
}

Test(createInt16, create_int_sixteen)
{
    const std::string &value = "8";

    IOperand *obj = Factory::createOperand(eOperandType::INT16, value);
    cr_assert_eq(obj->getValue(), value);
    cr_assert_eq(obj->getType(), eOperandType::INT16);
}

Test(createInt32, create_int_thirty_two)
{
    const std::string &value = "8";

    IOperand *obj = Factory::createOperand(eOperandType::INT32, value);
    cr_assert_eq(obj->getValue(), value);
    cr_assert_eq(obj->getType(), eOperandType::INT32);
}

Test(createFloat, create_float)
{
    const std::string &value = "8";

    IOperand *obj = Factory::createOperand(eOperandType::FLOAT, value);
    cr_assert_eq(obj->getValue(), "8");
    cr_assert_eq(obj->getType(), eOperandType::FLOAT);
}

Test(createDouble, create_double)
{
    const std::string &value = "8";

    IOperand *obj = Factory::createOperand(eOperandType::DOUBLE, value);
    cr_assert_eq(obj->getValue(), "8");
    cr_assert_eq(obj->getType(), eOperandType::DOUBLE);
}

Test(createBigDecimal, create_big_decimal)
{
    const std::string &value = "8";

    IOperand *obj = Factory::createOperand(eOperandType::BIGDECIMAL, value);
    cr_assert_eq(obj->getValue(), value);
    cr_assert_eq(obj->getType(), eOperandType::BIGDECIMAL);
}

Test(createOperand, createNewOperand)
{
    IOperand *objInt8 = Factory::createOperand(eOperandType::INT8,"1");
    cr_assert_eq(objInt8->getValue(), "1");
    cr_assert_eq(objInt8->getType(), eOperandType::INT8);
    IOperand *objInt16 = Factory::createOperand(eOperandType::INT16,"2");
    cr_assert_eq(objInt16->getValue(), "2");
    cr_assert_eq(objInt16->getType(), eOperandType::INT16);
    IOperand *objInt32 = Factory::createOperand(eOperandType::INT32,"3");
    cr_assert_eq(objInt32->getValue(), "3");
    cr_assert_eq(objInt32->getType(), eOperandType::INT32);
    IOperand *objFloat = Factory::createOperand(eOperandType::FLOAT,"4");
    cr_assert_eq(objFloat->getValue(), "4");
    cr_assert_eq(objFloat->getType(), eOperandType::FLOAT);
    IOperand *objDouble = Factory::createOperand(eOperandType::DOUBLE,"5");
    cr_assert_eq(objDouble->getValue(), "5");
    cr_assert_eq(objDouble->getType(), eOperandType::DOUBLE);
    IOperand *objBigDecimal = Factory::createOperand(eOperandType::BIGDECIMAL,"6");
    cr_assert_eq(objBigDecimal->getValue(), "6");
    cr_assert_eq(objBigDecimal->getType(), eOperandType::BIGDECIMAL);
}