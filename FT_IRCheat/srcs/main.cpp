#include "Clients.hpp"
#include "Server.hpp"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "ERROR arg" << std::endl;
        return -1;
    }
	Server server;
	try
	{
		server.launch(argv[1], argv[2]);
	}
	catch (std::exception &e)
	{
		std::vector<pollfd> buf = server.getLstPollFd();
		for (size_t i = 0; i < buf.size(); i++)
			close(buf[i].fd);
		std::cerr << e.what() << std::endl;
		return (1);
	}
    return 0;
}

