
;; Function thread0 (thread0, funcdef_no=0, decl_uid=1988, cgraph_uid=1, symbol_order=2)

thread0 ()
{
  long unsigned int __atomic_store_tmp.1_1;

  <bb 2> [local count: 1073741824]:
  rt.a = -42;
  rt.b = -43;
  rt.c = -44;
  __atomic_store_tmp.1_1 = (long unsigned int) &rt;
  __atomic_store_8 (&gp, __atomic_store_tmp.1_1, 3);
  return;

}



;; Function thread1 (thread1, funcdef_no=1, decl_uid=1992, cgraph_uid=2, symbol_order=3)

thread1 ()
{
  int j;
  int i;
  long unsigned int _1;
  atomic struct rcutest * _2;
  _Bool _3;
  int _4;
  _Bool _5;
  int _6;

  <bb 2> [local count: 1073741823]:
  _1 = __atomic_load_8 (&gp, 1);
  _2 = (atomic struct rcutest *) _1;
  j_10 = MEM[(struct rcutest *)_2].a;
  if (_2 == &rt)
    goto <bb 3>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 3> [local count: 322122547]:
  i_12 = MEM[(struct rcutest *)_2].b;
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 751619277]:
  if (_1 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 375809638]:
  i_11 = MEM[(struct rcutest *)_2].c;

  <bb 6> [local count: 1073741824]:
  # i_7 = PHI <i_12(3), -1(4), i_11(5)>
  _3 = i_7 < 0;
  _4 = (int) _3;
  assert (_4);
  _5 = j_10 < 0;
  _6 = (int) _5;
  assert (_6);
  return;

}


