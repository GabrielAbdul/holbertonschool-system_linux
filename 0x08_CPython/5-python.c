#include <Python.h>

/**
 * print_python_int - prints Python integers
 * @p: PyObject int
 */
void print_python_int(PyObject *p)
{
	digit *num;
	Py_ssize_t size, i;
	unsigned long integer = 0;

	if (!p || !PyLong_Check(p))
	{
		printf("Invalid Int Object\n");
		exit(-1);
	}
	size = ((PyVarObject *)(p))->ob_size;
	num = ((PyLongObject *)(p))->ob_digit;
	/* ensure overflow doesn't occur */
	if (abs(size) > 3 || (abs(size) == 3 && num[2] > 15))
	{
		printf("C unsigned long int overflow\n");
		exit(-1);
	}
	/* Create int integer from string */
	for (i = 0; i < abs(size); i++)
		integer += num[i] * (1L << (i * PyLong_SHIFT));
	if (size < 0)
		putchar('-');
	printf("%lu\n", integer);
}
