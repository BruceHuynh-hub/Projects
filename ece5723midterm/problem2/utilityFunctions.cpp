

char and1(char a, char b)
{
	if ((a == '0') || (b == '0')) return '0';
	else if ((a == '1') && (b == '1')) return '1';
	else return 'X';
}

char or1(char a, char b)
{
	if ((a == '1') || (b == '1')) return '1';
	else if ((a == '0') && (b == '0')) return '0';
	else return 'X';
}

char not1(char a)
{
	if (a == '1') return '0';
	else if (a == '0') return '1';
	else return 'X';
}

char tri1(char a, char c)
{
	if (c == '1') return a;
	else return 'Z';
}

char resolve1(char a, char b)
{
	if (a == 'Z' || a == b) return b;
	else if (b == 'Z') return a;
	else return 'X';
}

char xor1(char a, char b)
{
	if ((a == 'X') || (b == 'X') || (a == 'Z') || (b == 'Z')) return 'X';
	else if (a == b) return '0';
	else return '1';
}

void fullAdder(char a, char b, char ci, char & co, char & sum)
{
	char axb, ab, abc;

	axb = xor1(a, b);
	ab = and1(a, b);
	abc = and1(axb, ci);
	co = or1(ab, abc);
	sum = xor1(axb, ci);
}

