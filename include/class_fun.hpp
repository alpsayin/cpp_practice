
#include <string>
#include <iostream>
using namespace std;

#ifndef _CLASS_FUN_HPP
#define _CLASS_FUN_HPP

class Polygon
{
protected:
  int width, height;

public:
  void
  set_values(int a, int b);
  string
  get_name();
  virtual string
  get_name_virtual();
  virtual int
  area();
  friend int
  stupid_area(const Polygon&);
};

class Rectangle : public Polygon
{
public:
  int
  area();
  string
  get_name();
  string
  get_name_virtual();
};

class Triangle : public Polygon
{
public:
  int
  area();
  string
  get_name();
  string
  get_name_virtual();
};

void
class_fun();

#endif