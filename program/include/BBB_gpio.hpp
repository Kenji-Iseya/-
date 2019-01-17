#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <exception>
#include <algorithm>

#include<BBB_error.hpp>

namespace BBB{

class GPIO
{
  public:
    GPIO() {}
    GPIO(int gpioNum_);

    void setGPIO(int gpioNum_) { *this = GPIO(gpioNum_); };
    //inならtrue、outならfalse

	enum Direction { IN, OUT };
    void setDirection(bool is_IN);
	void setDirection(Direction d);

    void setEdge(bool isBoth);
    void setActiveLow();

	void activate();
	void disActivate();

    void setValue(bool isActive);
    int value();

    int GPIOnum() { return gpioNum; }


    static std::vector<int> const availableGpioNum;

    ~GPIO();

  protected:
    int gpioNum;
    bool isGPIOSetted;

};
};




