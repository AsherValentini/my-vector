#include <iostream>
#include <cassert>
#include "vector.hpp"


inline std::ostream& operator<<(std::ostream& os, const asher::vector<int>& v) {
    for(int i=0; i < v.size(); ++i) {
        if(i == v.size()-1) {
            os << v[i];
        }else {
            os << v[i] << " ";
        }
    }

    return os;
}

inline void printData (const asher::vector<int>& v) {
    std::cout << "Data: " << v << " \n"
              << "Data Address: " << v.dataAddr() << "\n"
              << "Vector Size: " << v.size() << "\n"
              << "Vector Capacity: " << v.capacity() << "\n";
}

int main() {
	asher::vector<int> myVector;

    myVector.push_back(1);
    printData(myVector);
    myVector.push_back(2);
    printData(myVector);
    myVector.shrink_to_fit();
    printData(myVector);
    std::cout << "EOP \n";

    return 0;
}

