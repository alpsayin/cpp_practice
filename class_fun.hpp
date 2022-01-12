
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
};

class Rectangle : public Polygon
{
public:
  int
  area();
};

class Triangle : public Polygon
{
public:
  int
  area();
};

void
class_fun();

#endif