#ifndef NCURS_STATIC_HPP
# define NCURS_STATIC_HPP

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
# include "AnimalModule.hpp"
# include "IAnimalModule.hpp"
# define D_WIDTH 35

class NcursStatic : public IMonitorDisplay {

public:
	NcursStatic();
	virtual ~NcursStatic();
	NcursStatic &operator=(NcursStatic const &src);

	void	run( void );
	void	init( void );

private:
	char 	_mystring[5];
	WINDOW *_win_info;

};

#endif