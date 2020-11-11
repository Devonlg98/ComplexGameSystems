#pragma once

#include <iostream>		// std::cout
#include <fstream>
#include <string>		// std::getline
#include <thread>		//std::thread for all platforms
#include <vector>		//std::vector
#include <mutex>		// std:mutex

class logger
{


public:



	void WriteToLog(std::string i);
	void SaveToDisk();

};