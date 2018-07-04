#include "Ncurs.hpp"

Ncurs::Ncurs() : flag(true) {
	for (int i = 0; i < D_WIDTH; i++) {
		arr_cpu[i] = 0;
		arr_ram[i] = 0;
	}
}


Ncurs::Ncurs(bool flag) : flag(flag) {
	for (int i = 0; i < D_WIDTH; i++) {
		arr_cpu[i] = 0;
		arr_ram[i] = 0;
	}
}


Ncurs::~Ncurs() {
}

Ncurs 	&Ncurs::operator=(Ncurs const &src) {
	if (this != & src) {
		for (int i = 0; i < 5; i++)
			_mystring[i] = src._mystring[i];
		for (int i = 0; i < D_WIDTH; i++) {
			arr_cpu[i] = src.arr_cpu[i];
			arr_ram[i] = src.arr_ram[i];
		}
		_win_info = src._win_info;
	}
	return (*this);
}

void	Ncurs::init( void ) {
	IUser 	*user = new User();
	IOS		*os = new OS();
	ICPU 	*cpu = new CPU();

	initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay (stdscr, TRUE);
    start_color();
    _win_info = newwin(40, 50, 0, 5);
    box(_win_info, 0, 0);
    init_pair(1, COLOR_GREEN, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_RED);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);

    wattron(_win_info, COLOR_PAIR(3));
    mvwprintw(_win_info, 1, 3, "        Hostname:     %s", user->getHost());
    mvwprintw(_win_info, 2, 3, "        User:         %s", user->getUser());
    wattroff(_win_info, COLOR_PAIR(3));
    mvwprintw(_win_info, 3, 1, "------------------------------------------------");
    wattron(_win_info, COLOR_PAIR(2));
    mvwprintw(_win_info, 8, 3, "CPU ");
    wattroff(_win_info, COLOR_PAIR(2));
    mvwprintw(_win_info, 13, 1, "------------------------------------------------");
    wattron(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 16, 3, "RAM ");
    wattroff(_win_info, COLOR_PAIR(4));
    mvwprintw(_win_info, 19, 1, "------------------------------------------------");
    wattron(_win_info, COLOR_PAIR(6));
    mvwprintw(_win_info, 20, 3, "                   OS info");
    mvwprintw(_win_info, 21, 3, "        System name:       %s", os->getSysname());
    mvwprintw(_win_info, 22, 3, "        System reales:     %s", os->getRealese());
    mvwprintw(_win_info, 23, 3, "        System machine:    %s", os->getMachine());
    if (flag)
    	mvwprintw(_win_info, 25, 3, "                   Network");
    mvwprintw(_win_info, 29, 3, "                   CPU info");
    mvwprintw(_win_info, 30, 3, "        [%.25s]", cpu->getModel());
    mvwprintw(_win_info, 31, 3, "        Core count:    	%d", cpu->getCore_count());
    mvwprintw(_win_info, 32, 3, "        Clock speed:    	%.1f GHz", static_cast<float>(cpu->getClockSpeed() / 100000000) / 10);
    
    wattroff(_win_info, COLOR_PAIR(6));
    refresh();

    delete(user);
    delete(os);
    delete(cpu);
}

void	Ncurs::run( void ) {
	FILE*	top;
	IRAM 	*obj_ram = new RAM();
	IDate 	*date = new Date();
	INetwork *net = new Network();
	ICPU 	*icpu = new CPU();
	int		cpu = 0;
	int 	ram = 0;

	init();
	wrefresh(_win_info);
	while (getch() != 27) {
		top = popen("top -l 1 | grep \"CPU usage:\" |  cut -d ' ' -f3", "r");
		if (top != NULL) {
    		fgets(_mystring, 5, top);
    		cpu = atof(_mystring);
    		arr_cpu[0] = cpu / 10;
    	}
    	for (int i = D_WIDTH - 1; i > 0; i--) {
    		arr_cpu[i] = arr_cpu[i - 1];
    	}
    	for (int i = 0; i < D_WIDTH; i++) {
    		for (int k = 0; k < 9; k++)
				mvwprintw(_win_info, 12 - k, 44 - i, " ");
			for (int j = 0; j < arr_cpu[i]; j++) {
				wattron(_win_info, COLOR_PAIR(1));
				mvwprintw(_win_info, 12 - j, 44 - i, ".");
				wattroff(_win_info, COLOR_PAIR(1));
			}
		}
		wattron(_win_info, COLOR_PAIR(2));
    	mvwprintw(_win_info, 9, 3, "%d %%", cpu);
    	wattroff(_win_info, COLOR_PAIR(2));

    	ram = (atoi(obj_ram->getRAMUsed()) * 100) / (obj_ram->getRAMSize() / 1000000);
    	arr_ram[0] = ((ram - 50) / 10);
    	for (int i = D_WIDTH - 1; i > 0; i--) {
    		arr_ram[i] = arr_ram[i - 1];
    	}
    	for (int i = 0; i < D_WIDTH; i++) {
    		for (int k = 0; k < 4; k++)
				mvwprintw(_win_info, 18 - k, 44 - i, " ");

			for (int j = 0; j < arr_ram[i]; j++) {
				wattron(_win_info, COLOR_PAIR(5));
				mvwprintw(_win_info, 18 - j, 44 - i, ".");
				wattroff(_win_info, COLOR_PAIR(5));
			}
		}
		wattron(_win_info, COLOR_PAIR(4));
    	mvwprintw(_win_info, 17, 3, "%d %%", ram);
    	wattroff(_win_info, COLOR_PAIR(4));
    	wattron(_win_info, COLOR_PAIR(6));
    	if (flag){
    		mvwprintw(_win_info, 26, 3, "        packets in:  %.11s", net->getPacketsIn());
    		mvwprintw(_win_info, 27, 3, "        packets out: %.9sM", net->getPacketsOut());
    	}
    	mvwprintw(_win_info, 33, 3, "        Processes:    	%s", icpu->getProcessCount());
    	mvwprintw(_win_info, 38, 14, "%s ", date->getDate().c_str());
    	wattroff(_win_info, COLOR_PAIR(6));
    	wrefresh(_win_info);
    	usleep(20000);
    	pclose(top); 
    }
    clear();
    endwin();
}
