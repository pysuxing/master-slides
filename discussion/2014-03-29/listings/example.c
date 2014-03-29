int i;
int *p = &i;
int *q = NULL;
int *s;
if (*p)
    s = p;
else
    s = q;
*s = i + 1;
