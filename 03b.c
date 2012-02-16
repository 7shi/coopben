#include <stdio.h>

typedef struct {
    int nums[16];
    int count;
} Numbers;

void Numbers_init(Numbers *this) {
    this->count = 0;
}

void Numbers_add(Numbers *this, int n) {
    if (this->count < 16)
        this->nums[this->count++] = n;
}

int Numbers_sum(Numbers *this) {
    int ret = 0, i;
    for (i = 0; i < this->count; i++)
        ret += this->nums[i];
    return ret;
}

int main(void) {
    Numbers nums;
    Numbers_init(&nums);
    Numbers_add(&nums, 1);
    Numbers_add(&nums, 2);
    Numbers_add(&nums, 3);
    printf("%d\n", Numbers_sum(&nums));
    return 0;
}
