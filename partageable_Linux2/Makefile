
test.exe: main.cpp libComposant1.so libComposant2.so
	g++ -o text.exe main.cpp -ldl

libComposant1.so: Composant1.cpp Composant1Version.h Composant1.h
	g++ -fPIC -shared -o libComposant1.so Composant1.cpp
	
libComposant2.so: Composant2.cpp Composant2.h
	g++ -fPIC -shared -o libComposant2.so Composant2.cpp

clean:
	rm -f test.exe libComposant1.so libComposant2.so 
