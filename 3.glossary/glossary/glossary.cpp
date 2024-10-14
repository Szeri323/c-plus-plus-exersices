#include "../../../headers/std_lib_facilities.h"

int main() {
	// This is the technical words glossary.
	
	cout << "\n\n--- Chapter 3 - Objects, Types and Values --- \n\n";

	cout << "// - one line comment.\n";
	cout << "<< - output stream direction operator.\n";
	cout << "library - set of statments for reuse.\n";
	cout << "Compilation Error - is an error that can occur at the compliation stage. When the source code is translated into object code, it must meet certain some requirements, such as constexpr must be defined by a literal, which means constexpr must be known before compilation.\n";
	cout << "C++ - superset of C, based on simula, high-level language, created by Bjarne Stroustrup in 1985.\n";
	cout << "cout - shorten of stream control output. This statement is instance of ostream class.\n";
	cout << "output data - data exiting the program.\n";
	cout << "function - a statment for computer. It contains type, function name, parameters and definition.\n";
	cout << "IDE - interactive or integrated developement envirement. It contains all nessecary tools for developer to produce a program.\n";
	cout << "#include - a derective that informs copiler which header files add and where it can find them.\n";
	cout << "instruction/stetment - single command for computer.\n";
	cout << "Object code - a code generated from source code. It is hard to understand for humans but easy to understand for computers. It doesn't contain comments.\n";
	cout << "Source code - contains sets of instructions like functions writen in way that is understable for humans and can contain comments. From this type of code compiler create object code.\n";
	cout << "comment - a string that is ignored by compiler. One line comment start with // and multilines comment starts with /* and ends with */\n";
	cout << "compilator - a program that compiles source code to object code. In other words it takes files that ends with .cpp, .h and transle them to low level machine code without comments.\n";
	cout << "linker - a program that takes object codes and link them togeter in one executible program.\n";
	cout << "main() - a fragment of function definition.\n";
	cout << "header - contains definitions and sets of functions.\n";
	cout << "program - set of instructions what computer has to do and how it can do it.\n";
	cout << "executible - last stage of production. It is finished sorce code, compiled (translated to object code) and linked (all necesery object files connected in one executible file), that we can run on our computer.\n";
	
	cout << "\n\n--- Chapter 4 - Performing calculations ---\n\n";

	cout << "abstraction - is a situation where the way a computer works and the problems it solves are brought closer to human thinking rather than machine code. For example, programming languages are designed to be more familiar to human language, making them less about zeros and ones and more about expressing concepts in a way humans understand.\n";
	cout << "begin() - it is a vector class methos, that returns the iterator points to first element of vector.\n";
	cout << "input data - information passing through specific devices like keyboard or files to computer.\n";
	cout << "output data - information generated by computer and providing to user or program in many ways like printing on a screen.\n";
	cout << "definition - is full function with declaration and body. It looks like this: type name(paramiters) { instructions }.\n";
	cout << "declaration - defining a signature of the function: type of returned value, name, paramiters (and their types) of the function.\n";
	cout << "divide and conquer - says that the problem should be devided to smaller pices that makes it easier to solve.\n";
	cout << "else - one of three instruction from if statment. That says if if and else if are not true then do what is declared in else statment. It is optional.\n";
	cout << "end() - one of two vector methods. It returns iterator points to last element of the vector.\n";
	cout << "function - named and organized set of inctructions it can takes arguments and return values.\n";
	cout << "member function(component function) - is function declared in a class and process its data.\n";
	cout << "incrementation - it is instruction which raise up a value by one.\n";
	cout << "instruction - one command for computers processor.\n";
	cout << "for instruction - allows execute block of code a specified number of times, with option of initializing, conditional and updating a control variable.\n";
	cout << "if instruction - allows make decision depending on the result (true or false) of some condition.\n";
	cout << "switch instruction - other variant of if. It allows from single char, numbers values and enums in condition.\n";
	cout << "while instruction - other variant of for instruction. It works till the condition is true. It doesn't contain initialization or actualization.\n";
	cout << "iteration - it is one cicle of the loop.\n";
	cout << "l-value - left side of the expression, e.g. int a = 2, where 'int a' is left value of the expression.\n";
	cout << "loop - instruction that reapet the instructions written in definiton of the loop.\n";
	cout << "repetition - do something one more time.\n";
	cout << "processing - executing some insctrucions or calculating something.\n";
	cout << "push_back() - it is a class method. It could be defined by programer, but in default (cin.put_back(c)) it puts a c value back into a cin stream.\n";
	cout << "r-value - right side of the expression.\n";
	cout << "selection - choosing one of many alteratives.\n";
	cout << "size() - vector class method that return count of the elements in a structure.\n";
	cout << "sort() - vector method that takes two iterators (some_name.begin(), some_name.end()) and return a sorted structure.\n";
	cout << "vector - specific dynamic structure similiar to the array, but with dynamic allocation of memmory, so we can add elements even if vector is 'full'.\n";
	cout << "expression - it is component that we can use in instructions, e.g. 1 + 2  is expression.\n";
	cout << "ranged for instruction - it is special tape of for loop. Its task is to go through every element in a structure, from begining to end. We cant specifia number of iterations in this type of loop.\n";

	cout << "\n\n--- Chapter 5 - Errors ---\n\n";

	cout << "assertion - we check if the value passed by us is the same as the value returned by the program.\n";
	cout << "error - a situation in our program when something goes differently than expected.\n";
	cout << "runtime error - this type of error occurs when the program is compiled, linked and ranning (during the execution stage).\n";
	cout << "compilation error - this type of error occures when source code is translated in to object code.\n";
	cout << "linker (consolidation) error - occurs when the linker tries to find object files to link into the executable program but cannot find some of them.\n";
	cout << "sytax error - occurs when the code does not follow the rules of the langage, e.g. typos or non-existent type names.\n";
	cout << "type error - occurs when a variable or function has no type, or the type of a declared function is incompatible with the type when the function is called. It also occurs when the number of parameters or their types are incompatible with the function declaration.\n";
	cout << "scope (range) error - occurs when we try to refer to a variable or function that does not exist in the current scope. A common occurrence is when, in another part of the program, we try to refer to a counter that was mistakenly defined inside a for loop.\n";
	cout << "argument error - in C++, predefined exceptions are used for error handling. We can careat our own exception taht takes a string argument to describe the error.\n";
	cout << "catch - an instruction associated with the try instruction. If any error (exception) occurs in the try block, catch will handle the situation. We can print what happened, clean up the mess and bring the program back to normal state.\n";
	cout << "debug - the process of running code and executing instructions one after another in a specific mode with additional monitoring.\n";
	cout << "container - data collection like vector or array.\n";
	cout << "invariant - intializer that allows defining only varaibles in specific way. It ensuers a value of variable always be correct.\n";
	cout << "testing - checks whether a program or instruction behaves according to our assumptions.\n";
	cout << "throw - a statement that stops program execution and tries looks for the nearest catch block to pass on the error with additional information, if defined.\n";
	cout << "pre-condition - a function test its arguments before executing the statement.\n";
	cout << "post-condition - a test placed after a function statement to ensure that return value is correct and meets the assumptions.\n";
	cout << "exception - a general type of error that we can catch and handle.\n";
	cout << "requirement - an expectation that needs to be fulfilled for the program or statement to run successfully.\n";

	cout << "\n\n--- Chapter 6 - Writing a program ---\n\n";
	
	cout << "analysis - is universal process that can be performed at all stages of software life. It is the observation of data or behavior and its comparison with our assumptions.\n";
	cout << "syntax analizer (parser) - (@@@@@CHECK THIS DEFINITION@@@@@) is a program that takes some input and divide it using grammar. \n";
	cout << "class - is a structure that contains constructor and destructor (or many of them), fields and methods. Class can have access specifiers such as public, protected or private. It helps to structure and manage the data.\n";
	cout << "dividing by zero - is an unforgivable mistake that needs to be handle in any better program.\n";
	cout << "member function - is another name for class method. It is function that is defined in body of the class.\n";
	cout << "grammar - (@@@@@CHECK THIS DEFINITION@@@@@) set of rules defining much complex structures.\n";
	cout << "implementation - \n";
	cout << "interface - (@@@@@CHECK THIS DEFINITION@@@@@) is a way that define comunication or way of usage between programs or theirs components.\n";
	cout << "parser - \n";
	cout << "private - one of three access modifiers. Makes members of a class accessible only for other mebers of the same class.\n";
	cout << "project - (@@@@@CHECK THIS DEFINITION@@@@@)set of rules and tools that help write, compile and link code in more effective way.\n";
	cout << "prototype - (@@@@@CHECK THIS DEFINITION@@@@@)first and very simple version of project or source code. It's goal is to present main concept and verify if our understanding of problem cover client needs or if our assumptions are right.\n";
	cout << "use case - (@@@@@CHECK THIS DEFINITION@@@@@)is single way of usage our program that can \n";
	cout << "pseudocode - (@@@@@CHECK THIS DEFINITION@@@@@)it is simplified way of presentation our thoughs that contains both code and human interpretation elements. Desciptions of algorytms are presened by pseudo code.\n";
	cout << "public - (@@@@@CHECK THIS DEFINITION@@@@@)one of three class access specifiers.\n";
	cout << "class member - (@@@@@CHECK THIS DEFINITION@@@@@)is an entity that belongs to a class.\n";
	cout << "token - (@@@@@CHECK THIS DEFINITION@@@@@)small peace of data that can be taken from input stream and interpreted.\n";
	cout << "class data member - another name of field of class. It is variable inside of a class.\n";

	cout << "\n\n--- Chapter 7 - Finishing a program ---\n\n";
	
	cout << "version history - list of changes (when and what was changed) in project.\n";
	cout << "commenting - Using // sign for pass some additional informations or conclusions, pass some our assmptions of program work or quick way to temporary disable some code.\n";
	cout << "fuctions multiplication - \n";
	cout << "errors handling - tring executing part of code and been ready to handle an error when occur. It is done by try, catch statements.\n";
	cout << "recovery - bringing back the program to a previous working state.\n";
	cout << "symbolic constant - It is a value that does not change during the execution of program.\n";
	cout << "backbone - small pice of source code, that need to work and simply make job well. Writen in first stage of coding or for prototyping.\n";
	cout << "testing - using if statement to check if value is correct and meet conditions.\n";
	cout << "code aligment - way of using whitespaces (spaces or tabs) to improve clearity of code. It helps in better code organizations and makes finding bugs easier.\n";
	cout << "code maintenance - making our code better. We can make it by keeping our code, clear, organized, universal and simplied.\n";

	cout << "\n\n--- Chapter 8 - Technical ditails - fuctions, references and namespaces ---\n\n";

	cout << "argument - parameter passed to the function when it is called.\n";
	cout << "nesting block - when we write code using curly bracket {} signs and then next code in them and so on. It becomes when we write loops in loops or condition and condition activated only if this previous is fulfiled.\n";
	cout << "const - statemant that declare inmutable values in our program.\n";
	cout << "constexpr - statement that be initialized on a compilation proces and can contain only literals.\n";
	cout << "definition - content between curly brackets e. g. body of a function.\n";
	cout << "definition of the funciton - are insctructions inside the function between curly brackets.\n";
	cout << "declaration - contains a type and name of variable or type name and paramiters of function without definition.\n";
	cout << "using declaration - when we need use function which is defined under the caller function we can 'use definition' higher in our code. By using it we say we want use this function but we define it later in code.\n";
	cout << "advance declaration - \n";
	cout << "using directive - \n";
	cout << "extern - \n";
	cout << "function - \n";
	cout << "initializer - \n";
	cout << "namespace - \n";
	cout << "undeclared identifier - \n";
	cout << "header file - \n";
	cout << "passing on arguments - \n";
	cout << "passing by reference - \n";
	cout << "passing by const reference - \n";
	cout << "passing by value - \n";
	cout << "activation record - \n";
	cout << "recursion - \n";
	cout << "return - \n";
	cout << "call stack - \n";
	cout << "Technical details - \n";
	cout << "returning value - \n";
	cout << "range - \n";
	cout << "global range - \n";
	cout << "instruction range - \n";
	cout << "class range - \n";
	cout << "local range - \n";
	cout << "namespace range - \n";

	return 0;
}