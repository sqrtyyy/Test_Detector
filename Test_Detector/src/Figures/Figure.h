//
// Created by aleksei on 1/31/21.
//

#ifndef WARTSILA_TEST_FIGURE_H
#define WARTSILA_TEST_FIGURE_H
#include <string>
#include <vector>
/**
 * @brief An abstract class for operating with Figures
 */
class Figure {
protected:
    explicit Figure(std::string  name);
    /**
     * @brief Returns the string with figure's data such as size, coordinates and etc.
     *
     * @return  String with information.
     */
    [[nodiscard]] virtual std::string getParams() const = 0;
public:
    /**
     * @brief Struct for dots in image.
     */
    struct Dot{
        double y = 0;
        double x = 0;
        Dot() = default;
        Dot(double newY, double newX) : y(newY), x(newX){};
        Dot(Dot const& dot){
            y = dot.y;
            x = dot.x;
        }
    };
    /**
     * @brief Sets the parameters of figure.
     * @param size The size of figure.
     * @param coords The coordinates of left top corner.
     */
    virtual void setParams(int size, Dot coords) = 0;
    /**
     * @brief Returns the mask of the figure
     * @param size The size of mask;
     * @return Mask.
     */
    virtual std::vector<std::vector<bool>> getMask(int size) const = 0;
    /**
     * @brief Prints the information about figure(name, size,...)
     */
    void printInfo() const;
    virtual ~Figure() = default;

private:
    std::string m_Name;///The name of figure.
};


#endif //WARTSILA_TEST_FIGURE_H
