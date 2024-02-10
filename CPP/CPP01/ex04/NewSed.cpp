//
// Created by dbaule on 2/10/24.
//

#include "NewSed.hpp"

NewSed::NewSed(std::string filename)  : _infile(filename)
{
	this->_outfile = this->_infile + ".replace";
}

NewSed::~NewSed()
{

}

int	NewSed::replace(string findStr, string replaceStr)
{
	std::ifstream file(this->_infile.c_str());
	string	buf;

	if (!file)
		return(cout << "Cannot find file or no right to open it" << endl, 1);

	if (!getline(file, buf, '\0'))
		return (cout << "the infile given is empty, cannot continue" << endl, file.close(), 1);

	std::ofstream newFile(this->_outfile.c_str());
	if (!newFile)
		return (cout << "Not allowed to open this file '" << this->_outfile << "'" << endl, 1);
	size_t pos;
	while ((pos = buf.find(findStr)) != std::string::npos)
	{
		buf.erase(pos, findStr.length());
		buf.insert(pos, replaceStr);
	}
	newFile << buf;
	newFile.close();
	return (0);
}
