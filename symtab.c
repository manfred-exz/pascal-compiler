#include "globals.h"
#include "symtab.h"
#include "utils.h"

#define SHIFT 4

HashTableList hashtable_const;
HashTableList hashtable_type;
HashTableList hashtable_var;
HashTableList hashtable_routine;

static int hash ( char* key )
{
	int temp = 0;
	int i = 0;
	while ( key[i] != '\0')
	{
		temp = ((temp << SHIFT) + key[i]) % SIZE;
		i++;
	}
	return temp;
}

/* 
 * initialize hashtable. it must be done before using symtab. 
 */
void st_init_hashrecord(HashTableList h)
{
	int i;
	for (i=0; i<SIZE; i++)
	{
		h->hasht[i] = NULL;
	}
	h->next = NULL;
	h->label = NULL;
	h->size = 0;
}

void st_init()
{
	hashtable_const = (HashTableList) malloc (sizeof(struct HashTableRecord));
	hashtable_type = (HashTableList) malloc (sizeof(struct HashTableRecord));
	hashtable_var = (HashTableList) malloc (sizeof(struct HashTableRecord));
	hashtable_routine = (HashTableList) malloc (sizeof(struct HashTableRecord));
	st_init_hashrecord(hashtable_const);
	st_init_hashrecord(hashtable_type);
	st_init_hashrecord(hashtable_var);
	st_init_hashrecord(hashtable_routine);
}

/* 
 * insert a line into existed bucketlist 
 */
void st_insert_line(BucketList bl, int lineno)
{
	LineList templl = (LineList) malloc (sizeof(struct LineListRec));
	LineList ptemp;
	templl->next = NULL;
	templl->lineno = lineno;
	ptemp = bl->lines;
	while (ptemp->next!=NULL)
		ptemp = ptemp->next;
	ptemp->next = templl;
}

/*
 * insert a new symbol into symbol table 
 */
// hashtable from hashtable_{const|type|var|routine}
void st_insert( HashTableList hashtable, TreeNode *node, char *name, int loc, int para_type)
{
	int h = hash(name);
	BucketList l = hashtable->hasht[h];
	while ((l!=NULL) && (strcmp(name,l->name)!=0))
		l = l->next;
	if (l==NULL)
	{
		l = (BucketList) malloc (sizeof (struct BucketListRec));
		l->name = name;
		for (; hashtable == hashtable_var && node->nodekind == SimpleK && node->kind.type_kind == IdK; node = node->child[2]);
		for (; hashtable == hashtable_var && node->nodekind == TypeK && node->kind.type_kind == TypeSimpleK && node->child[0]->kind.simple_kind == IdK; node = node->child[0]->child[2]);
		l->node = node;
		l->memloc= loc;
		l->para_type = para_type;
		l->level = 0;
		(l->next) = (hashtable->hasht[h]);
		hashtable->hasht[h] = l;
	}
	/* found in table, just add line number */
	/* no more needed, the record in table is inserted in another way, details in add() function of analyze.c */
	/*
	else 
	{
		LineList t = l->lines;
		while (t->next != NULL) t = t->next;
		t->next = (LineList) malloc (sizeof(struct LineListRec));
		t->next->lineno = lineno;
		t->next->next = NULL;
	}
	*/
}


/*
 *	insert a new hashtable.
 */


HashTableList st_insert_hashtb_sub(HashTableList hashtable, char *label)
{
	HashTableList new_record = (HashTableList) malloc (sizeof(struct HashTableRecord));
	st_init_hashrecord(new_record);
	new_record->next = hashtable;
	new_record->label = copyString(label);
	return new_record;
}

void st_insert_hashtb(char *name)
{
	hashtable_const = st_insert_hashtb_sub(hashtable_const,name);
	hashtable_type = st_insert_hashtb_sub(hashtable_type,name);
	hashtable_var = st_insert_hashtb_sub(hashtable_var,name);
	hashtable_routine = st_insert_hashtb_sub(hashtable_routine,name);
}


/*
 * remove a hash table
 */
void st_remove_linelist(BucketList b)
{
	LineList temp;
	temp = b->lines;
	while (temp!=NULL)
	{
		b->lines = b->lines->next;
		free (temp);
		temp = b->lines;
	}
}

void st_remove_buckets(HashTableList h)
{
	int i;
	for ( i=0; i<SIZE; i++)
	{
		if (h->hasht[i]!=NULL)
		{
			st_remove_linelist(h->hasht[i]);
			free(h->hasht[i]);
		}
	}
}

HashTableList st_remove_hashtb_sub(HashTableList hashtable)
{
	HashTableList temp = hashtable;
	if ( temp!=NULL )
	{
		temp = temp->next;
		st_remove_buckets(hashtable);
		free(hashtable);
	}
	return temp;
}

void st_remove_hashtb()
{
	hashtable_const = st_remove_hashtb_sub(hashtable_const);
	hashtable_type = st_remove_hashtb_sub(hashtable_type);
	hashtable_var = st_remove_hashtb_sub(hashtable_var);
	hashtable_routine = st_remove_hashtb_sub(hashtable_routine);
}


BucketList st_lookup(HashTableList hashtable, char* name)
{
	int h=hash(name);
	int level = 0;
	HashTableList temphash = hashtable;
	BucketList templ;
	int flag = 0;	// flag == 1 means found.	
	while (temphash!=NULL)
	{
		templ = (temphash->hasht)[h];

		while ( templ!=NULL )
		{
			if ( strcmp(name, templ->name) == 0 )
			{
				flag = 1;
				break;
			}
			templ = templ->next;
		}

		if (flag==1)
			break;
		
		level++;
		temphash = temphash->next;
	}
	if (flag)
	{
		templ->level = level;
		return templ;
	}
	else
		return NULL;
}

char * st_lookup_name(HashTableList hashtable, char* name)
{
	int h=hash(name);
	char *tmp = malloc(256);
	HashTableList temphash = hashtable;
	BucketList templ;
	int flag = 0;	// flag == 1 means found.	
	while (temphash!=NULL)
	{
		templ = (temphash->hasht)[h];

		while ( templ!=NULL )
		{
			if ( strcmp(name, templ->name) == 0 )
			{
				memset(tmp, 0, 256);
				sprintf(tmp, "%s", name);
				while (temphash != NULL)
				{
					if (temphash->label != NULL)
						sprintf(tmp, "%s_%s", tmp, temphash->label);
					temphash = temphash->next;
				}
				flag = 1;
				break;
			}
			templ = templ->next;
		}

		if (flag==1)
			break;
		temphash = temphash->next;
	}
	if (flag)
		return tmp;
	else
		return NULL;
}


