#include "Bounds.h"

bool Bounds::Intersects(Bounds& otherBounds)
{
    Vector OwnMin = GetMinPosition();
    Vector OwnMax = GetMaxPostition();
    Vector OtherMin = otherBounds.GetMinPosition();
    Vector OtherMax = otherBounds.GetMaxPostition();

    bool collision = 
        ( OwnMax.x   >= OtherMin.x) &&  // x1Max >= x2Min
        ( OtherMax.x >= OwnMin.x)   &&  // x2Max >= x1Min
        ( OwnMax.y   >= OtherMin.y) &&  // y1Max >= y2Min
        ( OtherMax.y >= OwnMin.y);                  // y2Max >= y1Min

    return collision;
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
