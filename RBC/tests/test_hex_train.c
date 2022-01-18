//
// Created by gregoire on 10/01/2022.
//

#include <assert.h>
#include <stdio.h>


int conv_ascii_hex_to_int(const char *hex) {
    int res = 0;
    res += (hex[0] - 48) * 16 * 16;
    if (hex[1] >= 65) {
        res += (hex[1] - 55) * 16;
    } else {
        res += (hex[1] - 48) * 16;
    }
    if (hex[2] >= 65) {
        res += hex[2] - 55;
    } else {
        res += hex[2] - 48;
    }
    return res;
}

int main() {
    int bal1 = conv_ascii_hex_to_int("3F2");
    int bal2 = conv_ascii_hex_to_int("3D2");
    int bal3 = conv_ascii_hex_to_int("3CA");
    printf("%d\n",bal1);
    printf("%d\n",bal2);
    printf("%d\n",bal3);
    assert(bal1 == 1010);


    return 0;
}