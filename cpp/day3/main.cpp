#include <iostream>
#include <cmath>

int calcDistanceFromOrigin(int x, int y) {
    return (int)std::sqrt((x*x) + (y*y));
}

int calcSpiral(int max, int count, int x, int y, int maxX, int minX, int maxY, int minY) {
    if (count > max) {
        return calcDistanceFromOrigin(x, y);
    }
    if (x == maxX && x == minY) {
        //go right, genesis
        return calcSpiral(max, count + 1, x + 1, y, maxX + 1, minX, maxY, minY);
    }
    //
    if (x == maxX && x > maxY) {
        // go up
        if (y == maxY) {
            maxY += 1;
        }
        return calcSpiral(max, count + 1, x, y + 1, maxX, minX, maxY, minY);
    }

    if (x > minX && x == maxY) {
        // go left
        return calcSpiral(max, count + 1, x - 1, y, maxX, minX, maxY, minY);
    }

    if (y == maxY && y > std::abs(minX)) {
        // go left
        if (x == minX) {
            minX -= 1;
        }
        return calcSpiral(max, count + 1, x - 1, y, maxX, minX, maxY, minY);
    }

    if (x == minX && y > x) {
        // go down
        return calcSpiral(max, count + 1, x, y - 1, maxX, minX, maxY, minY);
    }

    if (minY != y) {
        minY = y;
    }

    return calcSpiral(max, count + 1, x + 1, y, maxX, minX, maxY, minY);
}

int main()
{
    const int max = 368078;
    int count = 1;
    int maxX = 0;
    int minX = 0;
    int maxY = 0;
    int minY = 0;
    int X = 0;
    int Y = 0;

    // algo to develop spiral, find location, add x and y
    // cartesian system, distance where (x1, y1) == (0,0) so d = sqrt((0-xn)^2+(0-yn)^2)

    // spiral increase to x max + 1, increase to y max+1, decrease to x min -1, decrease to y min -1

    int part1 = calcSpiral(max, count, X, Y, maxX, minX, maxY, minY);

    std::cout << part1 << std::endl;

    return 0;
}
