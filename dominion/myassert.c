int failed = 0;

int myassert(int b,char* msg) {
  if (b == 0) {
    printf("	FAILED ASSERTION: %s\n",msg);
    failed = 1;
    return failed;
  }
  return 0;
}

void checkasserts() {
  if (!failed) {
    printf ("TEST SUCCESSFULLY COMPLETED.\n");
  }
}
