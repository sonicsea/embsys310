
int main()
{
  unsigned int x = 1;
  printf ("%d", (int) (((char *)&x)[0]));
  return 0;
}
