
#ifndef _CLASS_FUN_CPP
#define _CLASS_FUN_CPP

#include <string>
#include <iostream>
#include "include/class_fun.hpp"

using namespace std;

int
stupid_area(const Polygon& p)
{
  return -p.height * p.width;
}

void
Polygon::set_values(int a, int b)
{
  width = a;
  height = b;
}

int
Polygon ::area()
{
  return 0;
}

int
Rectangle ::area()
{
  return width * height;
}

int
Triangle ::area()
{
  return width * height / 2;
}

string
Polygon ::get_name()
{
  return "Polygon";
}

string
Rectangle ::get_name()
{
  return "Rectangle";
}

string
Triangle ::get_name()
{
  return "Triangle";
}


void
class_fun()
{
  Polygon weird;
  Rectangle rect;
  Triangle trgl;
  Polygon* ppoly1 = &rect;
  Polygon* ppoly2 = &trgl;
  ppoly1->set_values(4, 5);
  ppoly2->set_values(4, 5);
  cout << "Rect area is " << rect.area() << '\n';
  cout << "Trgl area is " << trgl.area() << '\n';
  cout << "Rect(Poly) area is " << ppoly1->area() << '\n';
  cout << "Trgl(Poly) area is " << ppoly2->area() << '\n';
  cout << "Stupid rect " << stupid_area(rect) << endl;
  cout << "Stupid triangle " << stupid_area(trgl) << endl;
  cout << "weird name " << weird.get_name() << endl;
  cout << "Rect name " << rect.get_name() << endl;
  cout << "Trgl name " << trgl.get_name() << endl;
  cout << "Rect(Poly) name " << ppoly1->get_name() << endl;
  cout << "Trgl(Poly) name " << ppoly2->get_name() << endl;
}

#endif
