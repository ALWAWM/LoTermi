#ifndef RANDQI_H
#define RANDQI_H

#include "mainwindow.h"
#include <random>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <vector>
#include <QRandomGenerator>

inline int randRange(int minV, int maxV) {
    return QRandomGenerator::global()->bounded(minV, maxV + 1);
}
#endif // RANDQI_H
