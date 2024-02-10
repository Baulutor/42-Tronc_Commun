//
// Created by dbaule on 2/8/24.
//

#ifndef NEWSED_HPP
#define NEWSED_HPP

# include <iostream>
# include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;


class	NewSed{
private :
	string	_infile;
	string	_outfile;
public :
	//CONSTRUCTOR AND DESTRUCTOR
	NewSed(string filename);
	~NewSed();

	int replace(string findStr, string replaceStr);
};

#endif
