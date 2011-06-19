#include "unit_test.c"

int main(int argc, char** argv)
{
  CuString *output = CuStringNew();
  CuSuite *suite = CuSuiteNew();

  add_unit_tests(suite);

  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s %s\n", argv[0], output->buffer);
  return suite->failCount;
}
