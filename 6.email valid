%{
%}
%%
[a-z.0-9_]+"@"[a-z]+".com"|".in" {printf("\n Vaild E-mail\n");}
.+ {printf("\n Not Valid\n");}
%%
int yywrap(void){}
int main()
{
  printf("enter mail address:\n");
  yylex();
  return 0;
}
