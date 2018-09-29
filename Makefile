ext2reader: ext2reader.c ext2.c
	gcc ext2reader.c ext2.c -o ext2reader -Wall

clean:
	rm ext2reader
