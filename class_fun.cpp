
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
  virtual int
  area()
  {
    return 0;
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
  cout << "Rect area is " << rect.area() << '\n';
  cout << "Trgl area is " << trgl.area() << '\n';
  cout << "Rect(Poly) area is " << ppoly1->area() << '\n';
  cout << "Trgl(Poly) area is " << ppoly2->area() << '\n';
  cout << stupid_area(rect) << endl;
}

#endif
