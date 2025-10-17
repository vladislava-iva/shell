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
        std::string line;
        while (std::getline(history_in,line)) {
            std::cout<<line<<std::endl;
        }
        continue;
    }

    if (input.find("echo ")==0){
        std::cout<<input.substr(5)<<std::endl;
    } 

    if (input.find("\\e $")==0){
        const char* val=std::getenv(input.substr(4).c_str());
        if (val) {
            std::string s=val;
            for (int i=0;i<s.length();i++){
                if (s[i]==":") std::cout<<std::endl;
                else std::cout<<s[i];
            }
            std::cout<<std::endl;
            
        }
    }

    else if(!input.empty()){
        std::cout<<"Error: "<<input<<" is unknown command"<<std::endl;
    } 

    if (!input.empty()){
        out<<input<<std::endl;
    }

    
  }

  return 0;
}
