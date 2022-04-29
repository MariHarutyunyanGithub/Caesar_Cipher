/*Write a program that provides a menu for the
user with two options: code, decode. The coding
and decoding should be performed based on the Caesar Cipher
The program should read a normal text from a
text file, code it with the Caesar Cipher 
algorithm and save it in another text file.
The program can also read already coded text 
from a text file, decode it and save it in another text file.*/

#include <fstream>
#include <iostream>
#include <string>

std::string to_code(std::string);
std::string to_decode(std::string);

int main(){
	std::cout << "Please, enter the path of file to read the text.\n";
	std::string text_path;
        std::cin >> text_path;

	std::cout << "Now enter the path of file to write coded text.\n";
	std::string code_path;
        std::cin >> code_path;

	std::cout << "Now enter the path of file to write the decoded text.\n";
        std::string new_path;
        std::cin >> new_path;

	std::ifstream fin;
        fin.open(text_path);
	
        if(!fin.is_open()){
                std::cout << "the file " << text_path << " is not opened" << std::endl;
        }
        else{	
		std::cout << "The file " << text_path << " is opened!\n";
		std::string my_text;
		std::string str;
		while(!fin.eof()){
			std::getline(fin, str);
			my_text += to_code(str);
		}
                fin.close();

		std::ofstream fout;
		fout.open(code_path);

		if (!fout.is_open()){
			std::cout << "the file " << code_path << " is not opened" << std::endl;
		}
		else {
			std::cout << "The file " << code_path << " is opened!\n";
			fout << my_text;
			std::cout << "The coded text has been successfully entered in " << code_path << std::endl;
			fout.close();
		
			fout.open(new_path);
			if(!fout.is_open()){
				std::cout << "the file " << new_path << " is not opened" << std::endl;
                	}
			else{
				std::cout << "the file " << new_path << " is opened" << std::endl;
				std::string decoded_str = to_decode(my_text);
				fout << decoded_str;
				std::cout << "The decoded text has been successfully entered in " << new_path << std::endl;
				fout.close();
			}
		}
		
        }
	return 0;
}


std::string to_code(std::string str)
{
	for (int i{}; i < str.length(); ++i){
		if (str[i] >='3' && str[i] <='9'|| str[i] >='D' && str[i] <= 'Z' || str[i] >= 'd' && str[i] <='z'){
			str[i] -= 3;
		}
		else if (str[i] >='0' && str[i] < '3'){
			str[i] += ('9' - '3' + 1);
		}
		else if (str[i] >='A' && str[i] <='D' || str[i] >= 'a' && str[i] <='d'){
			str[i] += ('Z' - 'D' + 1);
		}
	}
	return str;
}

std::string to_decode(std::string str)
{
	for (int i{}; i < str.length(); ++i){
		if (str[i] >='0' && str[i] <'7'|| str[i] >='A' && str[i] < 'X' || str[i] >= 'a' && str[i] <'x'){
			str[i] += 3;
		}
		else if (str[i] >='7' && str[i] <= '9'){
			str[i] -= ('9' - '3' + 1);
		}
		else if (str[i] >='X' && str[i] < 'Z' || str[i] >= 'x' && str[i] <='z'){
			str[i] -= ('Z' - 'D' + 1);
		}
	}
	return str;
}


