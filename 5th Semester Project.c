#include<stdio.h>
#include<conio.h>
#include<string.h>

void separate(char []); //Separates the string that are between two '&' signs and creates a noun array.
void chkpro(char []); //Creates a pronoun array.
void link(int);
int match(char [], char[]); //Matches two strings.
void link2();
void out(char []); //Prints the output.
char nar[20][15], par[100][10], op[20], word[1000][20];
int n=0, st, lin=0, ni=0, pi=0, nal=0, pal=0, plc=0, pl=0, pflg=0, wl=0;

int main()    //Main Function: File is read and all the other functions are called.
{
   FILE *fp;
   char str[20], ch, p[100];
   int i=0, line=0, j=0;
   printf("Enter path of file: ");
   F:
     gets(p);
     fp=fopen(p,"r+");
     if(fp==NULL)
       {
        printf("\nFile not found.");
        printf("\n\nERROR:Wrong path entered.\n\nHELP:\nSyntax- DRIVE:\\Directory\\Filename.extention");
        printf("\nPlease enter correct path: ");
        goto F;
       }
   else
     {
      while(!feof(fp))
           {
            ch=fgetc(fp);
            if(ch!=' ' && ch!='.' && ch!=',' && ch!=';' && ch!=':' && ch!='?' && ch!='"' && ch!='\'' && ch!='/' && ch!='\\' && ch!='-' && ch!='\n' && ch!='(' && ch!=')')
              {
               str[i]=ch;
               i++;
              }
            else
              {
               str[i]='\0';
               n=atoi(str);
               i=0;
               goto N;
              }
           }
      N:
        fclose(fp);
        fp=fopen(p,"r+");
        st=0;
        while(!feof(fp))
             {
              ch=fgetc(fp);
              if(ch!=' ' && ch!=',' && ch!=';' && ch!=':' && ch!='?' && ch!='"' && ch!='\'' && ch!='/' && ch!='\\' && ch!='-' && ch!='(' && ch!=')')
                {
                 if(ch=='.')
                   {
                    line++;
                   }
                 if(ch=='\n')
                    st++;
                }
             }
        if(line==n && st<3)
          {
           fp=fopen(p,"r+");
           while(!feof(fp))
                {
                 ch=fgetc(fp);
                 if(ch!=' ' && ch!='.' && ch!=',' && ch!=';' && ch!=':' && ch!='?' && ch!='"' && ch!='\'' && ch!='/' && ch!='\\' && ch!='-' && ch!='\n' && ch!='(' && ch!=')')
                   {
                    str[i]=ch;
                    i++;
                   }
                 else
                   {
                    str[i]='\0';
                    if(str[0]!='\0')
                      {
                       separate(str);
                       strcpy(word[j],str);
                       j++;
                      }
                    i=0;
                   }
                 if(ch=='.')
                   {
                    lin++;
                   }
                }
           str[i-1]='\0';
           separate(str);
           strcpy(word[j],str);
           fclose(fp);
           wl=j+1;
           /*for(j=0;j<wl;j++)
                {
                 printf("%d-%s\n",j,word[j]);
                }*/
           printf("\nOutput:\n\n");
           //for(i=0;i<pal;i++)
                 //printf("%s.",par[i]);
           //for(i=0;i<nal;i++)
                //printf("%d.%s\n",i,nar[i]);
           pl=pal;
           link2();
          }
        else
          {
           printf("\nERROR: Input file content not in proper order.\n");
          }
     }
 return 0;
}

void separate(char str[])
{
 char tmp[20];
 int l=0, i;
 l=strlen(str);
 if(str[0]=='&' && str[l-1]=='&')
   {
    for(i=1;i<l-1;i++)
      {
       tmp[i-1]=str[i];
      }
    tmp[i-1]='\0';
    chkpro(tmp);
   }
 if(lin==n)
   {
    strcpy(nar[nal],str);
    nal++;
   }
}

void chkpro(char str[])
{
 if(strcmp(str,"its") || strcmp(str,"my") || strcmp(str,"who") || strcmp(str,"her") || strcmp(str,"his") || strcmp(str,"it") || strcmp(str,"who") || strcmp(str,"I") || strcmp(str,"me") || strcmp(str,"he") || strcmp(str,"she") || strcmp(str,"herself") || strcmp(str,"you") || strcmp(str,"that") || strcmp(str,"they") || strcmp(str,"each") || strcmp(str,"few") || strcmp(str,"many") || strcmp(str,"whoever") || strcmp(str,"whose") || strcmp(str,"someone") || strcmp(str,"everybody"))
   {
    strcpy(par[pal],str);
    pal++;
   }
}

void link(int b)
{
 char tch, tstr[20];
 int fi=0, flag=0, i2;
 i2=b;
 if(b==1 || match(par[pi],"my")==1)
   {
    for(;i2<wl;i2++)
       {
        if(pflg==1)
          {
           goto JM;
          }
        strcpy(tstr,word[i2]);
           if(tstr[0]!='\0')
              {
               for(fi=0;fi<nal;fi++)
                  {
                   flag=0;
                   flag=match(nar[fi],tstr);
                   if(flag==1)
                     {
                      strcpy(op,tstr);
    JM:               out(op);
                      goto L2;
                     }
                  }
              }
       }
    L2:
    printf("");
   }
 else{
 for(;i2>0;i2--)
   {
    if(pflg==1)
      {
       goto QM;
      }
    strcpy(tstr,word[i2]);
       if(tstr[0]!='\0')
          {
           for(fi=0;fi<nal;fi++)
              {
               flag=0;
               flag=match(nar[fi],tstr);
               if(flag==1)
                 {
                  strcpy(op,tstr);
 QM:              out(op);
                  goto L3;
                 }
              }
          }
   }
 L3:
  printf("");
 }
}

void link2()
{
 char tstr2[20], tmp[20];
 int i,i2, j, flag2=0, sl=0;
 for(i2=0;i2<wl;i2++)
   {
    strcpy(tstr2,word[i2]);
    sl=strlen(tstr2);
    if((tstr2[0]=='&') && (tstr2[sl-1]=='&'))
      {
       for(j=1;j<(sl-1);j++)
          {
           tmp[j-1]=tstr2[j];
          }
       tmp[j-1]='\0';
       flag2=0;
       flag2=match(par[pi],tmp);
       if(flag2==1)
         {
          //printf("\n%s-",par[pi]);
          if(match(tmp,"my")==1 || match(tmp,"i")==1)
            {
             if(pflg==1)
               {
                out(op);
               }
             if(pflg==0)
               {
                link(i2);
                pflg=1;
               }
            }
          else
            {
             pflg=0;
             link(i2);
            }
          pi++;
          goto Q;
         }
      }
 Q: printf("");
   }
}

int match(char s[], char t[])
{
 int j, l1=0, l2=0, f=0;
 l1=strlen(s);
 l2=strlen(t);
 if(l1==l2)
   {
    for(j=0;j<l1;j++)
       {
        if(tolower(s[j])==tolower(t[j]))
            f=1;
        else
          {
           f=0;
           goto C;
          }
       }
   }
 C:
 return f;
}

void out(char or[])
{
 if(plc<pl)
   {
    printf("%s\n",or);
    plc++;
   }
}
