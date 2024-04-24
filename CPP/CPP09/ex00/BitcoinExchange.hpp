//
// Created by dbaule on 4/22/24.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <exception>
# include <vector>
# include <set>
# include <cstdlib>


class BitcoinExchange {
private :
    std::ifstream				_fileDatabase;
    std::ifstream				_fileInput;
    std::vector<std::string>	_dataDatabase;
    std::vector<float>			_valueDatabase;
    BitcoinExchange();
public :
    // Constructor Destructor
    BitcoinExchange(const char* input);
    BitcoinExchange(BitcoinExchange &src);
    BitcoinExchange &operator=(BitcoinExchange &rhs);
    ~BitcoinExchange();

    // Getter and Setter

    // Method

    void    gettingBitcoin();
	bool	parsDate(std::string lineInput);
	bool	parsValue(std::string valueInput);
	bool	parsString(std::string lineInput, bool flag);
	bool	checkValue(std::string lineInput, int *comptPoint, int i);

    // Exception
    class cantOpenDatabase : public std::exception
    {
    public :
        virtual const char  *what() const throw();
    };
    class cantOpenInput : public std::exception
    {
    public :
        virtual const char  *what() const throw();
    };
};

#endif
