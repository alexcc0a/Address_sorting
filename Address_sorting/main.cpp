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
    void new_city(std::string city) {
        this->city = city;
    }
    std::string get_city() {
        return city;
    }
    void init_ad(std::string city, std::string street, int home_number, int apartment_number) {
        this->city = city;
        this->street = street;
        this->home_number = home_number;
        this->apartment_number = apartment_number;
    }
    std::string ad() {
        return city + ", " + street + ", " + std::to_string(home_number) + ", " + std::to_string(apartment_number);
    }
private:
    std::string city;
    std::string street;
    int home_number;
    int apartment_number;
};

void sort(Address* ad, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num -1; j++) {
            if (ad[j + 1].get_city() < ad[j].get_city()) {
                std::string str;
                str = ad[j].get_city();
                ad[j].new_city(ad[j + 1].get_city());
                ad[j + 1].new_city(str);
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
  Address address;
  Address* ad = new Address[num];

  std::string city;
  std::string street;
  int home_number;
  int apartment_number;

  for (int j = 0; j < num; j++) {
    file >> city;
    file >> street;
    file >> home_number;
    file >> apartment_number;
    ad[j].init_ad(city, street, home_number, apartment_number);

  }

  sort(ad, num);

  for (int j = 0; j < num; j++) {

    File << ad[j].ad() << std::endl;

  }

  delete[] ad;
}
