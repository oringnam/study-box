#pragma once

#include "Common.h"
#include "BuildingData.h"

class XelsNaga;
class BaseLocation;

class BuildingPlacer
{
    XelsNaga & m_bot;

    std::vector< std::vector<bool> > m_reserveMap;

    // queries for various BuildingPlacer data
    bool			buildable(const Building & b, int x, int y) const;
    bool			isReserved(int x, int y) const;
    bool			isInResourceBox(int x, int y) const;
    bool			tileOverlapsBaseLocation(int x, int y, sc2::UnitTypeID type) const;

public:
    BuildingPlacer(XelsNaga & bot);

    void onStart();

    // determines whether we can build at a given location
    bool			canBuildHere(int bx, int by, const Building & b) const;
    bool			canBuildHereWithSpace(int bx, int by, const Building & b, int buildDist) const;

    // returns a build location near a building's desired location
    sc2::Point2D	getBuildLocationNear(const Building & b, int buildDist) const;

    void			drawReservedTiles();

    void			reserveTiles(int x, int y, int width, int height);
    void			freeTiles(int x, int y, int width, int height);
    sc2::Point2D	getRefineryPosition();
};
