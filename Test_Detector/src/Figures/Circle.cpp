//
// Created by aleksei on 2/2/21.
//

#include "Circle.h"

#include <cmath>

using std::to_string;

static void fillMask(std::vector<std::vector<bool>>& mask){
    int size = mask.size();
    if(size % 2 == 1){
        for (int i = 0; i < size  / 2; ++i){
            mask[i][size / 2] = mask[size / 2][i] = mask[size - 1 - i][size / 2] = mask[size / 2][size - 1 - i] = true;
        }
        mask[size / 2][size / 2] = true;
    }
    for (int i = 0; i < size  / 2; ++i) {
        for (int j = 0; j < size / 2; ++j) {
            double x = i - (double)size / 2;
            double y = j - (double)size / 2;
            double r = sqrt(x * x + y * y);
            mask[i][j] = mask[size - 1 - i][j] = mask[i][size - 1 - j] = mask[size - 1 - i] [size - 1 - j] = r <= ((double)size / 2 + size % 2);
        }
    }
    if(size % 2 == 0){
        mask[0][size / 2] = mask [0][size / 2 - 1] =  mask[size - 1][size / 2] = mask [size - 1][size / 2 - 1] = true;
        mask[size / 2][0] = mask [size / 2 - 1][0] =  mask[size / 2][size - 1] = mask [size / 2 - 1][size - 1] = true;
    }
}


std::vector<std::vector<bool>> Circle::getMask(int size) const {
   auto mask = std::vector<std::vector<bool>>(size, std::vector<bool>(size, false));
   fillMask(mask);
   return mask;
}

void Circle::setParams(int size, Figure::Dot coords) {
    m_Diameter = size;
    m_Center.y = coords.y + (double)size / 2;
    m_Center.x = coords.x + (double)size / 2;
}

std::string Circle::getParams() const {
    return "диаметр: " + to_string(m_Diameter) + ", " + "координаты центра: " +
           "(" + to_string(m_Center.y) + ";" + to_string(m_Center.x) + ")";
}


