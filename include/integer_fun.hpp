
#include <string>
#include <vector>
#include <memory>

#ifndef _INTEGER_FUN_HPP
#define _INTEGER_FUN_HPP

using std::string;
using std::vector;
using std::shared_ptr;
using std::unique_ptr;
using ivector = vector<int>;

void
print_ints(string prefix, ivector& int_list);

ivector*
add_ints_with_memory_leak(ivector* pInt_list);

shared_ptr<ivector>
add_ints_with_shared_ptr(ivector* pInt_list);

void
add_ints_in_place(ivector* pInt_list);

void
integer_fun();

#endif