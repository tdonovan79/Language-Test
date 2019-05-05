//see whether string is part of the language L={<S><$><R>}
//Thomas Donovan
//4/5/19
#include<iostream>
#include<string>
#include"LinkedStack.h"
#include"Node.h"

void pushToStack(std::string&, LinkedStack<char>&);
bool inLang(std::string, LinkedStack<char>&);

int main(){
	LinkedStack<char> charStack;
	std::string langTest;
	//get string to test if part of language
	std::cout << "Enter string: ";
	std::cin >> langTest;
	//push first half of string to stack
	pushToStack(langTest, charStack);
	//compare first half to second half of string, and output whether or not it is part of the lanuage
	std::cout << (inLang(langTest, charStack) ? "Part of language." : "Not part of Language.");
	
	
	return 0;
}

//push the chars in the first part of string before $ onto the stack
void pushToStack(std::string& langTest, LinkedStack<char>& charStack)
{
	int i = 0;
	//push each char from string onto stack inidividually until char is $
	while(langTest[i] != '$')
	{
		charStack.push(langTest[i]);
		i++;
	};
	//cut off everything up to and including $ from the string and leave the part that may be reversed
	langTest.erase(0, ++i);
}

//check each character in stack against characters left in string, if they don't match return false, if they do return true 
bool inLang(std::string langTest, LinkedStack<char>& charStack)
{
	//if stack is empty, and cut string is not empty string, string only contains $, therefor is true by default
	if(charStack.isEmpty() && langTest.empty())
		return true;
		
	bool flag = true;
	int i = 0;
	while(!charStack.isEmpty() && i < langTest.length())
	{
		
		if(langTest[i] != charStack.peek())
		{
			std::cout << '1';
			return false;
		}
		charStack.pop();
	};
	//if stack is empty and i is not end of string, return false, right side longer than left
	if(i < langTest.length() - 1)
	{
		std::cout << '2';
		return false;
	}
	std::cout<< !charStack.isEmpty();
	//if if stack is not empty and i is at end of string, return false
	if(i == langTest.length() - 1 && !charStack.isEmpty())
	{
		std::cout << '3';
		return false;
}
	std::cout << '4';
	return true;
}




