
#include <string>
#include <iostream>
using namespace std;

#ifndef _CLASS_FUN_CPP
#define _CLASS_FUN_CPP

#include <string>
#include <iostream>
using namespace std;

class Polygon
{
protected:
  int width, height;

public:
  void
  set_values(int a, int b)
  {
    width = a;
    height = b;
  }
};

class Rectangle : public Polygon
{
public:
  int
  area()
  {
    return width * height;
  }
};

class Triangle : public Polygon
{
public:
  int
  area()
  {
    return width * height / 2;
  }
};

void
class_fun()
{
  Rectangle rect;
  Triangle trgl;
  Polygon* ppoly1 = &rect;
  Polygon* ppoly2 = &trgl;
  ppoly1->set_values(4, 5);
  ppoly2->set_values(4, 5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
}

#endif
