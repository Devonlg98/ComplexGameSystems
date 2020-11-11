// Threading 00 basic example from Terry

#include <iostream>
#include <chrono>
#include <thread>
// Mutex
// Lockmguard

void debugPrint()
{
	std::cout << "Debug" << std::endl;
}

bool isReleased = false;

void printForever()
{
	while (!isReleased)
	{
		std::cout << "Infinite days until HL3 comes out" << std::endl;
	}
	std::cout << "Hl3 is cancelled again" << std::endl;
}

// Main thread - this is the thread containing the original thread of execution
int main()
{
	std::cout << "hello world" << std::endl;

	// Defer this to another thread
	//std::thread debugThread(debugPrint);
	std::thread debugThread(printForever);

	std::this_thread::sleep_for(std::chrono::seconds(5));

	isReleased = true;

	// Wait for this thread to terminate before continuing
	debugThread.join();
	std::cout << "MAIN THREAD COMPLETED" << std::endl;

}