#ifndef NCURS_HPP
# define NCURS_HPP

# include <ncurses.h>
# include <iostream>
# include <zconf.h>
# include "IUser.hpp"
# include "User.hpp"
# include "RAM.hpp"
# include "CPU.hpp"
# include "DateTime.hpp"
# include "OS.hpp"
# include "IOS.hpp"
# include "Network.hpp"
# include "INetwork.hpp"
# include "IMonitorDisplay.hpp"
# define D_WIDTH 35

class Ncurs : public IMonitorDisplay {

public:
	Ncurs();
	Ncurs(bool flag);
	virtual ~Ncurs();
	Ncurs &operator=(Ncurs const &src);

	void	run( void );
	void	init( void );
	int		arr_cpu[D_WIDTH];
	int		arr_ram[D_WIDTH];

private:
	bool	flag;
	char 	_mystring[5];
	WINDOW *_win_info;

};

#endif
