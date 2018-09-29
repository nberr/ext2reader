#ifndef PROGRAM4_H
#define PROGRAM4_H

#include "ext2.h"

#define MAX_ARGS 4
#define MIN_ARGS 2

#define MODE_MASK 0xF000

#define ROOT_PATH "/"
#define PERMS "r"

#define NAME_SEP 20

#define FORMAT_HEADER "name                    size     type\n"

#define BASE_BLOCKS 10
#define BLOCK_SIZE 1024
#define ADDR_PER_BLOCK 255

void print_usage(void);
void find_inode(inode *data, uint32_t inode_number);
void print_dir(inode data);
void print_reg(inode data);
void traverse(inode *data, char *path);
void print_name(char *name, uint16_t name_len);
void print_meta_data(inode meta);

#endif

