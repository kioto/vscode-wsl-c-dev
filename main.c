#include <stdio.h>
#include <string.h>
#include <zlib.h>
#include <stdlib.h>

int main(void) {
    printf("Hello from glibc!");

    const char *input = "This is a test string for zlib compression.";
    uLong src_len = (uLong)strlen(input);

    uLong dest_len = compressBound(src_len);
    Bytef *compressed = (Bytef*)malloc(dest_len);
    if (!compressed) { perror("malloc"); return 1; }

    int rc = compress(compressed, &dest_len, (const Bytef*)input, src_len);
    if (rc == Z_OK) {
        printf("zlib OK: %lu -< %lu bytes\n",
        (unsigned long) src_len, (unsigned long)dest_len);
    } else {
        printf("zlib FAILED: rc=%d\n", rc);
    }
    free(compressed);
    return 0;
}