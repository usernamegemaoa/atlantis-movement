#include "atlantis1.h"
#include <cutest/CuTest.h>
#include <stdio.h>

static void test_createregion(CuTest * tc)
{
    region * r;
    
    resetgame();
    r = createregion(2, 3);
    CuAssertPtrNotNull(tc, r);
    CuAssertIntEquals(tc, 2, r->x);
    CuAssertIntEquals(tc, 3, r->y);

    CuAssertPtrEquals(tc, 0, r->next);
}

static void test_createunit(CuTest * tc)
{
    region * r;
    unit *ux;
    
    resetgame();
    r = createregion(0, 0);
    ux = createunit(r);
    CuAssertPtrNotNull(tc, ux);

    CuAssertPtrEquals(tc, ux, r->units);
}

static void test_destroyunit(CuTest * tc)
{
    region *r;
    unit *u;

    resetgame();
    r = createregion(0, 0);
    u = createunit(r);
    destroyunit(u, r);
    CuAssertPtrEquals(tc, 0, r->units);    
}

static void test_createregion_once(CuTest * tc)
{
    region *r1, *r2;

    resetgame();
    r1 = createregion(0, 0);
    r2 = createregion(0, 0);
    CuAssertPtrEquals(tc, r1, r2);    
}

static void test_moveunit(CuTest * tc)
{
    region *r, *r2;
    unit *u;
    
    resetgame();
    r = createregion(0, 0);
    r2 = createregion(0, 1);
    u = createunit(r);
    moveunit(u, r, r2);

    CuAssertPtrEquals(tc, u, r2->units);
    CuAssertPtrEquals(tc, 0, r->units);
}

int main(int argc, char** argv)
{
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, test_createregion);
  SUITE_ADD_TEST(suite, test_createregion_once);
  SUITE_ADD_TEST(suite, test_createunit);
  SUITE_ADD_TEST(suite, test_moveunit);
  SUITE_ADD_TEST(suite, test_destroyunit);

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s %s\n", argv[0], output->buffer);
  return suite->failCount;
}
