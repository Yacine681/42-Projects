#include <exception>
#include <iostream>
#include <string>
#include <limits>
#include <climits>

void	print_msg(int n, const std::string ms, const std::string title)
{
	std::string tmp;
	tmp.append("<!DOCTYPE html>\n");
	tmp.append("<html>\n");
	tmp.append("<head>\n");
	tmp.append("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/my_styles.css\">\n");
	tmp.append("</head>\n");
	tmp.append("<body>\n");
	tmp.append("<div class=\"center-container\">\n");
	tmp.append("<h1>\n");
	tmp.append(title);
	tmp.append("\n");
	tmp.append("</h1>\n");
	tmp.append("<p>\n");
	if(n > 300)
	{
		tmp.append("Error");
		tmp.append("<br>");
	}
	tmp.append(ms);
	tmp.append("\n");
	tmp.append("</p>\n");
	tmp.append("<h3>\n");
	tmp.append("<a href=\"index.html\">");
	tmp.append("home page");
	tmp.append("</a");
	tmp.append("\n");
	tmp.append("</h3>\n");
	tmp.append("</div>\n");
	tmp.append("</body>\n");
	tmp.append("</html>\n");
	std::cout<<tmp<<std::endl;
}

int checkNumber(std::string number)
{
	if (number.empty())
	{
		std::cout << "500" << std::endl;
		print_msg(500, "input  empty!", "cpp calculator");
		// std::cout << "number empty!" << std::endl;
		exit(0);
	}

	for(int i=number.size() - 1;i>=0;i--)
	{
		if (!std::isdigit(number[i]))
		{
			std::cout << "500" << std::endl;
			print_msg(500, "input  is not number!", "cpp calculator");
			// std::cout << "is not number!" << std::endl;
			exit(0);
		}
	}
  return (std::stoi(number));
}

void calculator(char *str1)
{
	std::string str(str1);

	size_t pos1 = 0;
	size_t pos2 = 0;

	int f_number = 0;
	int s_number = 0;
	int result = 0;
	char op;
	
	pos1 = str.find_first_of("&") - 1;
	pos2 = str.find_first_of("=") + 1;
	
	std::string findNumber = str.substr(pos2, pos1 - pos2 + 1);
	try {
		f_number = checkNumber(findNumber);
 	} catch (const std::exception& ex) {
		// std::cout << "500\n" << ex.what() << std::endl;
		std::cout << "500\n";
		print_msg(500, "Error Exception!", "cpp calculator");
    exit(0);
 	}

	pos2 = str.find_last_of("=") + 1;

	findNumber = str.substr(pos2);
	try {
		s_number = checkNumber(findNumber);
 	} catch (const std::exception& ex) {
		// std::cout << "500\n" << ex.what() << std::endl;
		std::cout << "500\n";
		print_msg(500, "Exception Error!", "cpp calculator");
 	}

	pos2 = str.find_last_of("&") - 1;
	op = str[pos2];

  try
  {
		if (op == '+') {
			result = f_number + s_number;
		} else if (op == '-') {
			result = f_number - s_number;
		} else if (op == '*') {
			result = f_number * s_number;
		} else if (op == '/') {
			if (s_number == 0)
				throw std::exception();
			result = f_number / s_number;
		} else if (op == '%') {
			result = f_number % s_number;
		} else {
			// std::cout << "not a operator!" << std::endl;
			std::cout << "500\n";
			print_msg(500, "not a operator!", "cpp calculator");
			exit(0);
		}
		std::cout <<"200\n";
		print_msg(200, std::to_string(f_number) + op +  std::to_string(s_number) + " = " + std::to_string(result), "cpp calculator");
		// std::cout << f_number << " " << op << " " << s_number << " = " << result << std::endl;
  }
  catch(std::exception &e)
  {
		std::cout << "500\n";
		print_msg(500, "Error exception!", "cpp calculator");
		exit(0);

  }

}


int main(int argc, char **argv)
{
	// char op[] = "f_number=89&operation=*&s_number=34";
	try{
		calculator(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout << "500\n";
		print_msg(500, "Exception Error!", "cpp calculator");
		exit(0);
	}
	return 0;
}
