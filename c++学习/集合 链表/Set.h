#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#define MAXIENGTH 100
struct Set
{
    int data[MAXIENGTH];
    unsigned count;
    //countĬ����int������
};
void Initialize(Set *pSet);//��ʼ��
void Add(int elem,Set *pSet);//���
void Remove(int elem,Set *pSet);//ɾ��
int Isin(int elem,Set* pSet);//�Ƿ����
#endif // SET_H_INCLUDED
