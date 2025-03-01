#include <stdio.h>

int main() {
    int reference_string[] = {4, 7, 6, 1, 7, 6, 1, 2, 7, 2};
    int n = 10;
    int frames[3] = {-1, -1, -1};
    int number_of_frames = 3;
    int page_faults = 0;
    int page_hits = 0;
    int insertion_order[3] = {0, 0, 0};
    int current_time = 0;

    printf("Reference \tString \tFrames (after each step)\tAction\n");

    for (int i = 0; i < n; i++) {
        int page = reference_string[i];
        int found = 0;

        for (int j = 0; j < number_of_frames; j++) {
            if (frames[j] == page) {
                found = 1;
                page_hits++;
                break;
            }
        }

        if (found == 0) {
            int oldest_index = 0;
            for (int j = 1; j < number_of_frames; j++) {
                if (insertion_order[j] < insertion_order[oldest_index]) {
                    oldest_index = j;
                }
            }
            frames[oldest_index] = page;
            insertion_order[oldest_index] = current_time++;
            page_faults++;
        }

        printf("%d\t\t\t", page);
        for (int j = 0; j < number_of_frames; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            } else {
                printf("- ");
            }
        }
        if (found) {
            printf("\t\t\t\tPage \t\t\tHit\n");
        } else {
            printf("\t\t\t\tPage \t\t\tFault\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", page_hits);

    return 0;
}

//Reference 	String 	Frames (after each step)	Action
//4			4 - - 				Page 			Fault
//7			7 - - 				Page 			Fault
//6			7 6 - 				Page 			Fault
//1			7 6 1 				Page 			Fault
//7			7 6 1 				Page 			Hit
//6			7 6 1 				Page 			Hit
//1			7 6 1 				Page 			Hit
//2			2 6 1 				Page 			Fault
//7			2 7 1 				Page 			Fault
//2			2 7 1 				Page 			Hit

//Total Page Faults: 6
//Total Page Hits: 4