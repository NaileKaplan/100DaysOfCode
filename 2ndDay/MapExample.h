#ifndef MAPEXAMPLE_H
#define MAPEXAMPLE_H

#include <iostream>
#include <map>
#include <string>
#include <iterator>

class MapExample
{
public:
    MapExample();
    void insertElements();
    void printElements();
    void searchElementbyKey();    //Searching element by key

private:
    std::map<std::string, int> mapOfWords;

};

#endif // MAPEXAMPLE_H
