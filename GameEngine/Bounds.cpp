#include "Bounds.h"

bool Bounds::Intersects(const Bounds& otherBounds)
{
    return
        ( maxPosition.x >= otherBounds.minPosition.x  )              &&  // x1Max >= x2Min
        ( otherBounds.maxPosition.x >= otherBounds.minPosition.x)   &&  // x2Max >= x1Min
        ( maxPosition.y > otherBounds.minPosition.y)                &&  // y1Max >= y2Min
        ( otherBounds.maxPosition.y >= minPosition.y);                  // y2Max >= y1Min
}

Vector Bounds::GetCenter()
{
    return center;
}

Vector Bounds::GetExtends()
{
    return extends;
}
