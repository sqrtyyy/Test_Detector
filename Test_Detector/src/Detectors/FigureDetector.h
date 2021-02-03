//
// Created by aleksei on 1/30/21.
//

#ifndef WARTSILA_TEST_FIGUREDETECTOR_H
#define WARTSILA_TEST_FIGUREDETECTOR_H

#include "../BitImage.h"
#include "../Figures/Figure.h"
/**
 * @brief Class for detection different figures on a bit image.
 */
class FigureDetector {
protected:
    /**
     * @brief Struct for storing information about figure location and it's suitability.
     */
    struct FigureData{
        Figure::Dot location = {}; /// coordinates of upper m_Left angle of bit mask.
        int size = 0; /// size of a figure.
        double accuracy = 0; /// suitability.
    };
public:
    /**
     * Constructor which loads the bit image and calculates the borders of useful area.
     * @param bitImage
     */
    explicit FigureDetector(const BitImage * bitImage);
    /**
     * @brief Seeks the figure on the image.
     * @param figure The type of figure, which should be found.
     * @return The accuracy of seeking the figure.
     */
    [[nodiscard]] double detect(Figure* figure) const;
private:
    /**
     * @brief Checks if the column in bitImage is empty.
     * @param column The index of column which should be checked.
     * @return If the column is empty.
     */
    [[nodiscard]] bool isEmptyColumn(unsigned int column) const;
    /**
     * @brief Checks if the line in bitImage is empty.
     * @param line The index of line which should be checked.
     * @return If the line is empty.
     */
    [[nodiscard]] bool isEmptyLine(unsigned int line) const;
    /**
     * @brief Compares the mask and area of image.
     * @param dot Coordinates of top left corner.
     * @param mask The mask.
     * @return The accuracy of matching;.
     */
    [[nodiscard]] double compareMask(const Figure::Dot& dot, std::vector<std::vector<bool>> mask) const;
private:
    unsigned int m_Top;///Index of first non-empty line.
    unsigned int m_Bottom;///Index of last non-empty line
    unsigned int m_Right;///Index of last non-empty column.
    unsigned int m_Left;///Index of first non-empty column.
    const BitImage * const m_Data;///Image
};


#endif //WARTSILA_TEST_FIGUREDETECTOR_H
