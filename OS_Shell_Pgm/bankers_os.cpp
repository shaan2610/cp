// A Multithreaded Program that implements the banker's algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

int m,n,count=0;
int *curr;
int **allc;
int **max;
int **need;
int *seq;

pthread_mutex_t lockcurr;
pthread_cond_t condition;

void* processCode(void *arg) 
{
    int p = *((int *) arg);
    
    pthread_mutex_lock(&lockcurr);
    
    while(p != seq[count])
    {
        pthread_cond_wait(&condition, &lockcurr);
    }

    printf("\n--> Process %d", p+1);
    printf("\n\tAllocation : ");
    for(int i=0; i<m; i++)
    {
        printf("%3d", allc[p][i]);
    }

    printf("\n\tNeeded    : ");
    for(int i=0; i<m; i++)
    {
        printf("%3d", need[p][i]);
    }

    printf("\n\tAvailable : ");
    for(int i=0; i<m; i++)
    {
        printf("%3d", curr[i]);
    }
    printf("\n"); 
    printf("\tResource Allocation!");
    printf("\n");
    printf("\tProcess Code Running...");
    printf("\n");
    printf("\tProcess Code Completed...");
    printf("\n");
    printf("\tProcess Releasing Resource...");
    printf("\n");

    printf("\tResource Released!");
    for(int i=0; i<m; i++)
    {
        curr[i] += allc[p][i];
    }
    printf("\n\tNow Available : ");
    for(int i=0; i<m; i++)
    {
        printf("%3d", curr[i]);
    }
    printf("\n\n");
    count++;
    pthread_cond_broadcast(&condition);
    pthread_mutex_unlock(&lockcurr);
    pthread_exit(NULL);
}


bool getseq() 
{
    int curr1[m];
    for(int i=0;i<m;i++) 
    {
        curr1[i] = curr[i];
    }
    bool comp[n];
    for(int i=0; i<n; i++)
    {
        comp[i] = false;
    }
    int num=0;
    while(num<n) 
    {
        bool check=false;
        for(int i=0;i<n;i++) 
        {
            if(!comp[i]) 
            {
                bool possible=true;
                for(int j=0;j<m;j++)
                {
                    if(need[i][j]>curr1[j]) 
                    {
                        possible = false;
                        break;
                    }
                }
                if(possible) 
                {
                    for(int j=0;j<m;j++)
                    {
                        curr1[j]+=allc[i][j];
                    }
                    seq[num]=i;
                    comp[i]=true;
                    ++num;
                    check=true;
                }
            }
        }
        if(!check) 
        {
            for(int k=0; k<n; k++) seq[k] = -1;
            return false;   // Deadlock detected
        }
    }
    return true;
}


int main(int argc, char** argv) 
{
	scanf("%d", &n);
    scanf("%d", &m);

    curr = (int *)malloc(m * sizeof(*curr));
    for(int i=0; i<m; i++)
    {
        scanf("%d", &curr[i]);
    }

    allc = (int **)malloc(n * sizeof(*allc));
    for(int i=0; i<n; i++)
    {
        allc[i] = (int *)malloc(m * sizeof(**allc));
    }

    max = (int **)malloc(n * sizeof(*max));
    for(int i=0; i<n; i++)
    {
        max[i] = (int *)malloc(m * sizeof(**max));
    }
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &allc[i][j]);
        }
    }
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    need = (int **)malloc(n * sizeof(*need));
    for(int i=0; i<n; i++)
    {
        need[i] = (int *)malloc(m * sizeof(**need));
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            need[i][j] = max[i][j] - allc[i][j];
        }
    }
	// get check sequence
	seq = (int *)malloc(n * sizeof(*seq));
    for(int i=0; i<n; i++)
    {
        seq[i] = -1;
    }

    if(!getseq()) {
            printf("\nUnsafe State! -> Chances of Deadlock.\n\n");
            exit(-1);
    }

    printf("\n\nSafe Sequence Found :");
    for(int i=0; i<n; i++) 
    {
        printf("->%d", seq[i]+1);
    }

    printf("\nExecuting Processes...\n\n");
    
	// run threads
	pthread_t processes[n];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
	int processNumber[n];
	for(int i=0; i<n; i++) 
    {
        processNumber[i] = i;
    }

    for(int i=0; i<n; i++)
    {
        pthread_create(&processes[i], &attr, processCode, (void *)(&processNumber[i]));
    }
    for(int i=0; i<n; i++)
    {
        pthread_join(processes[i], NULL);
    }
    printf("\nAll Processes comp\n");	
}