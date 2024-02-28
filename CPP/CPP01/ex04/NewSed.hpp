//
// Created by dbaule on 2/8/24.
//

#ifndef NEWSED_HPP
#define NEWSED_HPP

# include <iostream>
# include <fstream>

class	NewSed{
private :
	std::string	_infile;
	std::string	_outfile;
public :
	//CONSTRUCTOR AND DESTRUCTOR
	NewSed(std::string filename);
	~NewSed();

	int replace(std::string findStr, std::string replaceStr);
};

#endif
