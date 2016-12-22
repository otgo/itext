void print(char *text){
	printf("%s\n", text);
}

void *trim(char *str) {
    char *start, *end;
    for (start = str; *start; start++) {
        if (!isspace((unsigned char)start[0]))
            break;
    };
    for (end = start + strlen(start); end > start + 1; end--) {
        if (!isspace((unsigned char)end[-1])) {
					break;
				};
    };
    *end = 0;
    if (start > str) {
        memmove(str, start, (end - start) + 1);
		};
}

// bold formats
void bold(char *text) {
	printf("\033[1m%s\033[0m\n", text);
}

void bold_striked(char *text) {
	printf("\033[1m%s\033[0m\n", text);
}

void bold_inderlined(char *text) {
	printf("\033[1m%s\033[0m\n", text);
}

// italics formats
void italics(char *text) {
	printf("\033[3m%s\033[0m\n", text);
}

void italics_bold(char *text) {
	printf("\033[3;1m%s\033[0m\n", text);
}

void italics_striked(char *text) {
	printf("\033[3;9m%s\033[0m\n", text);
}

void italics_underlined(char *text) {
	printf("\033[3;4m%s\033[0m\n", text);
}

// 3 formats
void italics_bold_striked(char *text) {
	printf("\033[3;9;1m%s\033[0m\n", text);
}

void italics_bold_underlined(char *text) {
	printf("\033[3;4;1m%s\033[0m\n", text);
}

// single
void underlined(char *text) {
	printf("\033[4m%s\033[0m\n", text);
}

void underlined_stricked(char *text) {
	printf("\033[4;9m%s\033[0m\n", text);
}

void highlight(char *text) {
	printf("\033[7m%s\033[0m\n", text);
}

void highlight_striked(char *text) {
	printf("\033[7;9m%s\033[0m\n", text);
}

void striked(char *text) {
	printf("\033[9m%s\033[0m\n", text);
}

char *replace(char *orig, char *rep, char *with) {
    char *result, *ins, *tmp;
    int len_rep, len_with, len_front, count;
    if (!orig && !rep)
        return NULL;
    len_rep = strlen(rep);
    if (len_rep == 0)
        return NULL;
    if (!with)
        with = "";
    len_with = strlen(with);
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) {
        ins = tmp + len_rep;
    }
    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);
    if (!result)
        return NULL;
    while (count--) {
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
		free(result); free(tmp);
}

void *__circles(char *text) {
	char *new = text, *final;
	new = replace(new, "a", "ⓐ "); new = replace(new, "o", "ⓞ ");
	new = replace(new, "b", "ⓑ "); new = replace(new, "p", "ⓟ ");
	new = replace(new, "c", "ⓒ "); new = replace(new, "q", "ⓠ ");
	new = replace(new, "d", "ⓓ "); new = replace(new, "r", "ⓡ ");
	new = replace(new, "e", "ⓔ "); new = replace(new, "s", "ⓢ ");
	new = replace(new, "f", "ⓕ "); new = replace(new, "t", "ⓣ ");
	new = replace(new, "g", "ⓖ "); new = replace(new, "u", "ⓤ ");
	new = replace(new, "h", "ⓗ "); new = replace(new, "v", "ⓥ ");
	new = replace(new, "i", "ⓘ "); new = replace(new, "w", "ⓦ ");
	new = replace(new, "j", "ⓙ "); new = replace(new, "x", "ⓧ ");
	new = replace(new, "k", "ⓚ "); new = replace(new, "y", "ⓨ ");
	new = replace(new, "l", "ⓛ "); new = replace(new, "z", "ⓩ ");
	new = replace(new, "m", "ⓜ ");
	new = replace(new, "n", "ⓝ ");
	final = trim(new);
	return final;
}

void circles(char *text) {
	print(__circles(text));
}
