#include <stdio.h>
#include <stdlib.h>
int a[10][10],vis[20],q[20],front=-1,rear=-1;
void main()
{
    int n,i,j,c,s;
    printf("enter no. of vertices\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("enter 1 if %d join with %d\n",i,j);
            scanf("%d",&a[i][j]);

        }
    }
    printf("the adjency vertices are\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d",a[i][j]);

        }
        printf("\n");
    }

    for(i=1;i<=n;i++){
        vis[i]=0;
    }
    printf("1.b.f.s\n2.d.f.s");
    printf("enter the source value");
    scanf("%d",&s);
    while(1){
        printf("enter choice\n");
        scanf("%d",&c);
        switch(c){
    case 1:bfs(s,n);
    break;
    case 2:dfs(s,n);
    break;}
    }
}
void bfs(int s,int n){
    int p,i;
    add(s);
    vis[s]=1;
    p=delete();
    if(p!=0){
        printf("%d",p);
    }
    while(p!=0){
        for(i=1;i<=n;i++){
            if(a[p][i]!=0&&vis[i]==0){
                add(i);
                vis[i]=1;}
                p=delete();
                if(p!=0){
                    printf("%d",p);
                }

        }
    }
    for(i=1;i<=n;i++){
        if(vis[i]==0){
            bfs(i,n);
        }
    }
}
void add(int item){
    if(rear==19){
        printf("queue is full\n");
    }
    else{
            if(rear==-1){
        rear++;
        q[rear]=item;
        front++;}
        else{
            q[++rear]=item;
        }

    }
}
int delete(){
int k;
if(front==-1||front<rear){
    return 0;
}
else{
        k=q[front++];
return k;

}
}
