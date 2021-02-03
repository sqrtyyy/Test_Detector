//
// Created by aleksei on 1/31/21.
//

#ifndef WARTSILA_TEST_SQUARE_H
#define WARTSILA_TEST_SQUARE_H
#include "Figure.h"
/**
 * @brief Class for Square
 */
class Square : public Figure {
public:
    Square() : Figure("квадрат"){};
    [[nodiscard]] std::vector<std::vector<bool>> getMask(int size) const override;
    void setParams(int size, Dot coords) override;
protected:
    [[nodiscard]] std::string getParams() const override;;
private:
    int m_SideLength = 0;
    Dot m_AngleCoords;
};


#endif //WARTSILA_TEST_SQUARE_H
