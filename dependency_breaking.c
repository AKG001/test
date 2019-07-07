#include "../gcc/gcc/ginclude/stddef.h"
#include "../gcc/gcc/ginclude/stdatomic.h"

typedef __SIZE_TYPE__ size_t;
extern void abort (void);
extern void exit (int);
extern void *malloc (size_t);
extern int assert ();

struct rcutest
{
  int a;
  int b;
  int c;
};

_Atomic struct rcutest *gp;

#define rcu_assign_pointer(p,v)		\
  atomic_store_explicit(&(p), (v), memory_order_release);

#define rcu_dereference(p) 		\
  atomic_load_explicit(&(p), memory_order_consume);

struct rcutest rt = {1, 2, 3};

void thread0 ()
{
	rt.a = -42;
	rt.b = -43;
	rt.c = -44;
	rcu_assign_pointer(gp, &rt);
}

void thread1 ()
{
	int i = -1;
	int j = -1;
	struct rcutest * _Dependent_ptr p;

	p = rcu_dereference(gp);
	j = p->a;
	if (p == &rt)
		i = p->b;
	else if(p)
		i = p->c;
	assert(i<0);
	assert(j<0);
}
