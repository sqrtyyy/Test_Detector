//
// Created by aleksei on 1/29/21.
//

#ifndef WARTSILA_TEST_BITIMAGE_H
#define WARTSILA_TEST_BITIMAGE_H

#include <iostream>
/**
 * @class BitImage
 * @brief Class which stores the file.
 */

class BitImage {
public:
    /**
     * @brief Creates empty img with params height and width.
     * @param height The height of image
     * @param width The width of image
     */
    BitImage(unsigned int height, unsigned int width);
    /**
     * @brief Loads the image from file.
     * @param fileName The name of file.
     * @return Possibility of loading the file.
     */
    bool loadImage(const std::string& fileName);
    /**
     * @brief Gets pixel from the img.
     * @param line The index of line of pixel.
     * @param column The index of column of pixel.
     * @return The pixel.
     */
    [[nodiscard]] bool getPixel(unsigned int line, unsigned int column) const;

    ~BitImage();
    /**
     * @brief Returns the height of the img.
     * @return
     */
    [[nodiscard]] unsigned int getHeight() const;
    /**
     * @brief Returns the width of the img.
     * @return
     */
    [[nodiscard]] unsigned int getWidth() const;
    /**
     * @brief Tells the number of ones on the img.
     * @return
     */
    [[nodiscard]] unsigned int getNumOfOnes() const;

private:
    bool * m_Data;
    unsigned int  m_Height;
    unsigned int  m_Width;
    unsigned  int m_NumOfOnes;

};


#endif //WARTSILA_TEST_BITIMAGE_H
