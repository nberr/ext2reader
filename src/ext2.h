/*
 * Copyright (C) 1992, 1993, 1994, 1995
 * Remy Card (card@masi.ibp.fr)
 * Laboratoire MASI - Institut Blaise Pascal
 * Universite Pierre et Marie Curie (Paris VI)
 *
 *  from
 *
 *  linux/include/linux/minix_fs.h
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */

#ifndef EXT2_H
#define EXT2_H

#define MAX_OFFSET 512

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

/*
 * Special inode numbers
 */
#define EXT2_ROOT_INO		 2	/* Root inode */

/* First non-reserved inode for old ext2 filesystems */
#define EXT2_GOOD_OLD_FIRST_INO	11

/*
 * Structure of a blocks group descriptor
 */
typedef struct ext2_group_desc
{
   uint32_t	bg_block_bitmap;	/* Blocks bitmap block */
   uint32_t	bg_inode_bitmap;	/* Inodes bitmap block */
   uint32_t	bg_inode_table;		/* Inodes table block */
   uint16_t	bg_free_blocks_count;	/* Free blocks count */
   uint16_t	bg_free_inodes_count;	/* Free inodes count */
   uint16_t	bg_used_dirs_count;	/* Directories count */
   uint16_t	bg_pad;
   uint32_t	bg_reserved[3];
} group_desc;

/*
 * Constants relative to the data blocks
 */
#define	EXT2_NDIR_BLOCKS		12
#define	EXT2_IND_BLOCK			EXT2_NDIR_BLOCKS
#define	EXT2_DIND_BLOCK			(EXT2_IND_BLOCK + 1)
#define	EXT2_TIND_BLOCK			(EXT2_DIND_BLOCK + 1)
#define	EXT2_N_BLOCKS			(EXT2_TIND_BLOCK + 1)

/*
 * Structure of an inode on the disk
 */
typedef struct ext2_inode {
   uint16_t	i_mode;		/* File mode */
   uint16_t	i_uid;		/* Low 16 bits of Owner Uid */
   uint32_t	i_size;		/* Size in bytes */
   uint32_t	i_atime;	/* Access time */
   uint32_t	i_ctime;	/* Creation time */
   uint32_t	i_mtime;	/* Modification time */
   uint32_t	i_dtime;	/* Deletion Time */
   uint16_t	i_gid;		/* Low 16 bits of Group Id */
   uint16_t	i_links_count;	/* Links count */
   uint32_t	i_blocks;	/* Blocks count */
   uint32_t	i_flags;	/* File flags */
   union {
      struct {
         uint32_t  l_i_reserved1;
      } linux1;
      struct {
         uint32_t  h_i_translator;
      } hurd1;
      struct {
         uint32_t  m_i_reserved1;
      } masix1;
   } osd1;				/* OS dependent 1 */
   uint32_t	i_block[EXT2_N_BLOCKS];/* Pointers to blocks */
   uint32_t	i_generation;	/* File version (for NFS) */
   uint32_t	i_file_acl;	/* File ACL */
   uint32_t	i_dir_acl;	/* Directory ACL */
   uint32_t	i_faddr;	/* Fragment address */
   union {
      struct {
         uint8_t	l_i_frag;	/* Fragment number */
         uint8_t	l_i_fsize;	/* Fragment size */
         uint16_t	i_pad1;
         uint16_t	l_i_uid_high;	/* these 2 fields    */
         uint16_t	l_i_gid_high;	/* were reserved2[0] */
         uint32_t	l_i_reserved2;
      } linux2;
      struct {
         uint8_t	h_i_frag;	/* Fragment number */
         uint8_t	h_i_fsize;	/* Fragment size */
         uint16_t	h_i_mode_high;
         uint16_t	h_i_uid_high;
         uint16_t	h_i_gid_high;
         uint32_t	h_i_author;
      } hurd2;
      struct {
         uint8_t	m_i_frag;	/* Fragment number */
         uint8_t	m_i_fsize;	/* Fragment size */
         uint16_t	m_pad1;
         uint32_t	m_i_reserved2[2];
      } masix2;
   } osd2;				/* OS dependent 2 */
} inode;

/*
 * Structure of the super block
 */
typedef struct ext2_super_block {
   uint32_t	s_inodes_count;		/* Inodes count */
   uint32_t	s_blocks_count;		/* Blocks count */
   uint32_t	s_r_blocks_count;	/* Reserved blocks count */
   uint32_t	s_free_blocks_count;	/* Free blocks count */
   uint32_t	s_free_inodes_count;	/* Free inodes count */
   uint32_t	s_first_data_block;	/* First Data Block */
   uint32_t	s_log_block_size;	/* Block size */
   uint32_t	s_log_frag_size;	/* Fragment size */
   uint32_t	s_blocks_per_group;	/* # Blocks per group */
   uint32_t	s_frags_per_group;	/* # Fragments per group */
   uint32_t	s_inodes_per_group;	/* # Inodes per group */
   uint32_t	s_mtime;		/* Mount time */
   uint32_t	s_wtime;		/* Write time */
   uint16_t	s_mnt_count;		/* Mount count */
   uint16_t	s_max_mnt_count;	/* Maximal mount count */
   uint16_t	s_magic;		/* Magic signature */
   uint16_t	s_state;		/* File system state */
   uint16_t	s_errors;		/* Behavior when detecting errors */
   uint16_t	s_minor_rev_level; 	/* minor revision level */
   uint32_t	s_lastcheck;		/* time of last check */
   uint32_t	s_checkinterval;	/* max. time between checks */
   uint32_t	s_creator_os;		/* OS */
   uint32_t	s_rev_level;		/* Revision level */
   uint16_t	s_def_resuid;		/* Default uid for reserved blocks */
   uint16_t	s_def_resgid;		/* Default gid for reserved blocks */
} super_block;

/*
 * Revision levels
 */
#define EXT2_GOOD_OLD_REV	0	/* The good old (original) format */
#define EXT2_CURRENT_REV	EXT2_GOOD_OLD_REV
#define EXT2_GOOD_OLD_INODE_SIZE 128

/*
 * Structure of a directory entry
 */

typedef struct ext2_dir_entry {
   uint32_t	inode;			/* Inode number */
   uint16_t	rec_len;		/* Directory entry length */
   uint16_t	name_len;		/* Name length */
   char	name[];			        /* File name, up to EXT2_NAME_LEN */
} dir_entry;

/*
 * Ext2 file mode types
 */
#define EXT2_S_IFSOCK 0xC000  /* socket */
#define EXT2_S_IFLNK 0xA000   /* symbolic link */
#define EXT2_S_IFREG 0x8000  /* regular file */
#define EXT2_S_IFBLK 0x6000   /* block device */
#define EXT2_S_IFDIR 0x4000   /* directory */
#define EXT2_S_IFCHR 0x2000   /* character device */
#define EXT2_S_IFIFO 0x1000   /* fifo */

void read_data(uint32_t block, uint16_t offset, uint8_t* data, uint16_t size);

#endif

