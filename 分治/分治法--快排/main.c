#include <stdio.h>
#include <stdlib.h>
int n,a[101];
void quicksort(int left,int right)
{
    int i,j,t,temp;
    if(left>right) return;
    temp=a[left];//temp中存的就是基准数
    i=left;
    j=right;
    while(i!=j)
        //这块循环的终止条件就是保证i==j
        //那么i左侧所有数据全部小于等于a[left];
        //i右侧所有数据全部大于a[left]
    {
        //顺序很重要,从右边开始找
        //为什么一定要先从右边往左边寻找呢？
        //这么想 如果说先从左边开始寻找的话
        //那么i所停留的位置一定是大于a[left]值数据的位置或者是j位置(例如5 4 3 2 1数据)
        //① 如果说走到了j位置 那么i==j跳出循环 a[left]=a[i]=1 a[i]=temp=5 显然不正确
        //② 如果说停留的位置是大于a[left]值数据的位置(例如6 1 2 7 9或者6 1 7 2 9)
        //如果是6 1 2 7 9的话，那么之后j向左移锁停留的位置一定也是7位置(由于i==j跳出循环),最终基数归位a[left]=a[i]=7 a[i]=temp=6 显然不正确
        //如果是6 1 7 2 9的话，我们发现最终结果是正确的
        while(a[j]>=temp&&i<j)
            j--;
        while(a[i]<=temp&&i<j)
            i++;
        //如果i==j 说明j的左侧所有数据全部小于等于a[left]
        //那么i,j所停的位置就是a[left]要填入的位置
        if(i<j)
        {
            t=a[i];
            a[i]=a[j];
            a[i]=t;
        }
    }
    //基数归位
    a[left]=a[i];
    a[i]=temp;
    quicksort(left,i-1);//继续处理左边的
    quicksort(i+1,right);//继续处理右边的
}
int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(1,n);//调用快速排序
    //输出排序后结果
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    getchar();getchar();
    return 0;
}
