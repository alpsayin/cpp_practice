
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
  // virtual string 
  string 
  get_name();
  virtual int
  area();
  friend int stupid_area(const Polygon&);
};

class Rectangle : public Polygon
{
public:
  int
  area();
  string get_name();
};

class Triangle : public Polygon
{
public:
  int
  area();
  string get_name();
};

void
class_fun();

#endif