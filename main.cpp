#include  <iostream>
#include <string>
#include <fstream>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::string history_file=".kubsh_history";
  std::ofstream out(history_file, std::ios::app);
  std::string input;
  std::cout<<"$ ";

  while (std::getline(std::cin,input)){
	if (input=="\\q") {
        break;
    }

    if (input=="history") {
        std::ifstream history_in(history_file);
        std:: string line;
        while (std::getline(history_in,line)) {
            std::cout<<line<<std::endl;
        }
        continue;
    }

    if (input.find("echo ")==0){
        std::cout<<input.substr(5)<<std::endl;
    } 

    else if(!input.empty()){
        std::cout<<input<<std::endl;
    } 

    if (!input.empty()){
        history_out<<input<<std::endl;
    }
  }

  return 0;
}
