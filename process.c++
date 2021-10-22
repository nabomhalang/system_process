#include "process.h"

int main(void) {
    int size, i, select;
    printf("어떤 스케줄링을 사용할 것인지 입력하십시오 \n1.FCFS(완)           2.SJF(미완)\n3.RR(미완)           4.SRT(미완)\n입력하세요 : ");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        fcfs_select();
        break;
    
    case 2:
        sjf_select();
        break;

    case 3:
        break;

    case 4:
        break;

    default:
        break;
    }
    return 0;
}

void fcfs_select() {
    int size;
    printf("몇개의 프로세스들을 입력할 것인지 입력하십시오 : ");
    scanf("%d", &size);

    struct setting s;
    for(int i = 0; i < size; i++) {
        printf("%d번째의 도착시간을 입력해주세요 : ", i+1);
        scanf("%d", &s.arrivalTime[i]);
        printf("%d번째의 실행시간을 입력해주세요 : ", i+1);
        scanf("%d", &s.workTime[i]);
    }
    s = process_sort(s, size);
    fcfs_input(s, size);
}

void sjf_select() {
    int size;
    printf("몇개의 프로세스들을 입력할 것인지 입력하십이오 : ");
    scanf("%d", &size);

    struct setting s;
    for(int i = 0; i < size; i++) {
        printf("%d번째의 도착시간을 입력해주세요 : ", i+1);
        scanf("%d", &s.arrivalTime[i]);
        printf("%d번째의 실행시간을 입력해주세요 : ", i+1);
        scanf("%d", &s.workTime[i]);
    }
    s = process_sort(s, size);
    sjf_input(s, size);
}

struct setting process_sort(struct setting s, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(s.arrivalTime[i] > s.arrivalTime[j]) {
                int temp_arrivalTime = s.arrivalTime[i];
                int temp_workTime = s.workTime[i];
                //arrivalTime 정렬
                s.arrivalTime[i] = s.arrivalTime[j];
                s.arrivalTime[j] = temp_arrivalTime;
                //workTime 정렬
                s.workTime[i] = s.workTime[j];
                s.workTime[j] = temp_workTime;
            }
        }
    }
    return s;
}

void sjf_input(struct setting s, int size) {
    int waiting_time = 0, total_process = 0, total = 0, gantt[MAX_SIZE][MAX_SIZE];
    system("clear");
    for(int i = 0; i < size; i++) {
        if(i == 0 && s.arrivalTime[i] > 0) total += s.workTime[i] + s.arrivalTime[i];
        else total += s.workTime[i];
    }
    memset(gantt, 0, total);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < total; j++) {
            
        }
    }
}

void fcfs_input(struct setting s, int size) {
    int waiting_time = 0, total_process = 0, total=0, gantt[MAX_SIZE][MAX_SIZE];
    system("clear");
    for(int i = 0; i < size; i++) {
        if(i == 0 && s.arrivalTime[i] > 0) total += s.workTime[i] + s.arrivalTime[i];
        else total += s.workTime[i];
    }
    
    memset(gantt, 0, total);
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < total; j++) {
            if(i==0 && s.arrivalTime[i] <= j) {
                for(int z=j; z < s.workTime[i] + s.arrivalTime[i]; z++)
                    gantt[i][z] = 1;
                break;
            }
            else if (i >= 1 && s.arrivalTime[i] <= j) {
                int idx=0;
                for(idx = j; gantt[i-1][idx] != 0; idx++) {
                    gantt[i][idx] = 2;
                }
                for(int z = idx; z < idx + s.workTime[i]; z++) {
                    gantt[i][z] = 1;
                }
                break;
            }
        }
    }
    printf("<------FCFS PROCESSING----->\n");
    for(int i =0; i< size; i++) {
        waiting_time = 0, total_process = 0;
        for(int j = 0; j < total; j++) {
            if(gantt[i][j] == 1) { total_process += 1; }
            else if(gantt[i][j] == 2) { waiting_time += 1; }
        }
        total_process += waiting_time;
        printf("%d번째 프로세스, 도착시간 : %d, 실행시간 : %d, 대기시간 : %d, 총처리시간 : %d\n", i+1, s.arrivalTime[i], s.workTime[i], waiting_time, total_process);
    }
    printf("<------------END------------>\n\n");
    printf("※칸당 1초, 🔲 : 칸, 🟣 : 대기중, ⚫ : 실행중\n\n");
    for(int i =0; i< size; i++) {
        waiting_time = 0, total_process = 0;
        for(int j = 0; j < total; j++) {
            if(gantt[i][j] == 0) { printf("🔲"); }
            else if(gantt[i][j] == 1) { printf("⚫");  }
            else if(gantt[i][j] == 2) { printf("🟣");}
        }
        printf("\n");
    }
}
