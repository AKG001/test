/* Test for _Dependent_ptr. _Dependent_ptr qualified pointer initialization tests. */
/* { dg-do run } */

extern void abort (void);
extern void exit (int);

#define TEST_SIMPLE_ASSIGN(TYPE)					\
  do									\
    {									\
      static volatile _Atomic _Dependent_ptr (TYPE) *a;			\
      static volatile (TYPE) b;						\
      a = &b;								\
      if (a != &b)							\
	abort();							\
    }                                                           	\
  while (0)

#define TEST_SIMPLE_ASSIGN_POINTER()					\
  do                                                            	\
    {                                                           	\
      TEST_SIMPLE_ASSIGN (_Bool);					\
      TEST_SIMPLE_ASSIGN (char);					\
      TEST_SIMPLE_ASSIGN (signed char);					\
      TEST_SIMPLE_ASSIGN (unsigned char);				\
      TEST_SIMPLE_ASSIGN (signed short);				\
      TEST_SIMPLE_ASSIGN (unsigned short);				\
      TEST_SIMPLE_ASSIGN (signed int);					\
      TEST_SIMPLE_ASSIGN (unsigned int);				\
      TEST_SIMPLE_ASSIGN (signed long);					\
      TEST_SIMPLE_ASSIGN (unsigned long);				\
      TEST_SIMPLE_ASSIGN (signed long long);				\
      TEST_SIMPLE_ASSIGN (unsigned long long);				\
      TEST_SIMPLE_ASSIGN (float);					\
      TEST_SIMPLE_ASSIGN (double);					\
      TEST_SIMPLE_ASSIGN (long double);					\
      TEST_SIMPLE_ASSIGN (_Complex float);				\
      TEST_SIMPLE_ASSIGN (_Complex double);				\
      TEST_SIMPLE_ASSIGN (_Complex long double);			\
      struct new_struct { _Dependent_ptr struct new_struct *next };	\
      _Dependent_ptr struct new_struct *s;				\
      struct new_struct t;						\
      s->next = &t;							\
      if (s->next != &t)						\
        abort();							\
    }									\
  while (0)

static void
test_simple_assign (void)
{
  TEST_SIMPLE_ASSIGN_POINTER ();
}

int main (void)
{
  test_simple_assign ();
  exit (0);
}
