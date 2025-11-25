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
    auto addr = v.dataAddr();
    std::cout << "Data: " << v << " \n";

    if(addr.has_value()){
        std::cout << "Data Address: " << *addr << "\n";
    } else {
        std::cout << "Data Address: " << "No data in container" << "\n";
    }
    std::cout << "Vector Size: " << v.size() << "\n"
              << "Vector Capacity: " << v.capacity() << "\n";
}

int main() {
	asher::vector<int> myVector;

	std::cout << "Push Back 1=============================================================\n";
	myVector.push_back(1);
    printData(myVector);
	std::cout << "Push Back 2=============================================================\n";
	myVector.push_back(2);
	printData(myVector);
	std::cout << "Push Back 3=============================================================\n";
	myVector.push_back(3);
    printData(myVector);
	std::cout << "Pop Back  =============================================================\n";
	myVector.pop_back();
	printData(myVector);
    myVector.pop_back();
	printData(myVector);
	myVector.pop_back();
	printData(myVector);

    return 0;
}

