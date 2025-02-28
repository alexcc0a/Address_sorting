//
//  main.cpp
//  Address_sorting
//
//  Created by Александр Нестеров on 7/29/24.
//

#include <iostream>
#include <fstream>
#include <string>

class Address {
public:
    Address() {}
    Address(std::string city, std::string street, int house_number, int apartment_number) {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->apartment_number = apartment_number;
    }

    Address(const Address& other) {
        city = other.city;
        street = other.street;
        house_number = other.house_number;
        apartment_number = other.apartment_number;
    }

    std::string get_city() const {
        return city;
    }

    void init_ad(std::string city, std::string street, int house_number, int apartment_number) {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->apartment_number = apartment_number;
    }
    std::string ad() const {
        return city + ", " + street + ", " + std::to_string(house_number) + ", " + std::to_string(apartment_number);
    }

private:
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;
};

void sort(Address* ad, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1; j++) {
            if (ad[j + 1].get_city() < ad[j].get_city()) {
                Address temp(ad[j]);
                ad[j] = Address(ad[j + 1]);
                ad[j + 1] = temp;
            } else {
                continue;
            }
        }
    }
}

int main() {

    std::ifstream file("in.txt");
    std::ofstream File("out.txt");

    setlocale(LC_ALL, "Russian");
    int num;
    file >> num;
    File << num << std::endl;

    Address* ad = new Address[num];

    std::string city;
    std::string street;
    int house_number;
    int apartment_number;

    for (int j = 0; j < num; j++) {
        file >> city;
        file >> street;
        file >> house_number;
        file >> apartment_number;
        ad[j].init_ad(city, street, house_number, apartment_number);
    }

    sort(ad, num);

    for (int j = 0; j < num; j++) {
        File << ad[j].ad() << std::endl;
    }

    delete[] ad;
}
