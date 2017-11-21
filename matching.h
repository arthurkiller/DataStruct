#ifndef _STDAFX_H
#define _STDAFX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

int matching(char* s, char* module) {
	if (0 == strlen(s) || 0 == strlen(module)) {
		return -1;
	}

	int index = 0, first = 0, m = 0;
	while (1) {
		if (m == (int)(strlen(module))) {
			// succeed
			break;
		}
		if (first == (int)(strlen(s))) {
			// not matching
			first = -1;
			break;
		}
		if (index == (int)(strlen(s))) {
			first = -1;
			break;
		}
		if (s[index] != module[m]) {
			// next index and start pair
			++first;
			index = first;
			m = 0;
		} else {
			++index;
			++m;
		}
	}

	if (first + (int)(strlen(module)) < (int)(strlen(s))) {
		return first;
	}
	return -1;
}
