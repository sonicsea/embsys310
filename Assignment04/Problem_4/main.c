int IsLittleEndian()
{
  unsigned int x = 1;
  int result =  (int)(((char *)&x)[0]);
  return result;
}

int main()
{
  int flag = IsLittleEndian();
  if (flag == 1)
    printf("Little Endian");
  else
    printf("Big Endian");
  return 0;
}