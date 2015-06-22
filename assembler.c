#include "globals.h"
#include "assembler.h"
#include "symtab.h"

static int label_num = 0;
const int para_mode = 0;

int calc_type_simple_size(TreeNode *t)
{
	if (t->t_size == 0)
	{
		switch (t->kind.simple_kind)
		{
			case BooleanK:
			case CharK:
			case IntegerK:
			case RealK:
			case SNameListK:
			case DotDotK:
			{
				t->t_size = 4;
				break;
			}
			case IdK:
			{
				t->child[2] = (st_lookup(hashtable_type, t->id))->node;
				t->t_size = calc_type_size(t->child[2]);
				break;
			}
		}
	}
	
	return t->t_size;
}

int calc_type_array_size(TreeNode *t)
{
	int x, y;
	TreeNode *tmp, *tmp2;
	
	if (t->t_size == 0)
	{
		t->size = calc_type_size(t->child[1]);
	
		switch (t->child[0]->kind.simple_kind)
		{
			case BooleanK:
			{
				t->t_size = 2 * t->size;
				break;
			}
			case CharK:
			{
				t->t_size = 256 * t->size;
				break;
			}
			case IntegerK:
			case RealK:
			{
				t->t_size = 65536 * t->size;
				break;
			}
			case SNameListK:
			{
				for (x = 0, tmp = t->child[0]->child[0]; tmp != NULL; x++, tmp = tmp->sibling);
				t->t_size = x * t->size;
				break;
			}
			case DotDotK:
			{
				if (t->child[0]->id2 == NULL)
				{
					x = t->child[0]->child[0]->value.int_value;
					if (t->child[0]->child[0]->is_minus)
						x = -x;
					
					y = t->child[0]->child[1]->value.int_value;
					if (t->child[0]->child[1]->is_minus)
						y = -y;
					
					t->low_bound = x;
					x = y - x + 1;
				}
				else
				{
					tmp = (st_lookup(hashtable_const, t->child[0]->id))->node;
					tmp2 = (st_lookup(hashtable_const, t->child[0]->id2))->node;
					
					x = tmp->value.int_value;
					if (tmp->is_minus)
						x = -x;
						
					y = tmp2->value.int_value;
					if (tmp2->is_minus)
						y = -y;
					
					t->low_bound = x;
					x = y - x + 1;
				}
				
				t->t_size = x * t->size;
				break;
			}
			case IdK:
			{
				tmp = (st_lookup(hashtable_const, t->child[0]->id))->node;
				x = tmp->value.int_value;
				t->t_size = x * t->size;
				break;
			}		
		}
	}
	
	return t->t_size;	
}

int calc_type_record_size(TreeNode *t)
{
	TreeNode *tmp, *tmp2;
	int y;
	
	if (t->t_size == 0)
	{
		for (tmp = t->child[0]; tmp != NULL; tmp = tmp->sibling)
		{
			tmp->size = calc_type_size(tmp->child[1]);
			for (y = 0, tmp2 = tmp->child[0]; tmp2 != NULL; y++, tmp2 = tmp2->sibling);
			tmp->t_size = y * tmp->size;
			t->t_size += tmp->t_size;
		}
	}
	return t->t_size;
}

int calc_type_size(TreeNode *t)
{
	if (t->t_size != 0)
		return t->t_size;
	
	switch (t->kind.type_kind)
	{
		case TypeSimpleK:
		{
			t->t_size = calc_type_simple_size(t->child[0]);
			return t->t_size;
		}
		case TypeArrayK:
		{
			return calc_type_array_size(t);
		}
		case TypeRecordK:
		{
			return calc_type_record_size(t);
		}
	}
}

char *gen_label()
{
	char *tmp = malloc(256);
	memset(tmp, 0, 256);
	sprintf(tmp, "label_%d", label_num++);
	return tmp;
}

