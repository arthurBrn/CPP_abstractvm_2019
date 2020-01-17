/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** ...
*/

#include "abstractvm.hh"
#include "Factory.hh"
#include "IOperand.hh"
#include "AbstractVmException.hh"

using namespace std;

int main ()
{
  std::vector<std::string> str;
  str.push_back("one");
  str.push_back("two");
  str.push_back("three");
  string message = "Hello World";
  cout << message << endl;

  for (int i = 0; i < str.size(); i++) {
    std::cout << i << std::endl;
    std::cout << str.at(i) << std::endl;
  }
  std::cout << str.size() << std::endl;
}
