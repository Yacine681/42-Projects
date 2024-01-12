#include	"../inc/ConfigParse.hpp"
#include	"../inc/ServerManager.hpp"

int main(int n, char *s[])
{
	if(n > 2)
		std::cout<<"you can enter only one argument!"<<std::endl;
	else
	{
		std::string path = "./config/default.config";
		if(n == 2)
			path = s[1];
		try{
			ConfigParse parseFile;
			parseFile.createCluster(path);
			ServerManager	webServer;
			webServer.setupServers(parseFile.getServers());
			webServer.runServers();

		}
		catch(std::exception &e)
		{
			std::cout<<e.what()<<std::endl;
		}
		
	}
	return 1;
}