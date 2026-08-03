#pragma once

#include <iostream>
#include <string>

class Country{
private:
    std::string name;

public:
    Country(std::string countryName);
    virtual ~Country() = default;

    virtual void printInfo() const;

};