#include <stdio.h>

class Numbers {
public:
    int nums[16];
    int count;

    Numbers() : count(0) {}

    void add(int n) {
        if (count < 16)
            nums[count++] = n;
    }

    int sum() {
        int ret = 0;
        for (int i = 0; i < count; i++)
            ret += nums[i];
        return ret;
    }
};

int main() {
    Numbers nums;
    nums.add(1);
    nums.add(2);
    nums.add(3);
    printf("%d\n", nums.sum());
}
