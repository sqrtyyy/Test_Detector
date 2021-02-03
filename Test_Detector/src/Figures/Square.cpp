//
// Created by aleksei on 1/31/21.
//

#include "Square.h"

using  std::to_string;

std::string Square::getParams() const {
    return "сторона: " + to_string(m_SideLength) + ", " + "координаты угла: " +
    "(" + to_string(m_AngleCoords.y) + ";" + to_string(m_AngleCoords.x) + ")";
}

std::vector<std::vector<bool>> Square::getMask(int size) const {
    return std::vector<std::vector<bool>>(size,std::vector<bool>(size, true));
}

void Square::setParams(int size, Dot coords) {
    m_SideLength = size;
    m_AngleCoords = coords;
}
