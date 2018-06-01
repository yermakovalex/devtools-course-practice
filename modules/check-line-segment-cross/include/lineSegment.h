// Copyright 2018 Razumova Maria

#ifndef MODULES_CHECK_LINE_SEGMENT_CROSS_INCLUDE_LINESEGMENT_H_
#define MODULES_CHECK_LINE_SEGMENT_CROSS_INCLUDE_LINESEGMENT_H_

class LineSegment {

public:
    LineSegment();
    LineSegment(double _x1, double _y1, double _x2, double _y2);
    LineSegment(const LineSegment&);
    LineSegment& operator=(const LineSegment&);
    bool operator==(const LineSegment& line) const;
    bool isCross (LineSegment&);
    double vectorProduct(const LineSegment& line);

private:
    double scalarProduct(const LineSegment& line);
    int sign(double _x1, double _y1);
    double x1, y1, x2, y2;
};

#endif  // MODULES_CHECK_LINE_SEGMENT_CROSS_INCLUDE_LINESEGMENT_H_
