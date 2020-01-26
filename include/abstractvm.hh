/*
** EPITECH PROJECT, 2020
** Abstractvm.hh
** File description:
** ...
*/

#ifndef _ABSTRACT_VM_HH_
#define _ABSTRACT_VM_HH_

#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include <map>
#include <fstream>
#include <stdbool.h>
#include <regex>
#include <stdexcept>

#define DIVISION_BY_ZERO "OPERATOR ERROR: Division by zero forbiden.\n"
#define FALSE_ASSERT "ASSERT ERROR: the value does not match the top stack value.\n"
#define LOAD_ERROR "LOAD ERROR: can't execute load on empty register.\n"
#define EMPTY_STACK "STACK ERROR: Can't execute commands on empty stack.\n"

#include "AbstractVmException.hh"

#endif