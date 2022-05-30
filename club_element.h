//
// Created by valus on 30.05.2022.
//

#ifndef OOP_CLUB_ELEMENT_H
#define OOP_CLUB_ELEMENT_H

#include <ostream>

template<typename T>
class club_element {
    T element;

public:
    //club_element(T element) : element(element) {}
    club_element() {}

    void setElement(T element_) {
        club_element::element = element_;
    }

    friend std::ostream &operator<<(std::ostream &os, const club_element &element_) {
        os << "element: " << element_.element;
        return os;
    }

    T afisClubElement(){
        return element;
    }

    T getElement() const {
        return element;
    }

};


#endif //OOP_CLUB_ELEMENT_H
