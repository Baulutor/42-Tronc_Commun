

#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
    if (argc < 2)
        return (std::cout << "Please put only one argument, which is the database that you want to use" << std::endl, 1);
    try
    {
        BitcoinExchange test(argv[1]);

        test.gettingBitcoin();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}