#include<stdio.h>
#include<string.h>
bool ans=false;
bool visit2[1000];
char alph[1000][1000];
int i=0;
void dfs(char cl)
{     if(cl=='m')
      {
          ans=true;
      }
else{
      for(int j=0;j<i;j++)
       {
          if(visit2[j]==0&&alph[j][0]==cl)//�Ѿ����ʵ����ٷ��ļ���û������ ����Ҫvisit�����־
          {
              visit2[j]=1;
              int t=strlen(alph[j]);
              dfs(alph[j][t-1]);//�����������
          }
       }
     }
}

int main()
{
    while(scanf("%s",alph[i++])!=EOF)//���벻Ϊ�������Ǿ�һֱ���� ÿ����0����
    {   memset(visit2,0,sizeof(visit2));
        if(alph[i-1][0]=='0')
        {
            dfs('b');
            printf("%s\n",ans?"Yes.":"No.");
            ans=false;
            i=0;
        }
    }
    return 0;
}
