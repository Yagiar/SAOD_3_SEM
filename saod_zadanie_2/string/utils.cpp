void string_copy(char* d, const char* s) {
	while (*s != '\0') {
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
}
int len(const char* d)
{
	int count = 0;
	while (*d != '\0')
	{
		d++;
		count++;
	}
	return count;
}
int compare(const char* d, const char* s)
{
	if (len(d) > len(s))
	{
		return len(d) - len(s);
	}
	else
	{
		if (len(d) < len(s))
		{
			return len(s) - len(d);
		}
		else
		{
			return 0;
		}
	}
}