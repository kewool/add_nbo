#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv){
	FILE* f1 = fopen(argv[1], "r");
    FILE* f2 = fopen(argv[2], "r");
    uint32_t* buffer1, buffer2;
    fread(&buffer1, sizeof(uint32_t), 4, f1);
    fread(&buffer2, sizeof(uint32_t), 4, f2);
    fclose(f1);
    fclose(f2);
    printf("1000(0x%x) + 500(0x%x) = 1500(0x%x)\n", __builtin_bswap32(buffer1), __builtin_bswap32(buffer2), __builtin_bswap32(buffer1) + __builtin_bswap32(buffer2));
    return 0;
}
