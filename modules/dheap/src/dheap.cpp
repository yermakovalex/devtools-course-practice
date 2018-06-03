// Copyright 2018 Lipatov Igor

#include "include/dheap.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

#define EMPTY (-1)

typedef std::pair<int, int> Vertex;  // vertex number and path length


Dheap::Dheap(int d, int elemCount) {
    this->elemCount = elemCount;
    this->d = d;
    points.resize(20 * elemCount + 2, EMPTY);
    // storage.resize(elemCount);
}

bool Dheap::isEmpty() {
    return storage.empty();
}


Vertex Dheap::pop() {
    if ( isEmpty() )
        return Vertex(-1, -1);
    Vertex v = std::make_pair(storage[0], points[2 * storage[0]]);
    del(0);
    return v;
}

void Dheap::push(Vertex v) {
    storage.push_back(v.first);
    points[2 * v.first] = v.second;
    points[2 * v.first + 1] = static_cast<int>(storage.size()) - 1;
    int pos = up(static_cast<int>(storage.size()) - 1);
    points[2 * v.first + 1] = pos;
}

int Dheap::getVal(int vNum) {
    return points[2 * vNum];
}


int Dheap::key(int i) {
    // return length val
    return points[2 * storage[i]];
}

void Dheap::swap(int iFir, int iSec) {
    int pTmp = points[2 * storage[iFir] + 1];
    points[2 * storage[iFir] + 1] = points[2 * storage[iSec] + 1];
    points[2 * storage[iSec] + 1] = pTmp;

    int tmp = storage[iFir];
    storage[iFir] = storage[iSec];
    storage[iSec] = tmp;
}

int Dheap::up(int i) {
    int p = (i - 1) / d;
    while ((i != 0) && (key(p) > key(i))) {
    }
    return i;
}

void Dheap::del(int i) {
    points[2 * storage[i] + 1] = -1;
    points[2 * storage[i]] = -1;
    storage[i] = storage[storage.size() - 1];
    storage.pop_back();
    elemCount--;
    if ((i != 0) && (key(i) < key((i - 1) / d))) {
    } else {
        points[(2 * storage[i]) + 1] = down(i);
    }
}

int Dheap::down(int i) {
    int s = minChail(i);
    while ((s != 0) && (key(i) > key(s))) {
        swap(i, s);
        i = s;
        s = minChail(i);
    }
    return i;
}

int Dheap::minChail(int i) {
    if (storage.size() == 1) return 0;
    if ((i * d + 1) >= elemCount) {
        return 0;
    } else {
        int s = i * d + 1;
        int minKey = key(s);
        int last = (i + 1) * d;
        if (last > elemCount) last = elemCount - 1;
        for (int j = s + 1; j < last + 1; j++) {
            int tmp = key(j);
            if (minKey > tmp) {
            }
        }
        return s;
    }
}

Dheap::~Dheap() {}
