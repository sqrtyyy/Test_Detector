#include <iostream>

#include "src/BitImage.h"
#include "src/Figures/Square.h"
#include "src/Figures/Circle.h"
#include "src/Detectors/FigureDetector.h"

#include <clocale>

#define HEIGHT 15
#define WIDTH  15
#define MIN_ACCURACY 0.70

template <typename T>
static int findMax(std::vector<T> container){
    if(container.empty()) return -1;
    int maxElemIdx = 0;
    for (int i = 0; i < container.size(); ++i) {
        if(container[maxElemIdx] <  container[i]) maxElemIdx = i;
    }
    return maxElemIdx;
}

int main(int argc, char** argv) {
    BitImage img(HEIGHT, WIDTH);
    std::setlocale(LC_ALL, "en_US.UTF-8");
    for (int argNum = 1; argNum < argc; ++argNum) {
        std::vector<Figure*> figures = {new Square(), new Circle()};
        std::vector<double> accuracies(figures.size());
        if(img.loadImage(argv[argNum])) {
            FigureDetector detector(&img);
            for (int i = 0; i < figures.size(); ++i) {
                accuracies[i] = detector.detect(figures[i]);
            }
            int figureIdx = findMax(accuracies);
            if(accuracies[figureIdx] > MIN_ACCURACY){
                std::cout << "C точностью: " << accuracies[figureIdx] << std::endl;
                figures[figureIdx]->printInfo();
            } else {
                std::cout << "Non of figures can be found" << std::endl;
            }
            for (const auto &figure : figures) {

            }
        } else {
            std::cout << "Img can't be loaded" << std::endl;
        }
        std::cout << std::endl;
        for (const auto &figure : figures) {
            delete figure;
        }
    }
    return 0;
}
