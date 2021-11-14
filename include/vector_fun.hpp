

#include <memory>
#include "integer_fun.hpp"

#ifndef _VECTOR_FUN_HPP
#define _VECTOR_FUN_HPP

using std::shared_ptr;
using std::unique_ptr;

shared_ptr<int>&
get_its_alive();

ivector
test_pointers_part1();

unique_ptr<ivector>
test_pointers_part2(shared_ptr<int> its_still_alive);

void
vector_fun();

#endif