#include <iostream>
#include <cstring>
using namespace std;

char* intalMultiply(char* intal1, char* intal2) {
    int len1 = strlen(intal1);
    int len2 = strlen(intal2);

    // Initialize variables for the product, carry, and index
    int max_len = len1 + len2;
    int product[max_len];
    memset(product, 0, sizeof(product));
    int carry = 0;
    int index = 0;

    // Multiply the INTALs from right to left using elementary multiplication
    for (int i = len1 - 1; i >= 0; i--) {
        carry = 0;
        int digit1 = intal1[i] - '0';
        index = len2 - 1;
        for (int j = index; j >= 0; j--) {
            int digit2 = intal2[j] - '0';
            int digit_product = digit1 * digit2 + carry + product[index + i + 1];
            carry = digit_product / 10;
            product[index + i + 1] = digit_product % 10;
            index--;
        }
        product[index + i + 1] = carry;
    }

    // Create a character array to store the result
    char* result = new char[max_len + 1];
    index = 0;
    for (int i = 0; i < max_len; i++) {
        if (product[i] != 0) {
            index = i;
            break;
        }
    }
    for (int i = index; i < max_len; i++) {
        result[i - index] = product[i] + '0';
    }
    result[max_len - index] = '\0';

    return result;
}

int main() {
    char intal1[] = "123456789";
    char intal2[] = "987654321";
    char* product = intalMultiply(intal1, intal2);
    cout << "Product of " << intal1 << " and " << intal2 << " is " << product << endl;
    delete[] product;
    return 0;
}
