all: contactList install
CFLAGS= -c  -ansi -Wall
contactList: ./src/contacts.o ./src/contacts_func.o 
	gcc -o contactList ./src/contacts.o ./src/contacts_func.o
contacts.o: ./src/contacts.c ./includes/contacts.h 
	gcc $(CFLAGS) ./src/contacts.c -I. includes/
contact_func.o: ./src/contacts_func.c 
	gcc -g ./src/contacts_func.c


clean:
	rm -f ./bin/*.o
	
install: contactList
	@mv ./contactList ./bin/
	@chmod a+x ./bin/contactList
	@chmod og-w ./bin/contactList
	@mv ./src/contacts.o ./src/contacts_func.o ./bin
	@echo "myexe installed successfully in bin/"
        
uninstall:
	@rm -f ./bin/contactList
	@echo "myexe successfully un-installed from /bin/"
