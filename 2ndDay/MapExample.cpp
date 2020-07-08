#include "MapExample.h"

MapExample::MapExample()
{
    insertElements();
    printElements();

}

void MapExample::insertElements()
{
    mapOfWords.insert(std::make_pair("earth",1));
    mapOfWords.insert(std::make_pair("moon",2));
    mapOfWords["sun"] = 3; //another insertion

}

void MapExample::printElements()
{
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
        it++;
    }

}

void MapExample::searchElementbyKey()
{
    if(mapOfWords.find("sun") != mapOfWords.end())
        std::cout<<"word 'sun' found."<<std::endl;
    if(mapOfWords.find("mars") == mapOfWords.end())
        std::cout<<"word 'mars' not found."<<std::endl;
}
