
#ifndef IMAGEPIXEL_H
#define IMAGEPIXEL_H

#include <iostream>
#include <cmath>

using namespace std;

class ReferencePoint {
public:
    ReferencePoint() = default;
    ReferencePoint(int x, int y, double longitude, double latitude)
        : x(x), longitude(longitude), y(y), latitude(latitude)
    {}

    int x{};
    double longitude{};
    int y{};
    double latitude{};
};

class ScaledMap {
public:
    ScaledMap() {};
    ScaledMap(int width, int height, ReferencePoint p1, ReferencePoint p2, int xOffset, int yOffset)
        : width(width), height(height), p1(p1), p2(p2), xOffset(xOffset), yOffset(yOffset)
    {
        xScale = abs(p1.longitude - p2.longitude) / abs(p1.x - p2.x);
        yScale = abs(p1.latitude - p2.latitude) / abs(p1.y - p2.y);
        longitudeScale = abs(p1.x - p2.x) / abs(p1.longitude - p2.longitude);
        latitudeScale = abs(p1.y - p2.y) / abs(p1.latitude - p2.latitude);

        double minLongitude = p1.longitude - (p1.x * xScale);
        double maxLongitude = p1.longitude + ((width - p1.x) * xScale);

        double minLatitude = p1.latitude + (p1.y * yScale);
        double maxLatitude = p1.latitude - ((height - p1.y) * yScale);

        minPoint = ReferencePoint(0, 0, minLongitude, minLatitude);
        maxPoint = ReferencePoint(501, 491, maxLongitude, maxLatitude);
    }

    int width;
    int height;
    ReferencePoint p1;
    ReferencePoint p2;
    ReferencePoint minPoint;
    ReferencePoint maxPoint;
    double xScale;
    double yScale;
    double longitudeScale;
    double latitudeScale;
    int xOffset;
    int yOffset;


    int longitudeToX(double longitude) {
        int x = abs((longitude - minPoint.longitude) * longitudeScale) + xOffset;
        return x;
    }

    int latitudeToY(double latitude) {
        int y = abs((latitude - minPoint.latitude) * latitudeScale) + yOffset;
        return y;
    }
};


#endif // IMAGEPIXEL_H
