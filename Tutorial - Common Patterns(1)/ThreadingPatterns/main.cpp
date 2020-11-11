#include "SingleThreadedApplication.h"
#include "multithreaded_application.h"

int main()
{
    //SingleThreadedApplication app;
    multithreaded_application app;
    

    while (true)
    {

        app.Tick();
    }

    return 0;
}


