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
    club_element();

    void setElement(const T& element_);

    T afisClubElement();

    T getElement() const;

};

template<typename T>
void club_element<T>::setElement(const T &element_) {
    club_element::element = element_;
}

template<typename T>
T club_element<T>::getElement() const {
    return element;
}

template<typename T>
T club_element<T>::afisClubElement() {
    return element;
}

template<typename T>
club_element<T>::club_element() {}

#endif //OOP_CLUB_ELEMENT_H
