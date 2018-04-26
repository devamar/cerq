#include <algorithm>
#include <emscripten/emscripten.h>

int min4(int x, int y, int z, int w) {
  return std::min(std::min(x, y), std::min(z, w));
}

int max4(int x, int y, int z, int w) {
  return std::max(std::max(x, y), std::max(z, w));
}

class Interval
{
  // Access specifier
  public:

  // Data Members
  int a;
  int b;

  // Member Functions()
  Interval(int a, int b)
  {
    this->a = a;
    this->b = b;
  }

  void add(Interval other)
  {
    a += other.a;
    b += other.b;
  }

  void mult(Interval other)
  {
    a = min4(a*b, a*other.b, b*other.a, b*other.b);
    b = max4(a*b, a*other.b, b*other.a, b*other.b);
  }

};

extern "C" {

EMSCRIPTEN_KEEPALIVE
void benchmark_add(int N)
{
  Interval a(0, 0);
  Interval b(4, 7);

  for (int i = 0; i < N; i++)
  {
    a.add(b);
  }
}

EMSCRIPTEN_KEEPALIVE
void benchmark_mult(int N)
{
  Interval a(0, 0);
  Interval b(4, 7);

  for (int i = 0; i < N; i++)
  {
    a.add(b);
  }
}

}
