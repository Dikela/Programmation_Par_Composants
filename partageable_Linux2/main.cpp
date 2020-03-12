
#include <iostream>
#include <dlfcn.h>
#include "Composant1.h"
#include "Composant2.h"
using namespace std;

int main(int argc, char ** argv)
{
	
	if(argc < 4){
		cout<<"usage: %s <library> <number1> <number2>\n";
		exit(1);
	}

	char *librarypath = argv[1];
	int number1 = atoi(argv[2]);
	int number2= atoi(argv[3]);

	
	void *lib = dlopen(librarypath,  RTLD_LOCAL | RTLD_LAZY);

	if(lib == NULL){
		cerr<<"dlopen: "<<dlerror()<<endl;
		exit(EXIT_FAILURE);
	}

       int (*opfunc)(int, int);

       opfunc = (int (*)(int, int))dlsym(lib, "composant2");

        if(opfunc == NULL){
                cerr<<"dlsym : " << dlerror()<<endl;
                exit(EXIT_FAILURE);

        }

	cout << "getCompo1 --->:" << opfunc(number1, number2) << endl;

	dlclose(lib);
}
