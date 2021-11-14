
#include <string>
#include <iostream>
#include <numeric>
#include <memory>
#include "integer_fun.hpp"

#ifndef _INTEGER_FUN_CPP
#define _INTEGER_FUN_CPP

using std::cout;
using std::endl;
using std::partial_sum;
using std::make_shared;

void
print_ints(string prefix, ivector& int_list)
{
  cout << prefix << " [ ";
  for (auto it = int_list.begin(); it != int_list.end(); it++)
  {
    cout << *it;
    if (it != int_list.end() - 1)
    {
      cout << ", ";
    }
  }
  cout << " ]" << endl;
}

ivector*
add_ints_with_memory_leak(ivector* pInt_list)
{
  ivector* pNew_list = new ivector(pInt_list->size());
  partial_sum(pInt_list->begin(), pInt_list->end(), pNew_list->begin());
  return pNew_list;
}

shared_ptr<ivector>
add_ints_with_shared_ptr(ivector* pInt_list)
{
  auto pNew_list = make_shared<ivector>(pInt_list->size());
  partial_sum(pInt_list->begin(), pInt_list->end(), pNew_list->begin());
  return pNew_list;
}

void
add_ints_in_place(ivector* pInt_list)
{
  partial_sum(pInt_list->begin(), pInt_list->end(), pInt_list->begin());
}

void
integer_fun()
{
  ivector int_list;
  for (int i = 0; i < 10; i++)
  {
    int_list.push_back(i);
  }
  auto copy_list = ivector(int_list);
  print_ints("int_list", int_list);
  print_ints("copy_list", copy_list);

  add_ints_in_place(&int_list);
  print_ints("int_list", int_list);
  print_ints("copy_list", copy_list);

  shared_ptr<ivector> pNew_list = add_ints_with_shared_ptr(&copy_list);
  print_ints("int_list", int_list);
  print_ints("copy_list", copy_list);
  print_ints("*pNew_list", *pNew_list);

  pNew_list.reset();
}

#endif