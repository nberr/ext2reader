#include <stdio.h>
#include <stdlib.h>

#include "ext2.h"
extern FILE *fp;

//the block argument is in terms of SD card 512 byte sectors
void read_data(uint32_t block, uint16_t offset, uint8_t* data, uint16_t size) {

   if (offset >= MAX_OFFSET) {
      printf ("Offset greater than 511.\n");
      exit(0);
   }
   
   fseek(fp,block*MAX_OFFSET + offset,SEEK_SET);
   fread(data,size,1,fp);
}

