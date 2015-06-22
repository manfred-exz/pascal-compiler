#ifndef _SYMTAB_H
#define _SYMTAB_H

#define SIZE 211

typedef struct LineListRec * LineList;
typedef struct BucketListRec * BucketList;
typedef struct HashTableRecord * HashTableList;

void st_init();
void st_insert( HashTableList hashtable, TreeNode *node, char *name, int loc, int para_type);
void st_insert_line(BucketList bl, int lineno);
void st_insert_hashtb(char *name);
void st_remove_hashtb();
BucketList st_lookup(HashTableList hashtable, char* name);
char * st_lookup_name(HashTableList hashtable, char* name);

/*	
 *	line number of each variable
 */

struct LineListRec
{
	int lineno;
	struct LineListRec * next;
};


/*
 *	each record of variables stored in the hash table
 */

struct BucketListRec
{
	char *name;
	TreeNode *node;
	LineList lines;
	int memloc;
	int para_type;
	int level;
	BucketList next;
};

struct HashTableRecord
{
	BucketList hasht[SIZE];
	struct HashTableRecord * next;
	char * label;
	int size;
};

extern HashTableList hashtable_const;
extern HashTableList hashtable_type;
extern HashTableList hashtable_var;
extern HashTableList hashtable_routine;

#endif
