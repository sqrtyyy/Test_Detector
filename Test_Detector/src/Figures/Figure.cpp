//
// Created by aleksei on 1/31/21.
//

#include "Figure.h"

#include <utility>
#include <iostream>

Figure::Figure(std::string name) : m_Name(std::move(name)) {

}

void Figure::printInfo() const {
    std::cout << m_Name << ' '  << getParams() << std::endl;
}
