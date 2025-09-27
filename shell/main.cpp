#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::cout << "$ ";

  std::string input;

  while (true){
	if (!std::getline(std::cin, input)) {	
		break;
        }

    if (input=="\\q") {
        break;
    }

	if (input.empty()){
		continue;
	}

	std::cout<<input<<std::endl;
  }
  return 0;
}
