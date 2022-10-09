#include <stdio.h>
#include <alg.h>

struct Process {
    int AT, BT, BT_left, CT, TAT, WT;
    char pid;
    _Bool completeness_flag, queue_flag;
};

typedef struct Node {
    struct Node *prev;
    struct Node *next;
    int val;
} node;

typedef struct Queue {
    node *back;
    node *front;
    int n;
} queue;

typedef struct Queue_Exec_Res{
    int time;
    int ready_n;
} exec_res;

int get_max(const struct Process *arr, int n) {
    int max = MININT;
    for (int i = 0; i < n; ++i)
        max = arr[i].AT > max ? arr[i].AT : max;
    return max;
}

int get_min(const struct Process *arr, int n) {
    int min = MAXINT;
    for (int i = 0; i < n; ++i)
        min = arr[i].AT < min ? arr[i].AT : min;
    return min;
}

void count_sort(int begin, int end, const struct Process *arr, int *indexes) {
    int result[end - begin];

    int min = get_min(arr, end);
    int max = get_max(arr, end);
    int count[max - min + 1], i;
    memset(count, 0, sizeof(count));

    for (i = begin; i < end; ++i)
        ++count[arr[i].AT - min];

    for (i = 1; i <= max - min + 1; ++i)
        count[i] += count[i - 1];

    for (i = end - 1; i >= begin; --i) {
        result[count[arr[i].AT - min] - 1] = indexes[i];
        --count[arr[i].AT - min];
    }

    for (i = begin; i < end; ++i)
        indexes[i] = result[i];
}

_Bool empty(queue *currentQueue) {
    return currentQueue->n == 0;
}

void enqueue(queue *currentQueue, int val) {
    if (empty(currentQueue)) {
        node *temp_node = malloc(sizeof(node));
        temp_node->prev = temp_node->next = NULL;
        temp_node->val = val;
        currentQueue->back = currentQueue->front = temp_node;
    } else {
        node *temp_node = malloc(sizeof(node));
        temp_node->val = val;
        temp_node->prev = NULL;
        temp_node->next = currentQueue->back;
        currentQueue->back->prev = temp_node;
        currentQueue->back = temp_node;
    }
    currentQueue->n++;
}

int dequeue(queue *currentQueue) {
    if (currentQueue->n > 1) {
        int val = currentQueue->front->val;
        node *temp = currentQueue->front;
        currentQueue->front = temp->prev;
        temp->next = NULL;
        free(temp);
        currentQueue->n--;
        return val;
    } else if (currentQueue->n == 1) {
        int val = currentQueue->front->val;
        free(currentQueue->front);
        currentQueue->front = currentQueue->back = NULL;
        currentQueue->n--;
        return val;
    }
    return -1;
}

void get_new_available_processes(struct Process processes[], const int n, const int cur_time, queue *process_queue) {
    for (int i = 0; i < n; ++i) {
        if (!processes[i].queue_flag && !processes[i].completeness_flag && processes[i].AT <= cur_time) {
            processes[i].queue_flag = 1;
            enqueue(process_queue, i);
        }
    }
}


exec_res execute_queue(struct Process processes[], const int n, const int quantum, queue *process_queue, int cur_time,
                  int ready_n) {
    int i = dequeue(process_queue);

    if (processes[i].BT_left <= quantum) {
        ready_n++;
        processes[i].completeness_flag = 1;
        cur_time += processes[i].BT_left;
        processes[i].CT = cur_time;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].BT_left = 0;
        int temp = processes[i].CT - processes[i].AT - processes[i].BT;
        if (temp < 0)
            processes[i].WT = 0;
        else
            processes[i].WT = temp;

        if (ready_n != n)
            get_new_available_processes(processes, n, cur_time, process_queue);
    } else {
        processes[i].BT_left -= quantum;
        cur_time += quantum;

        if (ready_n != n)
            get_new_available_processes(processes, n, cur_time, process_queue);
        enqueue(process_queue, i);
    }
    exec_res execRes;
    execRes.ready_n = ready_n;
    execRes.time = cur_time;
    return execRes;
}


void round_robin_algorithm(struct Process processes[], int n, int quantum) {
    queue *process_queue = (queue*) malloc(sizeof(process_queue));
    process_queue->front = process_queue->back = NULL;
    process_queue->n = 0;

    int cur_time = 0;
    int ready_n = 0;
    while(ready_n != n) {
        if (empty(process_queue)) {
            get_new_available_processes(processes, n, cur_time, process_queue);
            if(empty(process_queue))
                cur_time += 1;
        }
        else{
            exec_res execRes = execute_queue(processes, n, quantum, process_queue, cur_time, ready_n);
            cur_time = execRes.time;
            ready_n = execRes.ready_n;
        }
    }
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    struct Process processes[n + 1];
    int indexes[n];
    printf("Enter arrival times:\n");

    for(int i = 0; i < n; ++i){
        scanf("%d", &processes[i].AT);
    }

    printf("Enter burst times:\n");

    for (int i = 0; i < n; i++) {
        indexes[i] = i;
        scanf("%d", &processes[i].BT);
        processes[i].BT_left = processes[i].BT;
        processes[i].queue_flag = 0;
        processes[i].completeness_flag = 0;
    }

    count_sort(0, n, processes, indexes);
    struct Process new_processes[n + 1];

    for (int i = 0; i < n; ++i) {
        processes[indexes[i]].pid = (char) (65 + i);
        new_processes[i] = processes[indexes[i]];
    }
    round_robin_algorithm(new_processes, n, quantum);
    int sum_of_tats = 0;
    int sum_of_wts = 0;
    for(int i = 0 ; i < n; ++i){
        printf("Job - %c[AT - %d; BT - %d]: CT - %d, TAT - %d, WT - %d\n", new_processes[i].pid, new_processes[i].AT, new_processes[i].BT, new_processes[i].CT,
               new_processes[i].TAT, new_processes[i].WT);
        sum_of_tats += new_processes[i].TAT;
        sum_of_wts += new_processes[i].WT;
    }
    printf("Average Turnaround time - %lf\nAverage waiting time - %lf",
           (double) sum_of_tats / n, (double) sum_of_wts / n);
    return 0;
}

