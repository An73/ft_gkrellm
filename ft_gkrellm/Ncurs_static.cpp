#include "Ncurs_static.hpp"

NcursStatic::NcursStatic() {
}

NcursStatic::~NcursStatic() {
}

NcursStatic 	&NcursStatic::operator=(NcursStatic const &src) {
	if (this != & src) {
		for (int i = 0; i < 5; i++)
			_mystring[i] = src._mystring[i];
		_win_info = src._win_info;
	}
	return (*this);
}

void	NcursStatic::init( void ) {
	IUser 	*user = new User();
	IOS		*os = new OS();
	ICPU 	*cpu = new CPU();

	initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay (stdscr, TRUE);
    start_color();
    _win_info = newwin(34, 50, 0, 5);
    box(_win_info, 0, 0);
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(5, COLOR_RED, COLOR_RED);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);

    wbkgd(_win_info, COLOR_PAIR(3));
    wattron(_win_info, COLOR_PAIR(3));
    mvwprintw(_win_info, 1, 3, "        Hostname:     %s", user->getHost());
    mvwprintw(_win_info, 2, 3, "        User:         %s", user->getUser());
    mvwprintw(_win_info, 16, 3, "        CPU:");
    mvwprintw(_win_info, 17, 3, "        RAM:");
    wattron(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 3, 1, "          OS info                               ");
    wattroff(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 4, 3, "        System name:       %s", os->getSysname());
    mvwprintw(_win_info, 5, 3, "        System reales:     %s", os->getRealese());
    mvwprintw(_win_info, 6, 3, "        System machine:    %s", os->getMachine());
    wattron(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 7, 1, "          Network                               ");
    wattroff(_win_info, COLOR_PAIR(4));
    wattron(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 10, 1, "          CPU info                              ");
    wattroff(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 11, 3, "        [%.25s]", cpu->getModel());
    mvwprintw(_win_info, 12, 3, "        Core count:    	%d", cpu->getCore_count());
    mvwprintw(_win_info, 13, 3, "        Clock speed:    	%.1f GHz", static_cast<float>(cpu->getClockSpeed() / 100000000) / 10);
    wattron(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 15, 1, "          System load                           ");
    mvwprintw(_win_info, 18, 1, "                                                ");
    wattroff(_win_info, COLOR_PAIR(4));
    wattroff(_win_info, COLOR_PAIR(3));
    refresh();

    delete(user);
    delete(os);
    delete(cpu);
}

void	NcursStatic::run( void ) {
	FILE*	top;
	IRAM 	*obj_ram = new RAM();
	IDate 	*date = new Date();
	INetwork *net = new Network();
	ICPU 	*icpu = new CPU();
    IAnimalModule *animal = new AnimalModule();
	int		cpu = 0;
	int 	ram = 0;

    int     i = 0;

	init();
	wrefresh(_win_info);
	while (getch() != 27) {
		top = popen("top -l 1 | grep \"CPU usage:\" |  cut -d ' ' -f3", "r");
		if (top != NULL) {
    		fgets(_mystring, 5, top);
    		cpu = atof(_mystring);
    	}
        wattron(_win_info, COLOR_PAIR(6));
    	mvwprintw(_win_info, 16, 32, "%d %% ", cpu);
    	ram = (atoi(obj_ram->getRAMUsed()) * 100) / (obj_ram->getRAMSize() / 1000000);
    	mvwprintw(_win_info, 17, 32, "%d %% ", ram);
    	mvwprintw(_win_info, 8, 3, "        packets in:  %.11s", net->getPacketsIn());
    	mvwprintw(_win_info, 9, 3, "        packets out: %.9sM", net->getPacketsOut());
    	mvwprintw(_win_info, 14, 3, "        Processes:    	%s", icpu->getProcessCount());
    	mvwprintw(_win_info, 32, 14, "%s ", date->getDate().c_str());


        for (int j = 0; j < 7; j++) {
            mvwprintw(_win_info, 24 + j, 1, "                                                ");
        }
        if (i == 3)
            i = 0;
        else
            i++;
        for (int j = 0; j < 7; j++) {
            mvwprintw(_win_info, 22 + j, 16, "%s", animal->getPart(i, j));
        }


        wattroff(_win_info, COLOR_PAIR(6));
    	wrefresh(_win_info);
    	usleep(20000);
    	pclose(top); 
    }
    clear();
    endwin();
}