#include "sub.h"

//#define or_is_interface_keyword(tok) || ((tok) == tok_interface)
//#define or_is_cli_class_type_keyword(tok)                                 \
  || (cppcli_enabled &&                                                   \
      ((tok) == tok_interface_class  || (tok) == tok_interface_struct ||  \
       (tok) == tok_ref_class        || (tok) == tok_ref_struct       ||  \
       (tok) == tok_value_class      || (tok) == tok_value_struct))
//#define is_class_type_keyword(tok)                                    \
  ((tok) == tok_struct || (tok) == tok_union ||                       \
   (tok) == tok_class  or_is_interface_keyword(tok)                   \
   or_is_cli_class_type_keyword(tok))
//#define is_declarator_start()                                               \
  (curr_token == tok_identifier ?                                           \
     (C_mode() || !identifier_is_template_id()) :                           \
     (curr_token == tok_star || curr_token == tok_lparen                    \
      or_is_microsoft_declarator_keyword(curr_token) or_is_near_or_far() || \
      (C_dialect == C_dialect_cplusplus &&                                  \
       (curr_token == tok_ampersand ||                                      \
        (rvalue_references_enabled && curr_token == tok_and_and)            \
        or_is_cli_declarator_operator(curr_token)                 ||        \
        curr_token == tok_operator))))
//#define symbol_header_is_for_identifier_string(sym_hdr, tok_str)             \
  ((sym_hdr)->identifier[0] == (tok_str)[0] &&                               \
   strncmp((sym_hdr)->identifier, (tok_str),                                 \
           size_t_arg((sym_hdr)->identifier_length)) == 0 &&                 \
   strlen((tok_str)) == (sym_hdr)->identifier_length)
//void is_dclarator_start_test()
//{
//	symbol_header_is_for_identifier_string(header, test);
//}

struct _member
{
	int _a;
};


int sub_test()
{
	struct _member member;

	int a = 0;
	int b = 20;
	int c = 30;

	if (a == 0)
	{
		member._a = 10;
	}
	else if (a == 1)
	{
		member._a = 10;
	}
	else
	{
		switch (b) // switch_start // switch_test_start // switch_test_end 
		{			//	switch_block_start
		case 0:		// ...case_start - case_end
			member._a = 10; // 	block_start		 block_end
			break;			
		case 1:
			member._a = 10;
			break;
		default:
			member._a = 10;
			break;
		} // switch_block_end switch_end
		member._a = 10; 
	} 

	return a + b + c; 
}

int sum(int a, int b)
{
	return a + b;
}

int substract(int a, int b)
{
	return a - b;
}

double divide(int a, int b)
{
	if (b != 0)
		return a / b;
	return 0;
}
long multiply(int a, int b)
{
	return a * b;
}
