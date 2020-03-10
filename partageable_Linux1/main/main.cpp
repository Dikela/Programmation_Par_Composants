
#include <iostream>
#include <dlfcn.h>
#include "Composant1.h"
#include "Composant2.h"
using namespace std;

int main(int argc, char ** argv)
{
	
	/*if(argc < 3){
		std::cout<<"usage: %s <library> <number>\n"<<argv[0];
		exit(1);
	}*/

	//char *librarypath = argv[1];
	//int number = atoi(argv[2]);
	
	void *lib ;
       	lib = dlopen("./lib/libComposant1.so", RTLD_LAZY);
	if(lib == NULL){
		cerr<<"dlopen: "<<dlerror()<<endl;
		exit(EXIT_FAILURE);
	}

	void *opfunc;
	 opfunc = dlsym(lib, "getComposant1Version");

	if(opfunc == NULL){
		cerr<<"dlsym : " << dlerror() <<endl;
		exit(EXIT_FAILURE);

	}
	
        int data1=3;
        int data2=5;

        int valeur1;
        int valeur2;

        valeur1=composant1(data1,data2);

        valeur2=composant2(data1,data2);
	
	//std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
}
