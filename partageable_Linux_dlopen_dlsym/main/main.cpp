
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


        void *lib = dlopen(librarypath, RTLD_LAZY);
	

        if(lib == NULL){
                cerr<<"dlopen: "<<dlerror()<<endl;
                exit(EXIT_FAILURE);
        }

	

	int (*opfunc1)(int, int);
	opfunc1 = (int (*)(int, int))dlsym(lib, "composant2");
        
	if(opfunc1 == NULL){
		cerr<<"dlsym : " << dlerror()<<endl;
		exit(EXIT_FAILURE);
	}


        /*char* (*opfunc)();
        opfunc = (char* (*)())dlsym(lib, "getComposant1Version");

        if(opfunc == NULL){
                cerr<<"dlsym : " << dlerror()<<endl;
                exit(EXIT_FAILURE);
        }*/

	cout << "Valeur du Composant ---> : " << opfunc1(number1, number2) << endl;
	//cout << "Valeur Composant2 --->:" << opfunc() << endl;

        dlclose(lib);
}
