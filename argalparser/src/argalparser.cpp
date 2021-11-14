

#include <iostream>
#include <map>
#include <string>
#include "argalparser.hpp"

#ifndef _ARGUTILS_CPP
#define _ARGUTILS_CPP

using std::cout;
using std::endl;
using std::map;
using std::string;

static map<string, arg_callback_f> arg_callback_map;

bool
example_callback(const char* arg_val)
{
  cout << "flag with no args found" << endl;
  return false; // dont skip next
}

bool
example_callback_with_argument(const char* arg_val)
{
  cout << "flag with param found: ";
  if (arg_val == NULL)
  {
    cout << "(NULL)" << endl;
    return true; // skip next arg
  }
  cout << "\"" << arg_val << "\"" << endl;
  return true; // skip next arg
}

void
assign_callback_to_arg(const char* arg, arg_callback_f arg_callback_func)
{
  string key(arg);
  if (arg_callback_map.find(key) == arg_callback_map.end())
  {
    cout << "arg callback " << key << " assigned for first time" << endl;
  }
  else
  {
    cout << "arg callback overwritten" << endl;
  }
  arg_callback_map[key] = arg_callback_func;
}

void
process_args(int argc, char const* argv[])
{
  for (int i = 0; i < argc; i++)
  {
    // cout << "Arg #" << i << " : \"" << argv[i] << '\"' << endl;
    auto it = arg_callback_map.find(string(argv[i]));
    if (it != arg_callback_map.end())
    {
      if (i + 1 < argc)
      {
        if (it->second(argv[i + 1])) // return true means skip next argument
        {
          // parameter check before skipping next argument
          auto check = arg_callback_map.find(string(argv[i + 1]));
          if (check != arg_callback_map.end())
          {
            cout << "Warning: argument " << argv[i] << " entered without parameter" << endl;
          }
          else
          {
            i++; // only skip if the next argument is not a known flag
          }
        }
      }
      else
      {
        it->second(NULL);
      }
    }
  }
}

#endif