
#include <iostream>
#include <dlfcn.h>
#include "Composant1.h"
#include "Composant2.h"
using namespace std;

int main(int argc, char ** argv)
{
	
	if(argc < 3){
		std::cout<<"usage: %s <library> <number>\n"<<argv[0];
		exit(1);
	}

	char *librarypath = argv[1];
	int number = atoi(argv[2]);
	
	void *lib = dlopen(librarypath, RTLD_LAZY);

	if(lib == NULL){
		cerr<<"dlopen: "<<dlerror()<<endl;
		exit(EXIT_FAILURE);
	}

        char (*opfunc);

	opfunc = (char*)dlsym(lib, "getComposant1Version");

        if(opfunc == NULL){
                cerr<<"dlsym : " << dlerror() <<endl;
                exit(EXIT_FAILURE);

        }

	cout << "getCompo1 :" << opfunc << endl;
}
