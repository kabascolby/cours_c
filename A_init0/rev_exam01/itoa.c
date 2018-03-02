char *itoa(int n)
{
  long k;
  char *str;
  k = n;
  k = (n < 0 ? -(k) : k);
  int len;
  len = 0;
  while(k > 0)
  {
    k/=10;
    len++;
  }
  len = (n < 0 ? len + 2 : len + 1);
  str= (char *)malloc(sizeof(char) * len);
  str[--len] = '\0';
  k = n;
  k = (n < 0 ? -(k) : k);
  while(k > 0)
  {
    str[--len] = k % 10 + '0';
    k /=10;
  }
  if(n < 0)
    str[0] = '-';
  
  return(str);
  
}

int main() {
  printf("%s\n", itoa(-65));
  printf("%s\n", itoa(-2147483648));
  printf("%s\n", itoa(2147483647));
  printf("%s\n", itoa(65));

  return 0;
}