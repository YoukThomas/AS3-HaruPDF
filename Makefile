LIBHARU = ../libharu
HaruPDF = ./A3

CC = g++


sinePDF:  HaruPDF.o Sine.o sinePDF.o $(LIBHARU)/include/hpdf.h

	$(CC) -Wall -o sinePDF -I$(LIBHARU)/include sinePDF.o HaruPDF.o Sine.o -L$(LIBHARU)/src -lhpdfs


Sine.o:  Sine.h Sine.cpp

	$(CC) -Wall -c Sine.h Sine.cpp 


HaruPDF.o: HaruPDF.cpp

	$(CC) -Wall -c -I$(LIBHARU)/include HaruPDF.cpp 


sinePDF.o: sinePDF.cpp HaruPDF.h Sine.h

	$(CC) -Wall -c sinePDF.cpp HaruPDF.h Sine.h


.PHONY: clean


clean:

	rm -f A3 *.o
