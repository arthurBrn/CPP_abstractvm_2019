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
#include <fstream>
#include <iostream>

using namespace std;

int main (int ac, char **av)
{
    /*
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
   

  if (ac == 1)
    cout << "Enter a command" << endl;
  else if (ac == 2)
    cout << "Read the file" << endl;
  else
    cout << "Errot too much arguments"  << endl; */
  
  std::vector<std::string>commands;
  std::ifstream file;
  file.open("test.avm");
  std::string line;
  if (file.is_open()) {
    while (getline(file, line))
      commands.push_back(line);
  } else
    std::cout << "no files match" << std::endl;
  file.close();
  return 0;
}
