#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#define MAXIENGTH 100
struct Set
{
    int data[MAXIENGTH];
    unsigned count;
    //count默认是int型数据
};
void Initialize(Set *pSet);//初始化
void Add(int elem,Set *pSet);//添加
void Remove(int elem,Set *pSet);//删除
int Isin(int elem,Set* pSet);//是否存在
#endif // SET_H_INCLUDED
