#include <stdio.h>

void func(int *sum, int *count) {
    int num;
    scanf("%d", &num); 
    
    if (num == 0) {    
        return;
    }
    
    *sum += num;
    *count += 1;
    
    func(sum, count);
}

int main() {
    int sum = 0;
    int count = 0;
    
    func(&sum, &count);
    
    if (count == 0) {
        printf("Empty.\n");
    } else {
        double average = (double)sum / count;
        printf("Middle: %.2f\n", average);
    }
    
    return 0;
}