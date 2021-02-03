//
// Created by aleksei on 2/2/21.
//

#ifndef WARTSILA_TEST_CIRCLE_H
#define WARTSILA_TEST_CIRCLE_H
#include "Figure.h"
/**
 * @brief Class for circles.
 */

class Circle : public Figure {

protected:
    [[nodiscard]] std::string getParams() const override;
public:
    Circle() : Figure("круг"){};
    [[nodiscard]] std::vector<std::vector<bool>> getMask(int size) const override;
    void setParams(int size, Dot coords) override;
private:
    unsigned int m_Diameter = 0;
    Dot m_Center;
};


#endif //WARTSILA_TEST_CIRCLE_H
