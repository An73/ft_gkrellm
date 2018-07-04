#include <iostream>
#include "IMonitorDisplay.hpp"
#include "Ncurs_static.hpp"
#include "Ncurs.hpp"

int main(int argc, char **argv){
    IMonitorDisplay *display = NULL;
    std::string flag[2] = {"-t", "-n"};
    if (argc == 2){
        if (!flag[0].compare(argv[1]))
            display = new NcursStatic();
        else if (!flag[1].compare(argv[1]))
        	display = new Ncurs(false);
        else
        {
        	std::cout << "usage: ft_gkrellm [] - graphical UI | [-t] - shell UI | [-n] - disable network info" << std::endl;
        	return 0;
    	}
    }
    else if (argc == 1)
        display = new Ncurs();
    else
    {
        std::cout << "usage: ft_gkrellm [] - graphical UI | [-t] - shell UI | [-n] - disable network info" << std::endl;
        return 0;
    }
    display->run();
    return 0;
}
