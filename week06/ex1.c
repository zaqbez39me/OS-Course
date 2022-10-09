#include <stdio.h>
#include <alg.h>

int get_max(const int *arr, int n){
    int max = MININT;
    for(int i = 0; i < n; ++i)
        max = arr[i] > max ? arr[i] : max;
    return max;
}

int get_min(const int *arr, int n){
    int min = MAXINT;
    for(int i = 0; i < n; ++i)
        min = arr[i] < min ? arr[i] : min;
    return min;
}

void countSort(int begin, int end, int* arr, int* indexes)
{
    int result[end - begin];

    int min = get_min(arr, end);
    int max = get_max(arr, end);
    int count[max - min + 1], i;
    memset(count, 0, sizeof(count));

    for (i = begin; i < end; ++i)
        ++count[arr[i] - min];

    for (i = 1; i <= max - min + 1; ++i)
        count[i] += count[i - 1];

     for (i = end - 1; i>=begin; --i) {
        result[count[arr[i] - min] - 1] = indexes[i];
        --count[arr[i] - min];
    }

    for (i = begin; i < end; ++i)
        indexes[i] = result[i];
}

int get_next(const int *arrival, const int *indexes, int last_finish_time, _Bool *arrived, int n){
    for(int i = 0; i < n; ++i){
        if(arrival[indexes[i]] <= last_finish_time && !arrived[indexes[i]]){
            arrived[indexes[i]] = 1;
            return indexes[i];
        }
    }
    return -1;
}


int main(){
    int n;
    scanf("%d", &n);
    int arrival[n], burst[n], indexes[n], waiting_time[n], complete_time[n], turn_around_time[n], end_time[n];
    printf("Enter arrival times:\n");
    for(int i = 0;i < n; ++i)
        scanf("%d", arrival + i);
    printf("Enter burst times:\n");
    for(int i = 0;i < n; ++i)
        scanf("%d", burst + i);
    for(int i = 0;i < n; ++i)
        indexes[i] = i;
    countSort(0, n, arrival, indexes);
    int last_finish_time = 0;
    int sum_of_tats = 0;
    int sum_of_wts = 0;
    int visited_num = 0;
    _Bool arrived[n];
    memset(arrived, 0, sizeof (arrived));
    while (visited_num != n) {
        int next = get_next(arrival, indexes, last_finish_time, arrived, n);
        if (next == -1) {
            last_finish_time++;
            continue;
        } else{
            end_time[next] = last_finish_time + burst[next],
            turn_around_time[next] = end_time[next] - arrival[next], waiting_time[next] = last_finish_time - arrival[next];
            arrived[next] = 1;
            visited_num++;
        }
        sum_of_tats += turn_around_time[next];
        sum_of_wts += waiting_time[next];
        last_finish_time += burst[next];
    }
    for(int i = 0; i < n; ++i)
        printf("Job - %c[AT - %d; BT - %d]: CT - %d, TAT - %d, WT - %d\n", 65 + indexes[i], arrival[i],
               burst[i], end_time[i],
               turn_around_time[i], waiting_time[i]);
    printf("Average Turnaround time - %lf\nAverage waiting time - %lf",
           (double) sum_of_tats / n, (double) sum_of_wts / n);
}