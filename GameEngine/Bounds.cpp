#include "Bounds.h"

bool Bounds::Intersects(const Bounds& otherBounds)
{
    return
        ( maxPosition.x >= otherBounds.minPosition.x  )             &&  // x1Max >= x2Min
        ( otherBounds.maxPosition.x >= otherBounds.minPosition.x)   &&  // x2Max >= x1Min
        ( maxPosition.y > otherBounds.minPosition.y)                &&  // y1Max >= y2Min
        ( otherBounds.maxPosition.y >= minPosition.y);                  // y2Max >= y1Min
}

void Bounds::SetPosition(const Vector& position)
{
    center = position;
}

void Bounds::SetExtends(const Vector& size)
{
    extends = size;
}

Vector Bounds::GetCenter()
{
    return center;
}

Vector Bounds::GetExtends()
{
    return extends;
}

Vector Bounds::GetMinPosition()
{
    return center + (extends * -1);
}

Vector Bounds::GetMaxPostition()
{
    return center + extends;
}