void assembler_exp(TreeNode *t, int para_mode)
{
	char *label1, *label2;
	BucketList tmp;
	TreeNode *tmp2, *tmp3, *tmp4;
	int i, count;
	char *tmp_name, *tmp_name2;
	
	if (t == NULL)
		return;
		
	switch (t->nodekind)
	{
		case ExpressionK:
		{
			assembler_exp(t->child[0], para_mode);
			assembler_exp(t->child[1], para_mode);

			label1 = gen_label();
			label2 = gen_label();
			
			fprintf(code, "pop ebx\r\n");
			fprintf(code, "pop eax\r\n");
			fprintf(code, "cmp eax, ebx\r\n");
			
			switch (t->kind.expression_kind)
			{
				case GeK:
				{
					fprintf(code, "jge %s\r\n", label1);
					break;
				}

				case GtK:
				{
					fprintf(code, "jg %s\r\n", label1);
					break;
				}

				case LeK:
				{
					fprintf(code, "jle %s\r\n", label1);
					break;
				}

				case LtK:
				{
					fprintf(code, "jl %s\r\n", label1);
					break;
				}

				case EqualK:
				{
					fprintf(code, "je %s\r\n", label1);
					break;
				}

				case UnequalK:
				{
					fprintf(code, "jne %s\r\n", label1);
					break;
				}
			}
			
			fprintf(code, "push 0\r\n");
			fprintf(code, "jmp %s\r\n", label2);
			fprintf(code, "%s:\r\n", label1);
			fprintf(code, "push 1\r\n");
			fprintf(code, "%s:\r\n", label2);
			break;
		}
		
		case ExprK:
		{
			assembler_exp(t->child[0], para_mode);
			assembler_exp(t->child[1], para_mode);
			
			fprintf(code, "pop ebx\r\n");
			fprintf(code, "pop eax\r\n");
			
			switch (t->kind.expr_kind)
			{
				case PlusK:
				{
					fprintf(code, "add eax, ebx\r\n");
					break;
				}

				case MinusK:
				{
					fprintf(code, "sub eax, ebx\r\n");
					break;
				}

				case OrK:
				{
					fprintf(code, "or eax, ebx\r\n");
					break;
				}
			}
			
			fprintf(code, "push eax\r\n");
			break;
		}
		
		case TermK:
		{
			assembler_exp(t->child[0], para_mode);
			assembler_exp(t->child[1], para_mode);
			
			fprintf(code, "pop ebx\r\n");
			fprintf(code, "pop eax\r\n");
			
			switch (t->kind.term_kind)
			{
				case MulK:
				{
					fprintf(code, "imul ebx\r\n");
					fprintf(code, "push eax\r\n");
					break;
				}
				
				case DivK:
				{
					fprintf(code, "idiv ebx\r\n");
					fprintf(code, "push eax\r\n");
					break;
				}
				
				case ModK:
				{
					fprintf(code, "idiv ebx\r\n");
					fprintf(code, "push edx\r\n");
					break;
				}
				
				case AndK:
				{
					fprintf(code, "and eax, ebx\r\n");
					fprintf(code, "push eax\r\n");
					break;
				}
			}
			
			break;
		}
		
		case FactorK:
		{
			if (t->id != NULL && !strcmp(t->id, "read"))
			{
				fprintf(code, "call readInt\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "abs"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "call absInt\r\n");
				fprintf(code, "add esp, 4\r\n");
			}
			
			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "chr"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "pop eax\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "odd"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "call oddInt\r\n");
				fprintf(code, "add esp, 4\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "ord"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "pop eax\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "pred"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "pop eax\r\n");
				fprintf(code, "dec eax\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "sqr"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "call sqrInt\r\n");
				fprintf(code, "add esp, 4\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "sqrt"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "call sqrtInt\r\n");
				fprintf(code, "add esp, 4\r\n");
			}

			else if (t->id != NULL && t->child[0]!= NULL && !strcmp(t->id, "succ"))
			{
				assembler_exp(t->child[0]->child[0], para_mode);
				fprintf(code, "pop eax\r\n");
				fprintf(code, "inc eax\r\n");
			}

			else if (t->id != NULL && t->id2 == NULL)
			{
				if (t->child[0] == NULL && t->child[1] == NULL) //ID
				{
					tmp = st_lookup(hashtable_const, t->id);
					if (tmp != NULL) //ID: const
					{
						fprintf(code, "lea eax, %s\r\n", st_lookup_name(hashtable_const, t->id));
						if (tmp->node->kind.simple_kind != StringK)
							fprintf(code, "mov eax, dword ptr [eax]\r\n");
					}
					
					else
					{
						tmp = st_lookup(hashtable_var, t->id);
						if (tmp != NULL) //ID: var
						{
							fprintf(code, "push ebp\r\n");							
							for (i = 0; i < tmp->level; i++)
							{
								fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
							}

							if (tmp->memloc < 0) //Normal var
							{
								if (para_mode == 0)
								{
									fprintf(code, "mov eax, dword ptr [ebp %d]\r\n", tmp->memloc);
								}
								else
								{
									fprintf(code, "lea eax, dword ptr [ebp %d]\r\n", tmp->memloc);
								}
							}
							else //Para var
							{
								fprintf(code, "mov eax, dword ptr [ebp +%d]\r\n", tmp->memloc);
													
								if (tmp->para_type == 1 && para_mode == 0) //Var Para
								{
									fprintf(code, "mov eax, dword ptr [eax]\r\n");
								}
							}

							fprintf(code, "pop ebp\r\n");
						}
						
						else
						{
							tmp = st_lookup(hashtable_routine, t->id);
							if (tmp != NULL) //ID: Proc
							{
								fprintf(code, "call %s\r\n", st_lookup_name(hashtable_routine, t->id));
							}
						}	
					}
				}
				
				else if (t->child[0] != NULL && t->child[1] == NULL) //ID(expr_list)
				{
					tmp = st_lookup(hashtable_routine, t->id);
					if (tmp != NULL)
					{
						for (tmp2 = tmp->node->child[0], tmp3 = t->child[0], count = 0; tmp2 != NULL && tmp3 != NULL; tmp2 = tmp2->sibling)
						{											
							for (tmp4 = tmp2->child[0]; tmp4 != NULL && tmp3 != NULL; tmp4 = tmp4->sibling, tmp3 = tmp3->sibling, count++)
							{
								switch (tmp2->kind.para_kind)
								{
									case VarK:
									{
										assembler_exp(tmp3->child[0], 1);
										break;
									}
								
									case ValK:
									{
										assembler_exp(tmp3->child[0], 0);
										break;
									}
								}
							}
						}
											
						fprintf(code, "call %s\r\n", st_lookup_name(hashtable_routine, t->id));
						fprintf(code, "add esp, %d\r\n", 4 * count);
					}
				}
				
				else if (t->child[0] == NULL && t->child[1] != NULL) //ID[expr]
				{
					tmp = st_lookup(hashtable_var, t->id);
					
					if (tmp != NULL)
					{
						assembler_exp(t->child[1], para_mode);
						fprintf(code, "pop eax\r\n");
						fprintf(code, "mov ebx, %d\r\n", tmp->node->low_bound);
						fprintf(code, "sub eax, ebx\r\n");
						fprintf(code, "mov ebx, %d\r\n", tmp->node->size);
						fprintf(code, "imul ebx\r\n");
						
						fprintf(code, "push ebp\r\n");							
						for (i = 0; i < tmp->level; i++)
						{
							fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
						}

						if (tmp->memloc < 0) //Normal var
						{
							fprintf(code, "add ebp, eax\r\n");
							if (para_mode == 0)
							{
								fprintf(code, "mov eax, dword ptr [ebp %d]\r\n", tmp->memloc);
							}
							else
							{
								fprintf(code, "lea eax, dword ptr [ebp %d]\r\n", tmp->memloc);
							}
						}
						else //Para var
						{
							if (tmp->para_type == 0)
							{
								fprintf(code, "add ebp, eax\r\n");
								if (para_mode == 0)
								{
									fprintf(code, "mov eax, dword ptr [ebp +%d]\r\n", tmp->memloc);
								}
								else
								{
									fprintf(code, "lea eax, dword ptr [ebp +%d]\r\n", tmp->memloc);
								}
							}
							else
							{
								fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
								fprintf(code, "add ebp, eax\r\n");
								if (para_mode == 0)
								{
									fprintf(code, "mov eax, dword ptr [ebp]\r\n");
								}
								else
								{
									fprintf(code, "mov eax, ebp\r\n");
								}
							}
						}

						fprintf(code, "pop ebp\r\n");
					}
				}
			}
			
			else if (t->id != NULL && t->id2 != NULL) //ID.ID
			{
				tmp = st_lookup(hashtable_var, t->id);
				if (tmp != NULL)
				{
					for (i = 0, count = 0, tmp2 = tmp->node->child[0]; tmp2 != NULL; tmp2 = tmp2->sibling)
					{
						for (tmp3 = tmp2->child[0]; tmp3 != NULL; tmp3 = tmp3->sibling)
						{
							if (strcmp(t->id2, tmp3->id) == 0)
							{
								i = 1;
								break;
							}
							count += tmp2->size;
						}
						if (i == 1)
							break;
					}
					
					fprintf(code, "push ebp\r\n");							
					for (i = 0; i < tmp->level; i++)
					{
						fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
					}

					if (tmp->memloc < 0) //Normal var
					{
						fprintf(code, "add ebp, %d\r\n", count);
						if (para_mode == 0)
						{
							fprintf(code, "mov eax, dword ptr [ebp %d]\r\n", tmp->memloc);
						}
						else
						{
							fprintf(code, "lea eax, dword ptr [ebp %d]\r\n", tmp->memloc);
						}
					}
					else //Para var
					{
						if (tmp->para_type == 0)
						{
							fprintf(code, "add ebp, %d\r\n", count);
							if (para_mode == 0)
							{
								fprintf(code, "mov eax, dword ptr [ebp +%d]\r\n", tmp->memloc);
							}
							else
							{
								fprintf(code, "lea eax, dword ptr [ebp +%d]\r\n", tmp->memloc);								
							}
						}
						else
						{
							fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
							fprintf(code, "add ebp, %d\r\n", count);
							if (para_mode == 0)
							{
								fprintf(code, "mov eax, dword ptr [ebp]\r\n");
							}
							else
							{
								fprintf(code, "mov eax, ebp\r\n");								
							}
						}
					}

					fprintf(code, "pop ebp\r\n");
				}
			}
			
			else if (t->id == NULL && t->child[0] != NULL)
			{
				switch (t->child[0]->nodekind)
				{
					case ConstK:
					{
						switch (t->child[0]->kind.simple_kind)
						{
							case IntegerK:
							case RealK:
							case CharK:
							case BooleanK:
							{
								fprintf(code, "mov eax, %d\r\n", t->child[0]->value.int_value);
								break;
							}
							case StringK:
							{
								tmp_name = gen_label();
								tmp_name2 = gen_label();
								fprintf(code, "lea eax, %s\r\n", tmp_name);
								fprintf(code, "jmp %s\r\n", tmp_name2);
								fprintf(code, "%s db %s\r\n", tmp_name, t->child[0]->value.str_value);
								fprintf(code, "%s:\r\n", tmp_name2);
								break;
							}
						}
						break;
					}
					
					case ExpressionK:
					case ExprK:
					case TermK:
					case FactorK:
					{
						assembler_exp(t->child[0], para_mode);
						fprintf(code, "pop eax\r\n");
						break;
					}
				}
			}
			
			if (t->is_minus == 1)
			{
				fprintf(code, "neg eax\r\n");
			}
			
			if (t->is_not == 1)
			{
				fprintf(code, "not eax\r\n");
			}
			
			fprintf(code, "push eax\r\n");
			break;
		}
	}
}

void assembler_stmt(TreeNode *t)
{
	BucketList tmp;
	TreeNode *tmp2, *tmp3, *tmp4;
	int count, i;
	char *tmp_name1, *tmp_name2;
	
	if (t == NULL)
		return;

			for (; t != NULL; t = t->sibling)
			{
				if (t->label != 0)
					fprintf(code, "goto_%d:\r\n", t->label);
				
				switch (t->kind.stmt_kind)
				{
					case AssignK:
					{
						tmp = st_lookup(hashtable_var, t->id);
						if (tmp != NULL)
						{
							if (t->id2 == NULL && t->child[1] == NULL) //ID:=exp
							{
								assembler_exp(t->child[0], para_mode);
								fprintf(code, "pop eax\r\n");
								
								fprintf(code, "push ebp\r\n");							
								for (i = 0; i < tmp->level; i++)
								{
									fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
								}

								if (tmp->memloc < 0) //Normal var
								{
									fprintf(code, "mov [ebp %d], eax\r\n", tmp->memloc);
								}
								else //Para var
								{
									if (tmp->para_type == 0)
									{
										fprintf(code, "mov [ebp +%d], eax\r\n", tmp->memloc);
									}					
									else
									{
										fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
										fprintf(code, "mov [ebp], eax\r\n");
									}
								}
								fprintf(code, "pop ebp\r\n");
							}
							
							else if (t->id2 == NULL && t->child[1] != NULL) //ID[exp]:=exp
							{
								assembler_exp(t->child[0], para_mode);
								fprintf(code, "pop eax\r\n");
								fprintf(code, "mov ebx, %d\r\n", tmp->node->low_bound);
								fprintf(code, "sub eax, ebx\r\n");
								fprintf(code, "mov ebx, %d\r\n", tmp->node->size);
								fprintf(code, "imul ebx\r\n");
								fprintf(code, "push eax\r\n");
								assembler_exp(t->child[1], para_mode);
								fprintf(code, "pop eax\r\n");
								fprintf(code, "pop ebx\r\n");
									
								fprintf(code, "push ebp\r\n");							
								for (i = 0; i < tmp->level; i++)
								{
									fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
								}

								if (tmp->memloc < 0) //Normal var
								{
									fprintf(code, "add ebp, ebx\r\n");
									fprintf(code, "mov [ebp %d], eax\r\n", tmp->memloc);
								}
								else //Para var
								{
									if (tmp->para_type == 0)
									{
										fprintf(code, "add ebp, ebx\r\n");
										fprintf(code, "mov [ebp +%d], eax\r\n", tmp->memloc);
									}
									else
									{
										fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
										fprintf(code, "add ebp, ebx\r\n");
										fprintf(code, "mov [ebp], eax\r\n");
									}
								}
								fprintf(code, "pop ebp\r\n");
							}
							
							else if (t->id2 != NULL) //ID.ID = exp
							{
								for (i = 0, count = 0, tmp2 = tmp->node->child[0]; tmp2 != NULL; tmp2 = tmp2->sibling)
								{
									for (tmp3 = tmp2->child[0]; tmp3 != NULL; tmp3 = tmp3->sibling)
									{
										if (strcmp(t->id2, tmp3->id) == 0)
										{
											i = 1;
											break;
										}
										count += tmp2->size;
									}
									if (i == 1)
										break;
								}
								
								assembler_exp(t->child[0], para_mode);
								fprintf(code, "pop eax\r\n");
									
								fprintf(code, "push ebp\r\n");							
								for (i = 0; i < tmp->level; i++)
								{
									fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
								}

								if (tmp->memloc < 0) //Normal var
								{
									fprintf(code, "add ebp, %d\r\n", count);
									fprintf(code, "mov [ebp %d], eax\r\n", tmp->memloc);
								}
								else //Para var
								{
									if (tmp->para_type == 0)
									{
										fprintf(code, "add ebp, %d\r\n", count);
										fprintf(code, "mov [ebp +%d], eax\r\n", tmp->memloc);
									}
									else
									{
										fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
										fprintf(code, "add ebp, %d\r\n", count);
										fprintf(code, "mov [ebp], eax\r\n");
									}
								}
								fprintf(code, "pop ebp\r\n");
							}
						}
						break;
					}
					
					case SProcK:
					{
						if (!strcmp(t->id, "write")) //Write
						{
							for (tmp3 = t->child[0], count = 0; tmp3 != NULL; tmp3 = tmp3->sibling, count++)
							{				
								assembler_exp(tmp3->child[0], para_mode);
								fprintf(code, "call writeInt\r\n");
								fprintf(code, "add esp, 4\r\n");
							}
						}
						
						else if (!strcmp(t->id, "writeln")) //Writeln
						{
							for (tmp3 = t->child[0], count = 0; tmp3 != NULL; tmp3 = tmp3->sibling, count++)
							{				
								assembler_exp(tmp3->child[0], para_mode);
								fprintf(code, "call writelnInt\r\n");
								fprintf(code, "add esp, 4\r\n");
							}
						}
						
						else
						{
							tmp = st_lookup(hashtable_routine, t->id);
							if (tmp != NULL)
							{
								if (t->child[0] == NULL) //ID
								{
									fprintf(code, "call %s\r\n", st_lookup_name(hashtable_routine, t->id));
								}
								else //ID(expr_list)
								{
									for (tmp2 = tmp->node->child[0], tmp3 = t->child[0], count = 0; tmp2 != NULL && tmp3 != NULL; tmp2 = tmp2->sibling)
									{	
										for (tmp4 = tmp2->child[0]; tmp4 != NULL && tmp3 != NULL; tmp4 = tmp4->sibling, tmp3 = tmp3->sibling, count++)
										{
											switch (tmp2->kind.para_kind)
											{
												case VarK:
												{
													assembler_exp(tmp3->child[0], 1);
													break;
												}
								
												case ValK:
												{
													assembler_exp(tmp3->child[0], 0);
													break;
												}
											}
										}
									}
														
									fprintf(code, "call %s\r\n", st_lookup_name(hashtable_routine, t->id));
									fprintf(code, "add esp, %d\r\n", 4 * count);
								}
							}	
						}
						break;
					}
					
					case CompoundK:
					{
						assembler_stmt(t->child[0]);
						break;
					}
					
					case IfK:
					{
						tmp_name1 = gen_label();
						tmp_name2 = gen_label();
						
						assembler_exp(t->child[0], para_mode);
						
						fprintf(code, "pop eax\r\n");
						fprintf(code, "test eax, eax\r\n");
						fprintf(code, "jz %s\r\n", tmp_name1);
						assembler_stmt(t->child[1]);
						fprintf(code, "jmp %s\r\n", tmp_name2);
						fprintf(code, "%s:\r\n", tmp_name1);
						assembler_stmt(t->child[2]);
						fprintf(code, "%s:\r\n", tmp_name2);
						break;
					}
					
					case RepeatK:
					{
						tmp_name1 = gen_label();
						
						fprintf(code, "%s:\r\n", tmp_name1);
						assembler_stmt(t->child[0]);
						assembler_exp(t->child[1], para_mode);
						fprintf(code, "pop eax\r\n");
						fprintf(code, "test eax, eax\r\n");
						fprintf(code, "jz %s\r\n", tmp_name1);
						break;
					}
					
					case WhileK:
					{
						tmp_name1 = gen_label();
						tmp_name2 = gen_label();
						
						fprintf(code, "%s:\r\n", tmp_name1);
						assembler_exp(t->child[0], para_mode);
						fprintf(code, "pop eax\r\n");
						fprintf(code, "test eax, eax\r\n");
						fprintf(code, "jz %s\r\n", tmp_name2);
						assembler_stmt(t->child[1]);
						fprintf(code, "jmp %s\r\n", tmp_name1);
						fprintf(code, "%s:\r\n", tmp_name2);
						break;
					}
					
					case ForK:
					{
						tmp = st_lookup(hashtable_var, t->id);
						if (tmp != NULL) //ID: var
						{
							tmp_name1 = gen_label();
							tmp_name2 = gen_label();
							
							assembler_exp(t->child[0], para_mode);
							fprintf(code, "pop ecx\r\n");
								
							fprintf(code, "push ebp\r\n");							
							for (i = 0; i < tmp->level; i++)
							{
								fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
							}

							if (tmp->memloc < 0) //Normal var
							{
								fprintf(code, "mov [ebp %d], ecx\r\n", tmp->memloc);
							}
							else //Para var
							{
								if (tmp->para_type == 0)
								{
									fprintf(code, "mov [ebp +%d], ecx\r\n", tmp->memloc);
								}					
								else
								{
									fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
									fprintf(code, "mov [ebp], ecx\r\n");
								}
							}
							fprintf(code, "pop ebp\r\n");
							
							fprintf(code, "%s:\r\n", tmp_name1);
							fprintf(code, "push ecx\r\n");
							
							assembler_exp(t->child[2], para_mode);
							fprintf(code, "pop eax\r\n");
							fprintf(code, "pop ecx\r\n");
							fprintf(code, "cmp ecx, eax\r\n");
							
							switch (t->child[1]->kind.direction_kind)
							{
								case ToK:
								{
									fprintf(code, "jg %s\r\n", tmp_name2);
									break;
								}
								
								case DowntoK:
								{
									fprintf(code, "jl %s\r\n", tmp_name2);
									break;
								}
							}
							
							assembler_stmt(t->child[3]);
							
							fprintf(code, "push ebp\r\n");							
							for (i = 0; i < tmp->level; i++)
							{
								fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
							}

							if (tmp->memloc < 0) //Normal var
							{
								fprintf(code, "mov ecx, dword ptr [ebp %d]\r\n", tmp->memloc);
							}
							else //Para var
							{
								fprintf(code, "mov ecx, dword ptr [ebp +%d]\r\n", tmp->memloc);
								fprintf(code, "mov ecx, dword ptr [ecx]\r\n");
							}
							
							fprintf(code, "pop ebp\r\n");
							
							switch (t->child[1]->kind.direction_kind)
							{
								case ToK:
								{
									fprintf(code, "inc ecx\r\n");
									break;
								}
								
								case DowntoK:
								{
									fprintf(code, "dec ecx\r\n");
									break;
								}
							}
							
							fprintf(code, "push ebp\r\n");							
							for (i = 0; i < tmp->level; i++)
							{
								fprintf(code, "mov ebp, dword ptr [ebp]\r\n");
							}

							if (tmp->memloc < 0) //Normal var
							{
								fprintf(code, "mov [ebp %d], ecx\r\n", tmp->memloc);
							}
							else //Para var
							{
								if (tmp->para_type == 0)
								{
									fprintf(code, "mov [ebp +%d], ecx\r\n", tmp->memloc);
								}					
								else
								{
									fprintf(code, "mov ebp, dword ptr [ebp +%d]\r\n", tmp->memloc);
									fprintf(code, "mov [ebp], ecx\r\n");
								}
							}
							fprintf(code, "pop ebp\r\n");
							
							fprintf(code, "jmp %s\r\n", tmp_name1);
							fprintf(code, "%s:\r\n", tmp_name2);
						}
						break;
					}
					
					case SCaseK:
					{
						tmp_name1 = gen_label();
						assembler_exp(t->child[0], para_mode);
						fprintf(code, "pop eax\r\n");
						
						for (tmp2 = t->child[1]; tmp2 != NULL; tmp2 = tmp2->sibling)
						{
							tmp_name2 = gen_label();
							
							if (tmp2->id == NULL)
							{
								fprintf(code, "mov ebx, %d\r\n", tmp2->child[0]->value.int_value);
							}
							
							else
							{
								tmp = st_lookup(hashtable_const, tmp2->id);
								if (tmp != NULL)
								{
									fprintf(code, "lea ebx, %s\r\n", st_lookup_name(hashtable_const, tmp2->id));
									if (tmp->node->kind.simple_kind != StringK)
										fprintf(code, "mov ebx, dword ptr [ebx]\r\n");
								}
							}
							
							fprintf(code, "cmp eax, ebx\r\n");
							fprintf(code, "jne %s\r\n", tmp_name2);
							
							if (tmp2->id == NULL)	
							{
								assembler_stmt(tmp2->child[1]);
							}
							else
							{
								assembler_stmt(tmp2->child[0]);
							}
							fprintf(code, "jmp %s\r\n", tmp_name1);
							fprintf(code, "%s:\r\n", tmp_name2);
						}
						
						fprintf(code, "%s:\r\n", tmp_name1);
						break;
					}
					
					case GotoK:
					{
						fprintf(code, "jmp goto_%d\r\n", t->dest);
						break;
					}
				}				
			}
}

void printConst()
{
	int h;
	char *tmp = NULL;
	HashTableList temphash = hashtable_const;
	BucketList templ;
	int flag = 0;	// flag == 1 means found.
	
	for (h = 0; h < SIZE; h++)
	{
		temphash = hashtable_const;		
		templ = (temphash->hasht)[h];
		
		while ( templ!=NULL )
		{		
			temphash = hashtable_const;
			tmp = malloc(256);
			memset(tmp, 0, 256);
			sprintf(tmp, "%s", templ->name);
			while (temphash != NULL)
			{
				if (temphash->label != NULL)
					sprintf(tmp, "%s_%s", tmp, temphash->label);
				temphash = temphash->next;
			}
			
			switch (templ->node->kind.simple_kind)
			{
				case BooleanK:
				case CharK:
				case IntegerK:
				case RealK:
				{
					fprintf(code, "%s dd %d\r\n", tmp, templ->node->value.int_value);
					break;
				}
				case StringK:
				{
					fprintf(code, "%s db %s,0\r\n", tmp, templ->node->value.str_value);
					break;
				}
			}
			templ = templ->next;
		}		
	}	
}

void assembler_do(TreeNode *t)
{
	TreeNode *tmp;
	
	int x;
	
	if (t == NULL)
		return;
	
	switch (t->nodekind)
	{
		case RoutineK:
		{
			assembler_do(t->child[0]);
			assembler_do(t->child[1]);
			assembler_do(t->child[2]);
			assembler_do(t->child[3]);
			
			fprintf(code, "%s:\r\n", st_lookup_name(hashtable_routine, t->id));
			fprintf(code, "push ebp\r\n");
			fprintf(code, "mov ebp, esp\r\n");
			fprintf(code, "sub esp, %d\r\n", hashtable_var->size);
			assembler_do(t->child[4]);
			if (hashtable_var->size !=0)
				fprintf(code, "mov eax, dword ptr [ebp %d]\r\n", -(hashtable_var->size));
			fprintf(code, "add esp, %d\r\n", hashtable_var->size);
			fprintf(code, "pop ebp\r\n");
			fprintf(code, "ret\r\n");
			break;
		}
		
		case ConstDeclK:
		{
			for (; t != NULL; t = t->sibling)
			{
				st_insert(hashtable_const, t->child[0], t->id, 0, 0);
			}
			break;
		}
		
		case TypeDeclK:
		{
			for (; t != NULL; t = t->sibling)
			{
				calc_type_size(t->child[0]);
				st_insert(hashtable_type, t->child[0], t->id, 0, 0);
			}
			break;
		}
		
		case VarDeclK:
		{
			hashtable_var->size = 0;
			for (; t != NULL; t = t->sibling)
			{
				calc_type_size(t->child[1]);
				for (tmp = t->child[0]; tmp != NULL; tmp = tmp->sibling)
				{
					hashtable_var->size += t->child[1]->t_size;
					st_insert(hashtable_var, t->child[1], tmp->id, -(hashtable_var->size), 0);
				}
			}
			break;
		}
		
		case FuncProcK:
		{
			for (; t != NULL; t = t->sibling)
			{
				st_insert(hashtable_routine, t, t->id, 0, 0); 
				st_insert_hashtb(t->id);
				
				assembler_do(t->child[0]);

				switch (t->kind.func_proc_kind)
				{
					case FuncK:
					{
						calc_type_simple_size(t->child[1]);
						hashtable_var->size += t->child[1]->t_size;
						st_insert(hashtable_var, t->child[1], t->id, -(hashtable_var->size), 0);
						assembler_do(t->child[2]);
						break;
					}
				
					case ProcK:
					{
						assembler_do(t->child[1]);
						break;
					}
				}
				
				printConst();
				
				st_remove_hashtb(t->id);
			}
			break;
		}
		
		case ParaK:
		{
			for (; t != NULL; t = t->sibling)
			{
				for (tmp = t->child[0]; tmp->sibling != NULL; tmp = tmp->sibling)
				{
					tmp->sibling->lsibling = tmp;
				}
				
				if (t->sibling != NULL)
				{
					t->sibling->lsibling = t;
				}
				else
					break;
			}
			
			x = 8;
			for (; t != NULL; t = t->lsibling)
			{
				calc_type_simple_size(t->child[1]);
				
				for (tmp = t->child[0]; tmp->sibling != NULL; tmp = tmp->sibling);
				for (; tmp != NULL; tmp = tmp->lsibling)
				{
					switch (t->kind.para_kind)
					{
						case VarK:
						{
							st_insert(hashtable_var, t->child[1], tmp->id, x, 1);
							x += 4;
							break;
						}
					
						case ValK:
						{
							st_insert(hashtable_var, t->child[1], tmp->id, x, 0);
							x += t->child[1]->t_size;
							break;
						}
					}
				}
			}
			break;
		}
		
		case StmtK:
		{
			assembler_stmt(t);
			break;
		}
	}
}
void assembler(TreeNode *t)
{
	if (t == NULL)
		return;

	st_init();
	fprintf(code, ".386p\r\n");
	fprintf(code, ".model flat,stdcall\r\n");
	fprintf(code, "option casemap:none\r\n");
	fprintf(code, "include pasLib.inc\r\n");
	fprintf(code, "includelib pasLib.lib\r\n");
	fprintf(code, ".code\r\n");
	fprintf(code, "program:\r\n");
	fprintf(code, "jmp %s\r\n", t->id);
	assembler_do(t->child[0]);
	assembler_do(t->child[1]);
	assembler_do(t->child[2]);
	assembler_do(t->child[3]);
	fprintf(code, "%s:\r\n", t->id);
	fprintf(code, "push ebp\r\n");
	fprintf(code, "mov ebp, esp\r\n");
	fprintf(code, "sub esp, %d\r\n", hashtable_var->size);
	assembler_do(t->child[4]);
	fprintf(code, "add esp, %d\r\n", hashtable_var->size);
	fprintf(code, "pop ebp\r\n");
	fprintf(code, "ret\r\n");
	printConst();
	fprintf(code, "end program\r\n");
}
