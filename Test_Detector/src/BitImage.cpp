//
// Created by aleksei on 1/29/21.
//

#include <fstream>
#include<string>
#include "BitImage.h"

BitImage::BitImage(unsigned int height, unsigned int width) : m_Height(height), m_Width(width) {
    m_Data = new bool [height * width];
}

BitImage::~BitImage() {
    delete m_Data;
}

bool BitImage::loadImage(const std::string &fileName){
    m_NumOfOnes = 0;
    std::ifstream inputFile(fileName);

    if(!inputFile) return false;
    std::string strLine;
    int lineNum = 0;
    while (getline(inputFile, strLine) && !strLine.empty()){
        if(strLine.length() != m_Width) break;
        for (int i = 0; i < m_Width; ++i) {
            m_Data[lineNum * m_Width + i] = strLine[i] == '1';
            m_NumOfOnes += m_Data[lineNum * m_Width + i];
        }
        lineNum++;
    }
    inputFile.close();
    return m_Height == lineNum;
}

bool BitImage::getPixel(unsigned int line, unsigned int column) const {
    if (line >= m_Height || column > m_Width) {
        throw std::out_of_range("Wrong index of bit");
    }
    return m_Data[line * m_Width + column];
}

unsigned int BitImage::getHeight() const {
    return m_Height;
}

unsigned int BitImage::getWidth() const {
    return m_Width;
}

unsigned int BitImage::getNumOfOnes() const {
    return m_NumOfOnes;
}
