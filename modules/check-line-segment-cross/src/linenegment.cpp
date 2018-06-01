// Copyright 2018 Razumova Maria

#include <include/lineSegment.h>


LineSegment::LineSegment()
{
    x1 = x2 = y1 = y2 = 0;
}

LineSegment::LineSegment(double _x1, double _y1, double _x2, double _y2):
    x1(_x1), y1(_y1), x2(_x2), y2(_y2)
{}

LineSegment::LineSegment(const LineSegment & ls):
    x1(ls.x1), y1(ls.y1), x2(ls.x2), y2(ls.y2)
{}

LineSegment& LineSegment::operator=(const LineSegment& line)
{
    if (&line != this)
    {
        x1 = line.x1;
        y1 = line.y1;
        x2 = line.x2;
        y2 = line.y2;
    }
    return *this;
}
bool LineSegment::operator ==(const LineSegment& line) const
{
    return (x1 == line.x1 && y1 == line.y1
            && x2 == line.x2 && y2 == line.y2);
}

double LineSegment::scalarProduct(const LineSegment &line)
{
    return (x2 - x1) * (line.x2 - line.x1) + (y2 - y1) * (line.y2 - line.y1);
}

double LineSegment::vectorProduct(const LineSegment &line)
{
    return (x2 - x1) * (line.y2 - line.y1) - (line.x2 - line.x1) * (y2 - y1);
}

int LineSegment::sign(double  _x1, double _y1)
{
    if (vectorProduct(LineSegment(x1, y1, _x1, _y1))>0)
        return 1;
    else if (vectorProduct(LineSegment(x1, y1, _x1, _y1))<0)
        return -1;
    else
        return 0;

}

bool LineSegment::isCross (LineSegment& line)
{
    if (sign(line.x1, line.y1)* sign(line.x2, line.y2) <= 0
            && line.sign(x1, y1)* line.sign(x2,y2)<=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

LineSegment::~LineSegment()
{

}
