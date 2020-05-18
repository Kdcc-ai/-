#include <stdio.h>
#include <stdlib.h>
#define INF 32767
#define max 50
//������bug
typedef struct Mgraph{
   char V[100][100];//������
   char name[100][100];//������
   int edges[100][100];//��������
   int n;//ͼ�ж������
}graph;
typedef struct{
   int u;//�ߵ���ʼ����
   int v;//�ߵ���ֹ����
   int w;//�ߵ�Ȩֵ
}edge;
edge edgeset[100];
int findbian(graph g){//ͳ���ܹ��м�����
   int k=1;
   for(i=1;i<=g.n;i++)
        for(j=1;j<=g.n;j++)
          if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
          {
              edgeset[k].u=i;
              edgeset[k].v=j;
              edgeset[k].w=g.edges[i][j];//��ʼ������
              k++;
          }
  return k-1;//�ܹ���k-1����
}
void sort(int n){
   int i,j;
   edge t;
   for(i=1;i<=n-1;i++)
     for(j=i+1;j<=n;j++)
   if(edgeset[i].w>edgeset[j].w){
    t=edgeset[j];
    edgeset[j]=edgeset[i];
    edgeset[i]=t;
   }
}
int find_set(int father[],int node){//Ѱ�Ҹýڵ�ĸ��ڵ�ڵ�
    int r=node;
    while(father[r]!=r){
        r=father[r];
    }
    int i=node,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;//ѹ��·������
    }
    return r;
}
void Kruskal(graph g){
    printf("��³˹�������ͨ����Ϊ��\n");
    int father[max],v1,v2;
    int n=findbian(graph g);//�ܹ���n����
    sort(n);//��Ȩֵ��������
    for(i=1;i<=g.n;i++)
        father[i]=i;//���鼯��ʼ������
    i=1;
    while(i<g.n)    {//Ѱ��n-1����
        v1=find_set(father,edgeset[i].u);
        v2=find_set(father,edgeset[i].v);
        if(v1!=v2){
            printf("��(%d,%d)��ȨֵΪ��%d\n",edgeset[i].u,edgeset[i].v,edgeset[i].w);
            i++;
            father[v1]=v2;//v1�ĸ��ڵ�ǳ�v2
                 }
                      }

}


void Prim(graph g,int v){//Prim�㷨
    int i,k,min;
    int lowcost[100];//�������
    int closeset[100];
    for(i=1;i<=g.n;i++){//���������鸳��ֵ lowcost����Ϊ1->n���ڵ㵽�����ĵ�һ���ڵ��Ȩֵ��С closeset����Ϊ1->���ڵ��ǰһ����������ʱ�����ĵ�һ���ڵ�
        lowcost[i]=g.edges[v][i];
        closeset[i]=v;//��i�����Ķ���
        lowcost[v]=0;
    }
    for(i=1;i<g.n;i++){//���n-1����,��V-U���ҳ���U����Ķ���k
        min=INF;

        for(j=1;j<=g.n;j++)//����forѭ���ĵ�һ��,�Ӷ���1��ʼ����
            if(lowcost[j]!=0&&lowcost[j]<min)//jû��U����j��U����С��min
        {
            min=lowcost[j];
            k=j;//k��¼�����Ŷ���,�ռ���U���ϵĶ���
        }

       printf("��(%s,%s)��ȨֵΪ��%d\n",g.name[closeset[k]],g.name[k],lowcost[k]);
       lowcost[k]=0;//���k����U

    for(j=1;j<=g.n;j++){//����forѭ���ĵڶ���,�Ӷ���1��ʼ����
        if(lowcost[j]!=0&&`g.edges[k][j]<lowcost[j]){//j��V-U����j��ղ���Ľڵ����С��lowcost�����еľ���,������ֵ
            lowcost[j]=g.edges[k][j];//Ҫע��lowcost�����ǲ��ϸ��µ�,��ʼ�մ������V-U��ĳ�ڵ㵽V�нڵ�ľ�����Сֵ
            closeset[j]=k;//��ʱ��j�ڵ������������ڵ��Ϊj
        }
       }



    }

}



int main()
{
    int number=INF,i=1,count;
    graph g;
    while(number!=0){
    printf("������Ϣ�����밴1\n");
    printf("���м����༭�밴2\n");
    printf("����Prim�㷨����ͨ�����Ĺ����밴3\n");
    printf("����Kruskal�㷨����ͨ�����Ĺ����밴4\n");
    printf("�˳��밴0\n");
    scanf("%d",&number);
    if(number==1){
        printf("��������������ĳ�����Ϣ����\n");
        scanf("%d",&g.n);
        count=g.n;
        while(count--){
            printf("��������б�źͳ������ƣ�\n");
            scanf("%s %s",g.V[i],g.name[i]);
            i++;
         }
         printf("������Ϣ¼��ɹ�\n\n");
    }
    if(number==2)
        { int a,b,c,j;
        for(i=1;i<=g.n;i++)
        for(j=1;j<=g.n;j++)
         {g.edges[i][j]=INF;
         }
         for(i=1;i<=g.n;i++)
        for(j=1;j<=g.n;j++)
         {g.edges[i][j]=INF;
         }


       printf("����������¼�����Ϣ����\n");
       scanf("%d",&count);
        while(count--)
        { printf("��������б�ź�����֮��ľ���");
            scanf("%d %d %d",&a,&b,&c);
            g.edges[a][b]=g.edges[b][a]=c;
        }
    if(number==3)
        Prim(g,1);
    if(number==4)
        Kruskal(g);
   }

                     }
    return 0;
}
