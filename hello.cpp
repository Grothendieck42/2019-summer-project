#include<iostream>
#include <variant>
#include <vector>
using namespace std;
int main(){
	std::variant<int, std::vector<int>> p;
	p = std::vector{1, 2};
	if(auto q = std::get_if<int>(&p))
	{
		std::cout << *q << '\n';
	}
	else
	{
		std::cout << "Hello, world!" << '\n';
	}
	return 0;
}
