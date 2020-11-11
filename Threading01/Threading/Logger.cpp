#include "logger.h"

void logger::WriteToLog(std::string i)
{
	static std::mutex myMutex;
	std::ofstream myfile;
	if (!(myfile.is_open()))
	{
		myfile.open("GenericTextFile.txt");
	}

	myMutex.lock();
	myfile << i << std::endl;
	myMutex.unlock();

}

void logger::SaveToDisk()
{


}
