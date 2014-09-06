#include "static_header.h"


static int units = 0;

void add_unit() {
    units++;
}
int get_units() {
    return units;
}
