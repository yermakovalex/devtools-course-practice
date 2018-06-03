// Copyright 2018 Okunev Boris

#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <utility>

#include "include/integer_numerical_interval.h"

IntegerNumericalInterval::IntegerNumericalInterval() {
    leftBorder_ = 0;
    rightBorder_ = 0;
    isIncludeLeft_ = true;
    isIncludeRight_ = true;
}

IntegerNumericalInterval::IntegerNumericalInterval(const int leftBorder, const
    int rightBorder, const bool isIncludeLeft, const bool isIncludeRight) {

    if (!this->isInitializationCorrect(leftBorder, rightBorder, isIncludeLeft,
        isIncludeRight))
        throw(std::string("Wrong interval!\n"));
    leftBorder_ = leftBorder;
    rightBorder_ = rightBorder;
    isIncludeLeft_ = isIncludeLeft;
    isIncludeRight_ = isIncludeRight;
}

IntegerNumericalInterval::IntegerNumericalInterval(const std::string &
    interval) {
    std::stringstream ss(interval);
    char chF;
    char comma;
    char chS;
    ss >> chF >> leftBorder_ >> comma >> rightBorder_ >> chS;

    if (chF == '[') {
        isIncludeLeft_ = true;
    } else {
        if (chF == '(')
            isIncludeLeft_ = false;
        else
            throw(std::string("Wrong interval!\n"));
    }

    if (comma != ',')
        throw(std::string("Wrong interval!\n"));

    if (chS == ']') {
        isIncludeRight_ = true;
    } else {
        if (chS == ')')
            isIncludeRight_ = false;
        else
            throw(std::string("Wrong interval!\n"));
    }

    if (!isInitializationCorrect(leftBorder_, rightBorder_,
        isIncludeLeft_, isIncludeRight_))
        throw(std::string("Wrong interval!\n"));
}

IntegerNumericalInterval::IntegerNumericalInterval(const
    IntegerNumericalInterval & ni) {

    leftBorder_ = ni.leftBorder_;
    rightBorder_ = ni.rightBorder_;
    isIncludeLeft_ = ni.isIncludeLeft_;
    isIncludeRight_ = ni.isIncludeRight_;
}

bool IntegerNumericalInterval::isContainPoints(const vector<int>& points)
    const {
    pair<int, int> endPoints = getEndPoints();
    int begin = endPoints.first;
    int end = endPoints.second;
    int size = points.size();

    for (int i = 0; i < size; ++i)
        if (points[i] < begin || points[i] > end)
            return false;

    return true;
}

bool IntegerNumericalInterval::isHaveOverlapsRange(
    const IntegerNumericalInterval & ni) const {

    pair<int, int> endPoints = getEndPoints();
    pair<int, int> endPointsNI = ni.getEndPoints();
    if ((endPointsNI.first >= endPoints.first
         && endPointsNI.first <= endPoints.second) ||
        (endPointsNI.second >= endPoints.first
         && endPointsNI.second <= endPoints.second) ||
        (endPointsNI.first <= endPoints.first
          && endPointsNI.second >= endPoints.second))
        return true;
    return false;
}

bool IntegerNumericalInterval::isContainsRange(
    const IntegerNumericalInterval & ni) const {
    pair<int, int> endPoints = getEndPoints();
    pair<int, int> endPointsNI = ni.getEndPoints();
    if (endPointsNI.first >= endPoints.first
        && endPointsNI.second <= endPoints.second)
        return true;
    else
        return false;
}

vector<int> IntegerNumericalInterval::getAllPoints() const {
    pair<int, int> endPoints = getEndPoints();
    int size = endPoints.second - endPoints.first + 1;
    vector<int> points(size);

    int num = endPoints.first;
    for (int i = 0; i < size; ++i)
        points[i] = num++;
    return points;
}

pair<int, int> IntegerNumericalInterval::getEndPoints() const {
    pair<int, int> points;
    isIncludeLeft_ ? points.first = leftBorder_
                   : points.first = leftBorder_ + 1;
    isIncludeRight_ ? points.second = rightBorder_
                    : points.second = rightBorder_ - 1;
    return points;
}

bool IntegerNumericalInterval::operator==(
    const IntegerNumericalInterval & ni) const {
    if ((leftBorder_ == ni.leftBorder_) && (rightBorder_ == ni.rightBorder_)
        && (isIncludeLeft_ == ni.isIncludeLeft_)
        && (isIncludeRight_ == ni.isIncludeRight_))
        return true;
    else
        return false;
}

bool IntegerNumericalInterval::operator!=(
    const IntegerNumericalInterval & ni) const {
    return !(*this == ni);
}

IntegerNumericalInterval::operator std::string() {
    std::string out;
    isIncludeLeft_ ? out += '[' : out += '(';
    out += std::to_string(leftBorder_);
    out += ',';
    out += std::to_string(rightBorder_);
    isIncludeRight_ ? out += ']' : out += ')';
    return out;
}

bool IntegerNumericalInterval::isInitializationCorrect(const int leftBorder,
    const int rightBorder, const bool isIncludeLeft,
    const bool isIncludeRight) const {

    if (rightBorder < leftBorder)
        return false;
    if (rightBorder == leftBorder && (!isIncludeLeft || !isIncludeRight))
        return false;
    if ((rightBorder - leftBorder == 1) && !isIncludeLeft && !isIncludeRight)
        return false;
    return true;
}
