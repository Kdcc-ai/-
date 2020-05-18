#include<stdio.h>
#define size 101
int father[size],rank[size];
//并查集初始化操作
void Init(int N){
    int i;
    for(i = 1;i < N;++i){
        father[i] = i;
        rank[i] = 1;        //father[i]用于记录节点i的父亲节点,而rank[i]则用于记录
                            //节点i作为根节点时整棵树的大小(也称权重,用于记录树的节点个数)
    }
}
//并查集的查询操作,查询当前操作到的节点的根节点
//在查询操作中,我们需要将查询的过程压缩,即减少向上遍历询问次数
//那么一般情况下会采取路径压缩的做法
//路径压缩：就是在每次查找时，令查找路径上的每个节点都直接指向根节点

int find_set(int node) {
    if (father[node] != node) {
        father[node] = find_set(father[node]);   //在 find_set 函数中,当前结点不是根结点的情况下,
                                                 //将递归的结果赋值为当前结点的父节点,而递归结束的条件是
    }                                            //找到根节点,即if循环不成立的时候,递归结束,返回根节点至上一层调用该
    return father[node];                         //函数的地方,然后将上一层函数节点的父亲节点赋值为根节点
                                                //随后重复上述操作,将"父亲节点(根节点)"带回上一层函数并赋值,直到最外层调用递归的函数
                                            //该函数将"父亲节点(根节点)"返回至_union函数
}
//寻找根节点并优化的第二种做法
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

//并查集的合并操作,将两个不相交的集合合并成一个,即将两棵不同的有根树
//通过小树的根节点指向大树的根节点,使得两棵有根树合并成合一课有根树
int _union(int p,int q){
    int root1 = find_set2(p);
    int root2 = find_set2(q);
    if(root1==root2){
        return 0;     //如果当前操作到的两个节点同属于一个连通分量(即是同一棵树中的节点)

                    //则不执行合并操作直接返回0,表示合并失败
    }
    if(rank[root1] > rank[root2]){

        father[root2] = root1;         //小树连接到大树上,并且权值加至合并后
                                       //整棵完整的树的树根上
        rank[root1] += rank[root2];
    }
    else{
        father[root1] = root2;
        rank[root2] += rank[root1];
    }
    return 1;
}

//主函数
int main(){
    int i, m, x, y;
    Init(size);        //初始化操作
    scanf("%d",&m);    //m表示操作次数
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
