/* Test for _Dependent_ptr. _Dependent_ptr qualified pointer initialization tests. */
/* { dg-do run } */

extern void abort (void);
extern void exit (int);

int main (void)
{
  {
    static volatile _Atomic _Dependent_ptr *a;
    static volatile _Atomic b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr void *a;
    static volatile _Atomic char b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr _Bool *a;
    static volatile _Atomic _Bool b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr char *a;
    static volatile _Atomic char b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr signed char *a;
    static volatile _Atomic signed char b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr unsigned char *a;
    static volatile _Atomic unsigned char b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr signed short *a;
    static volatile _Atomic signed short b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr unsigned short *a;
    static volatile _Atomic unsigned short b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr signed int *a;
    static volatile _Atomic signed int b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr unsigned int *a;
    static volatile _Atomic unsigned int b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr signed long *a;
    static volatile _Atomic signed long b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr unsigned long *a;
    static volatile _Atomic unsigned long b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr signed long long *a;
    static volatile _Atomic signed long long b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr unsigned long long *a;
    static volatile _Atomic unsigned long long b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr float *a;
    static volatile _Atomic float b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr double *a;
    static volatile _Atomic double b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr long double *a;
    static volatile _Atomic long double b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr _Complex float *a;
    static volatile _Atomic _Complex float b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr _Complex double *a;
    static volatile _Atomic _Complex double b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    static volatile _Atomic _Dependent_ptr _Complex long double *a;
    static volatile _Atomic _Complex long double b;
    a = &b;
    if (a != &b)
	abort();
  }
  {
    struct new_struct { _Dependent_ptr struct new_struct *next; };
    _Dependent_ptr struct new_struct *a;
    struct new_struct b;
    a->next = &b;
    if (a->next != &b)
	abort();
  }
}
