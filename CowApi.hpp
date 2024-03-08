#include <studio.h>
#include <iostream>
#include <vector>

struct
{
    int x;
    int y;
    /* data */
} Cow;


class CowApi
{
private:
    std::vector<Cow*> cowList;
    int fieldSize;
public:
    CowApi(/* args */);
    int getNumberOfCows(){return this->cowList.size();};
    int getFieldSize(){return fieldSize;};
    int getXAxisCowById(int id);
    int getYAxisCowById(int id);
    ~CowApi();
};

CowApi::CowApi(/* args */)
{
    cowList.insert(Cow{0,0});
    cowList.insert(Cow{0,1});
}

CowApi::~CowApi()
{
}

CowApi::getXAxisCowById(int id)
{
    return this->cowList[id].x;
}

CowApi::getYAxisCowById(int id)
{
    return this->cowList[id].y;
}

