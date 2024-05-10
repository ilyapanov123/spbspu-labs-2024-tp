#include "polygonFunctions.hpp"
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

double ponomarev::getArea(const Polygon & polygon)
{
  std::vector< int > values(polygon.points.size());

  std::transform(
  ++polygon.points.cbegin(),
  polygon.points.cend(),
  polygon.points.cbegin(),
  values.begin(),
  getValue
  );

  values.push_back(getValue(polygon.points.front(), polygon.points.back()));
  int area = std::accumulate(values.cbegin(), values.cend(), 0);
  return abs(area) / 2.0;
}

int ponomarev::getValue(const Point & first, const Point & second)
{
  return (first.x * second.y) - (first.y * second.x);
}

double ponomarev::sumEven(double res, const Polygon & polygon)
{
  return (polygon.points.size() % 2 == 0) ? res + getArea(polygon) : res;
}

double ponomarev::sumIfNumOfVertexes(double res, const Polygon & polygon, size_t numOfVertexes)
{
  return (polygon.points.size() == numOfVertexes) ? res + getArea(polygon) : res;
}
