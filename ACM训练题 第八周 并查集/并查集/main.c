#include<stdio.h>
#define size 101
int father[size],rank[size];
//���鼯��ʼ������
void Init(int N){
    int i;
    for(i = 1;i < N;++i){
        father[i] = i;
        rank[i] = 1;        //father[i]���ڼ�¼�ڵ�i�ĸ��׽ڵ�,��rank[i]�����ڼ�¼
                            //�ڵ�i��Ϊ���ڵ�ʱ�������Ĵ�С(Ҳ��Ȩ��,���ڼ�¼���Ľڵ����)
    }
}
//���鼯�Ĳ�ѯ����,��ѯ��ǰ�������Ľڵ�ĸ��ڵ�
//�ڲ�ѯ������,������Ҫ����ѯ�Ĺ���ѹ��,���������ϱ���ѯ�ʴ���
//��ôһ������»��ȡ·��ѹ��������
//·��ѹ����������ÿ�β���ʱ�������·���ϵ�ÿ���ڵ㶼ֱ��ָ����ڵ�

int find_set(int node) {
    if (father[node] != node) {
        father[node] = find_set(father[node]);   //�� find_set ������,��ǰ��㲻�Ǹ����������,
                                                 //���ݹ�Ľ����ֵΪ��ǰ���ĸ��ڵ�,���ݹ������������
    }                                            //�ҵ����ڵ�,��ifѭ����������ʱ��,�ݹ����,���ظ��ڵ�����һ����ø�
    return father[node];                         //�����ĵط�,Ȼ����һ�㺯���ڵ�ĸ��׽ڵ㸳ֵΪ���ڵ�
                                                //����ظ���������,��"���׽ڵ�(���ڵ�)"������һ�㺯������ֵ,ֱ���������õݹ�ĺ���
                                            //�ú�����"���׽ڵ�(���ڵ�)"������_union����
}
//Ѱ�Ҹ��ڵ㲢�Ż��ĵڶ�������
int find_set2(int node){
    int r=node;
    while(father[r]!=r)
        r=father[r];
    int i=node,j;
    while(i!=r){
        j=father[i];
        i=j;
        father[i]=r;
    }
    return r;
}

//���鼯�ĺϲ�����,���������ཻ�ļ��Ϻϲ���һ��,�������ò�ͬ���и���
//ͨ��С���ĸ��ڵ�ָ������ĸ��ڵ�,ʹ�������и����ϲ��ɺ�һ���и���
int _union(int p,int q){
    int root1 = find_set2(p);
    int root2 = find_set2(q);
    if(root1==root2){
        return 0;     //�����ǰ�������������ڵ�ͬ����һ����ͨ����(����ͬһ�����еĽڵ�)

                    //��ִ�кϲ�����ֱ�ӷ���0,��ʾ�ϲ�ʧ��
    }
    if(rank[root1] > rank[root2]){

        father[root2] = root1;         //С�����ӵ�������,����Ȩֵ�����ϲ���
                                       //��������������������
        rank[root1] += rank[root2];
    }
    else{
        father[root1] = root2;
        rank[root2] += rank[root1];
    }
    return 1;
}

//������
int main(){
    int i, m, x, y;
    Init(size);        //��ʼ������
    scanf("%d",&m);    //m��ʾ��������
    for (i = 0; i < m; ++i) {
        scanf("%d %d",&x,&y);
        int ans = _union(x, y);
        if (ans) {
            printf("success\n");
        }
        else {
          printf("failed\n");
        }
    }
    return 0;
}
