#include <studio.h>
#include <iostream>
#include "CowApi.hpp"
class CowCount
{
private:
    CowApi *api;
    int fieldSize;
    int cowCount;
    int endfield;
    /* data */
public:
    CowCount(/* args */);
    ~CowCount();
    int getShyCows();
    int getCowsWithNeighbors();
};

CowCount::CowCount(/* args */)
{
    api = new CowApi();
    fieldSize = api->getFieldSize();
    cowCount = api->getNumberOfCows();
    endfield = fieldSize - 1;
}

CowCount::~CowCount()
{
}

CowCount::getShyCows()
{
    int shyCows = 0;

    for (int cowId = 0; cowId < cowCount; cowId++)
    {
        int xAxis = api->getXAxisCowById(cowId);
        int yAxis = api->getYAxisCowById(cowId);

        if ((xAxis == 0 && yAxis == 0) ||
            (xAxis == 0 && yAxis == endfield) ||
            (xAxis == endfield && yAxis == 0) ||
            (xAxis == endfield && yAxis == endfield))
        {
            shyCows++;
        }
    }

    return shyCows;
}

CowCount::getCowsWithNeighbors()
{
    int neighbors;

    for (int fixCowId = 0; fixCowId < cowCount; fixCowId++)
    {
        int fXAxis = api->getXAxisCowById(fixCowId);
        int fYAxis = api->getYAxisCowById(fixCowId);

        for(int cowId = 0; cowId < cowCount; cowId++)
        {
            int xAxis = api->getXAxisCowById(cowId);
            int yAxis = api->getYAxisCowById(cowId);

            if ((xAxis == fXAxis && yAxis == fYAxis + 1) ||
            (xAxis == fXAxis && yAxis == fYAxis - 1) ||
            (xAxis == fXAxis + 1 && yAxis == fYAxis) ||
            (xAxis == fXAxis - 1 && yAxis == fYAxis))
            {
                neighbors++;
                break;
            }
        }
    }
    return neighbors;
}

int main(int argc, char const *argv[])
{
    CowCount *app = new CowCount();
    printf("El valor de las esquinas es: %d", app->getShyCows());
    printf("Las vacas vecinas: %d", app->getCowsWithNeighbors()) return 0;
}
