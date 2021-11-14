
#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <vector>
#include <memory>
#include "argalparser.hpp"
#include "integer_fun.hpp"
#include "vector_fun.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::partial_sum;
using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;

static ivector nums_to_sum;

bool
integer_fun_callback(const char*)
{
  integer_fun();
  return false;
}

bool
vector_fun_callback(const char*)
{
  vector_fun();
  return false;
}

bool
register_number_callback(const char* param)
{
  int num = atoi(param);
  if (0 != num)
  {
    nums_to_sum.push_back(num);
  }
  return true;
}

int
main(int argc, char const* argv[])
{
  assign_callback_to_arg("-ex1", example_callback);
  assign_callback_to_arg("-ex2", example_callback_with_argument);
  assign_callback_to_arg_LOG("-i", integer_fun_callback);
  assign_callback_to_arg_LOG("-v", vector_fun_callback);
  assign_callback_to_arg_LOG("-s", register_number_callback);

  process_args(argc, argv);
  print_ints("nums_to_sum = ", nums_to_sum);

  if (nums_to_sum.size() > 0)
  {
    add_ints_in_place(&nums_to_sum);

    cout << "The sum = " << nums_to_sum.back() << endl;
  }

  return 0;
}