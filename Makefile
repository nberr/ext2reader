program_4: program4.c ext2.c
	gcc program4.c ext2.c -o ext2reader -Wall

clean:
	rm ext2reader
