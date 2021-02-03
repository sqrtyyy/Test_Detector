//
// Created by aleksei on 1/30/21.
//

#include "FigureDetector.h"


double FigureDetector::detect(Figure * figure) const{

    FigureData bestFigure;

    for (int i = 5; i <= 10; ++i) {
        auto mask = figure->getMask(i);
        if(mask.size() > (m_Bottom - m_Top + 1) || mask[0].size() > (m_Right - m_Left + 1)) break;
        for (unsigned int j = m_Top; j <= m_Bottom - mask.size() + 1; ++j) {
            for (unsigned int k = m_Left; k <= m_Right - mask[0].size() + 1; ++k) {
                auto accuracy = compareMask({(double)j, (double)k}, mask);
                if (accuracy > bestFigure.accuracy){
                    bestFigure.accuracy = accuracy;
                    bestFigure.size = i;
                    bestFigure.location = {(double)j,(double)k};
                }
                if(accuracy == 1) break;
            }
        }
    }
    figure->setParams(bestFigure.size, bestFigure.location);
    return bestFigure.accuracy;
}

bool FigureDetector::isEmptyLine(unsigned int line) const {
    for (unsigned int column = m_Left; column <= m_Right; ++column) {
        if(m_Data->getPixel(line,column)) return false;
    }
    return true;
}

bool FigureDetector::isEmptyColumn(unsigned int column) const {
    for (unsigned int line = m_Top; line <= m_Bottom; ++line) {
        if(m_Data->getPixel(line, column)) return false;
    }
    return true;
}

double FigureDetector::compareMask(const Figure::Dot& dot, std::vector<std::vector<bool>> mask) const {
    int numOfWrongPixels = 0;
    int height = mask.size();
    int width = mask[0].size();
    int numOfOnes = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            numOfWrongPixels += mask[i][j] != m_Data->getPixel(dot.y + i, dot.x + j);
            numOfOnes += m_Data->getPixel(dot.y + i, dot.x + j);
        }
    }
    for (int i = -1; i <= height; ++i) {
        numOfWrongPixels += m_Data->getPixel(dot.y + i, dot.x - 1);
        numOfWrongPixels += m_Data->getPixel(dot.y + i, dot.x + width);
    }
    for (int i = -1; i <= width; ++i) {
        numOfWrongPixels += m_Data->getPixel(dot.y - 1, dot.x + i);
        numOfWrongPixels += m_Data->getPixel(dot.y + height, dot.x + i);
    }
    return (1 - (double)numOfWrongPixels / ((height + 1) * (width + 1))) * numOfOnes / m_Data->getNumOfOnes();
}

FigureDetector::FigureDetector(const BitImage *bitImage) : m_Data(bitImage){
    m_Top = 0;
    m_Bottom = bitImage->getHeight() - 1;
    m_Left = 0;
    m_Right = bitImage->getWidth() - 1;
    while (m_Top <= m_Bottom && isEmptyLine(m_Top)){
        m_Top++;
    }
    while (m_Bottom >= m_Top && isEmptyLine(m_Bottom)){
        m_Bottom--;
    }
    while (m_Left <= m_Right && isEmptyColumn(m_Left)){
        m_Left++;
    }
    while (m_Left <= m_Right && isEmptyColumn(m_Right)){
        m_Right--;
    }
};
