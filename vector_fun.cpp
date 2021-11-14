

#include <iostream>
#include "vector_fun.hpp"

#ifndef _VECTOR_FUN_CPP
#define _VECTOR_FUN_CPP

static shared_ptr<int> its_alive;

using std::make_shared;
using std::make_unique;
using std::cout;
using std::endl;

ivector
test_pointers_part1()
{
  ivector raw_ptrs;
  auto unique_ptr_is_dead = make_unique<int>(111);
  auto long_live_the_shared_ptr = make_shared<int>(222);
  raw_ptrs.push_back((int)unique_ptr_is_dead.get());
  raw_ptrs.push_back((int)long_live_the_shared_ptr.get());
  print_ints("raw ptrs inside part1: ", raw_ptrs);
  its_alive = long_live_the_shared_ptr;
  cout << "address of returned vector inside = " << &raw_ptrs << endl;
  // gcc compiles this in a way so that list isn't copied but the reference is.
  return raw_ptrs; // I'd rather have it explicit though see part2
}

unique_ptr<ivector>
test_pointers_part2(shared_ptr<int> its_still_alive)
{
  auto upRaw_ptrs = make_unique<ivector>();
  auto unique_ptr_is_dead = make_unique<int>(111);
  auto long_live_the_shared_ptr = its_still_alive;
  upRaw_ptrs->push_back((int)unique_ptr_is_dead.get());
  upRaw_ptrs->push_back((int)long_live_the_shared_ptr.get());
  print_ints("raw ptrs inside part1: ", *upRaw_ptrs);
  its_alive = long_live_the_shared_ptr;
  cout << " address of returned vector inside = " << upRaw_ptrs.get() << endl;
  return upRaw_ptrs; // so now i explicityle return the reference to the vector
}

void
vector_fun()
{

  ivector raw_ptrs = test_pointers_part1();
  cout << "address of returned vector outside = " << &raw_ptrs << endl;

  auto upRaw_ptrs = test_pointers_part2(its_alive);
  cout << "address of returned vector outside = " << upRaw_ptrs.get() << endl;

  // i now wonder if i can force a vector move
  raw_ptrs = ivector(test_pointers_part1()); // using a move constructor
  cout << "address of returned vector outside = " << &raw_ptrs << endl;

  // i now wonder if i can force a vector move
  raw_ptrs = test_pointers_part1(); // this is still using a move constructor
  auto raw_ptrs2 = ivector(raw_ptrs); // this should be using a copy constructor
  auto raw_ptrs3 = raw_ptrs; // this also should be using a copy constructor
  auto& raw_ptrs4 = raw_ptrs; // this is clearly a reference-copy
  cout << "address of returned vector outside = " << &raw_ptrs << endl;
  cout << "address of assigned vector       2 = " << &raw_ptrs2 << endl;
  cout << "address of assigned vector       3 = " << &raw_ptrs3 << endl;
  cout << "address of assigned vector       4 = " << &raw_ptrs4 << endl;
  print_ints("raw_ptrs pre modification: ", raw_ptrs);
  print_ints("raw_ptrs2 pre modification: ", raw_ptrs2);
  print_ints("raw_ptrs3 pre modification: ", raw_ptrs3);
  print_ints("raw_ptrs4 pre modification: ", raw_ptrs4);
  raw_ptrs2.push_back(222);
  raw_ptrs3.push_back(333);
  raw_ptrs4.push_back(444);
  print_ints("raw_ptrs pre modification: ", raw_ptrs);
  print_ints("raw_ptrs2 pre modification: ", raw_ptrs2);
  print_ints("raw_ptrs3 pre modification: ", raw_ptrs3);
  print_ints("raw_ptrs4 pre modification: ", raw_ptrs4);
}

#endif