
#include<stdio.h>
typedef struct{
	int Data[100];
	int size;
}Stack;

void make_null_Stack(Stack *S){
	S->size=0;
}

void push_Stack(Stack *S, int x){
	S->Data[S->size]=x;
	S->size++;
}

void pop(Stack* S) {
S->size--;
}

int top_Stack(Stack S){
	return S.Data[S.size-1];
}

int empty_Stack(Stack S){
	return S.size==0;
}

//Khai bao List
typedef struct{
	int data[100];
	int size;
}List;

void makenull_List(List *L){
	L->size=0;
}

void push_back(List *L,int x){
	L->data[L->size]=x;
	L->size++;
}

int element_at(List L,int i){
	return L.data[i-1];
}

int count_list(List* L) {
    return L->size;
}
//Khai bao Graph
typedef struct{
	int A[100][100];
	int n,m;
}Graph;

void init_Graph(Graph *G, int n ,int m){
	G->n=n;
	G->m=m;
	for(int i=1;i<=G->n;i++)
		for(int j=1;j<=G->m;j++)
			G->A[i][j]=0;
}

void add_Graph(Graph *G,int e, int u, int v){
	G->A[u][e]=1;
	G->A[v][e]=1;
}
int mark[100];
int parent_u[100];
List neighbors(Graph G, int x){
    List L;
    makenull_List(&L);
    for(int i =1;i<=G.n;i++){
        if(i!=x)
        for(int j =1;j<=G.m;j++){
        if(G.A[i][j]==1 &&G.A[x][j]==1 ){
            push_back(&L,i);
            break;
        }  
    }
    }
    return L;
}


void BFS(Graph G, int g){
	Stack S;
	make_null_Stack(&S);
	push_Stack(&S,g);
	while(!empty_Stack(S)){
		int x=top_Stack(S);
		pop(&S);
		if(mark[x]==0){
			mark[x]=1;
			List L = neighbors(G,x);
		 	for(int i =1;i<=L.size;i++){
		 		int y = element_at(L,i);
		 		if(mark[y]==0){
		 			push_Stack(&S,y);
		 			parent_u[y]=x;
		 		}
		 			
		 	}		
		}
	}
}

int main(){
	//Khoi tao
	freopen("dt.txt", "r", stdin); //Khi n?p bài nh? b? d?ng này.
	Graph G;
	int n, m, u, v;
	scanf("%d%d", &n, &m);
	init_Graph(&G,n,m);
	for(int i=1;i<=G.m;i++){
		scanf("%d%d",&u,&v);
		add_Graph(&G,i,u,v);
	}
	for(int i =1;i<=G.n;i++){
	    	mark[i]=0;
	}
	for(int i=1;i<=G.n;i++)
		BFS(G,i);
	for(int i=1;i<=G.n;i++)
		printf("%d %d\n",i,parent_u[i]);
}
